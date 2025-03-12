#ifndef BOOKSTOREREPO_H
#define BOOKSTOREREPO_H
#include <iostream>

#include "PersistenceBaseRepo.h"
#include "../entity/book.h"

class BookStoreRepo final : public PersistenceBaseRepo{

    public:
    explicit BookStoreRepo(const std::string& path);
    explicit BookStoreRepo(const sw::redis::ConnectionOptions& opts, const sw::redis::ConnectionPoolOptions& pool_opts);
    ~BookStoreRepo() override ;
    std::vector<std::string> fetchBook(std::string& book_id) override;
    std::string storeBook(Book& obj) ;
    void updateBook(std::string& book_id, std::unordered_map<std::string,std::string>& fields);
    void deleteBook(std::string& book_id);
    void displayBooks() override;

    void store_book(const std::string& , const std::unordered_map<std::string, std::string >&);
};

#endif //BOOKSTOREREPO_H
