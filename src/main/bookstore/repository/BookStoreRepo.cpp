//
// Created by manish on 10/3/25.
//

#include "BookStoreRepo.h"

#include <iostream>
#include <regex>
#include <sstream>

std::string BookStoreRepo::fetchBook(std::string& book_id) {
    std::cout << "BookStoreRepo::fetchBook " << book_id << std::endl;
    //std::vector<sw::redis::OptionalString> vals;
    sw::redis::OptionalString val = conn.hget("book_hash" ,book_id);
    std::cout << "BookStoreRepo::fetchBook " << val.value_or("null") << std::endl;
    return val.value_or("null");
}

void BookStoreRepo::displayBooks() {
    std::unordered_map<std::string, std::string> books;
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

bool BookStoreRepo::updateBook(std::string& book_id, std::unordered_map<std::string,std::string>& fields) {
    std::cout << "BookStoreRepo::updateBook " << book_id << std::endl;
    std::vector<std::string> to_update;

    if (std::string val = fetchBook(book_id); val != "null") {
        std::string delimiter(":");
        std::size_t pos = 0;
        std::string token;
        while ((pos = val.find(delimiter)) != std::string::npos) {
            token = val.substr(0, pos);
            to_update.push_back(token);
            val.erase(0, pos + delimiter.length());
        }
        to_update.push_back(val);
        Book obj;
        obj.set_title(to_update[0]).set_author(to_update[1]).set_publisher(to_update[2])
        .set_genre(to_update[3]).set_rating(std::stof(to_update[4])).set_page(std::stoi(to_update[5])).set_price(std::stof(to_update[6]));

        for ( auto& [key, val] : fields) {
            if (key == "title") { obj.set_title(val); }
            if (key == "author") { obj.set_author(val); }
            if (key == "publisher") { obj.set_publisher(val); }
            if (key == "genre") { obj.set_genre(val); }
            if (key == "rating") { obj.set_rating(std::stof(val)); }
            if (key == "page") { obj.set_page(std::stoi(val)); }
            if (key == "price") { obj.set_isbn(val); }
        }
        deleteBook(book_id);
        std::cout << "Updated: " << storeBook(obj);

    }

    return true;
}
bool BookStoreRepo::deleteBook(std::string& book_id) {
    std::cout << "BookStoreRepo::deleteBook " << book_id << std::endl;
    conn.hdel("book_hash" ,book_id);
    return true;
}

BookStoreRepo::BookStoreRepo(const std::string& path):PersistenceBaseRepo(path) {
    std::cout << "BookStoreRepo::BookStoreRepo created" << std::endl;
}

BookStoreRepo::~BookStoreRepo() {
    std::cout << "BookStoreRepo::~BookStoreRepo" << std::endl;
}
