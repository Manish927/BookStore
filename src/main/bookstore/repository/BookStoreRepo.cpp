#include "BookStoreRepo.h"

#include <iostream>
#include <regex>
#include <sstream>

std::vector<std::string> BookStoreRepo::fetchBook(std::string& book_id) {
    std::cout << "BookStoreRepo::fetchBook " << book_id << std::endl;
    std::vector<std::string> books = {};

    try {

        auto pipe = conn.pipeline(false);
        auto replies = pipe.hgetall(book_id).exec();
        replies.get(0, std::back_inserter(books));

        for (auto& value : books) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return books;
}

void BookStoreRepo::displayBooks() {
    std::unordered_map<std::string, std::string> books;
    std::vector<std::string> keys;
    try {
        auto pipe = conn.pipeline(false);
        auto replies = pipe.keys("book-isbn*").exec();
        replies.get(0, std::back_inserter(keys));
        for (auto& value : keys) {
            std::vector<std::string>  temp = fetchBook(value);
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    conn.hgetall("book_hash", std::inserter(books, books.begin()));

    std::for_each(books.begin(), books.end(),
        [](const std::pair<std::string, std::string>& book){ std::cout << book.first << " " << book.second << std::endl; });
}

std::string BookStoreRepo::storeBook(Book& obj) {
    std::cout << "BookStoreRepo::storeBook " << obj << std::endl;
    std::stringstream ss;

    char buffer[512] = {0};
    std::sprintf(buffer, "%s", obj.get_isbn().c_str());
    ss << obj;
    std::string book_dtl = ss.str();
    conn.hset("book_hash", std::make_pair(buffer, book_dtl));
    std::cout << book_dtl << std::endl;
    return buffer;
}

void BookStoreRepo::updateBook(std::string& book_id, std::unordered_map<std::string,std::string>& fields) {
    std::cout << "BookStoreRepo::updateBook " << book_id << std::endl;
    std::unordered_map<std::string, std::string> updated_books = {};

    std::unordered_map<std::string, std::string> values = {};
    try {
        auto tx = conn.transaction();
        auto redis = tx.redis();

        while (true) {
            redis.watch(book_id);
            redis.hgetall(book_id, std::inserter(values, values.begin()));

            if (values.size() > 0) {
                updated_books.insert(fields.begin(), fields.end());
                updated_books.insert(values.begin(), values.end());
                auto replies = tx.hset(book_id, updated_books.begin(), updated_books.end()).exec();
            }
            else {
                std::cout << "No updated books" << std::endl;
            }
            break;
        }

    } catch (const sw::redis::WatchError &err) {
        std::cout << err.what() << std::endl;
        std::cout << "Probably keys has been modified outside " << book_id << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}


// delete entire book details
void BookStoreRepo::deleteBook(std::string& isbn) {
    std::cout << "BookStoreRepo::deleteBook " << isbn << std::endl;
    try {
        auto pipe = conn.pipeline(false);
        pipe.del(isbn).exec();
        pipe.discard();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void BookStoreRepo::store_book(const std::string& isbn, const std::unordered_map<std::string, std::string>& data) {
    std::cout << isbn << std::endl;

    try {
        auto pipe = conn.pipeline(false);
        pipe.hset(isbn, data.begin(), data.end()).exec();
        pipe.discard();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

BookStoreRepo::BookStoreRepo(const std::string& path):PersistenceBaseRepo(path) {
    std::cout << "BookStoreRepo::BookStoreRepo created" << std::endl;
}

BookStoreRepo::BookStoreRepo(const sw::redis::ConnectionOptions& opts, const sw::redis::ConnectionPoolOptions& pool_opts)
     :PersistenceBaseRepo(opts, pool_opts) {
    std::cout << "BookStoreRepo::BookStoreRepo created: " <<std::endl;
}

BookStoreRepo::~BookStoreRepo() {
    std::cout << "BookStoreRepo::~BookStoreRepo" << std::endl;
}
