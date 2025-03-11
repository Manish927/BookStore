
#include "BookReadRepo.h"

#include <iostream>

std::string BookReadRepo::fetchBook(std::string& book_id) {
    return book_id;
}

void BookReadRepo::displayBooks() {}

BookReadRepo::BookReadRepo(const std::string& path) : PersistenceBaseRepo(path){
    std::cout << "BookReadRepo::BookReadRepo" << std::endl;
}

BookReadRepo::~BookReadRepo() {
    std::cout << "BookReadRepo::~BookReadRepo" << std::endl;
}

