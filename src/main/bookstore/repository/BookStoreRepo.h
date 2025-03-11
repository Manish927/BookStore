#ifndef BOOKSTOREREPO_H
#define BOOKSTOREREPO_H
#include <iostream>

#include "PersistenceBaseRepo.h"
#include "../entity/book.h"

class BookStoreRepo : public PersistenceBaseRepo{

    public:
    explicit BookStoreRepo(const std::string& path);
    ~BookStoreRepo() override ;
    std::string fetchBook(std::string& book_id) override;
    std::string storeBook(Book& obj) ;
    bool updateBook(std::string& book_id, std::unordered_map<std::string,std::string>& fields);
    bool deleteBook(std::string& book_id);
    void displayBooks() override;
};



#endif //BOOKSTOREREPO_H
