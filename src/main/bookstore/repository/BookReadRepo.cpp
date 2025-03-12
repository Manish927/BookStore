#include "BookReadRepo.h"
#include <iostream>

std::vector<std::string> BookReadRepo::fetchBook(std::string& book_id) {
    return {};
}

void BookReadRepo::displayBooks() {}

BookReadRepo::BookReadRepo(const std::string& path) : PersistenceBaseRepo(path){
    std::cout << "BookReadRepo::BookReadRepo" << std::endl;
}

BookReadRepo::BookReadRepo(const sw::redis::ConnectionOptions& opts, const sw::redis::ConnectionPoolOptions& pool_opts)
     :PersistenceBaseRepo(opts, pool_opts) {
    std::cout << "BookrStoepoRe::BookReadRepo created: " <<std::endl;
}


BookReadRepo::~BookReadRepo() {
    std::cout << "BookReadRepo::~BookReadRepo" << std::endl;
}


