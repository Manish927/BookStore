#include "PersistenceBaseRepo.h"

#include <iostream>

PersistenceBaseRepo::PersistenceBaseRepo(const std::string& path):conn(path){
    std::cout << "PersistenceBaseRepo::PersistenceBaseRepo created: " <<conn.ping() << std::endl;
}

PersistenceBaseRepo::PersistenceBaseRepo(const sw::redis::ConnectionOptions& opts, const sw::redis::ConnectionPoolOptions& pool_opts)
     :conn(opts, pool_opts) {
    std::cout << "PersistenceBaseRepo::PersistenceBaseRepo created: " <<conn.ping() << std::endl;
}


PersistenceBaseRepo::~PersistenceBaseRepo() {
    std::cout << "PersistenceBaseRepo::~PersistenceBaseRepo" << std::endl;
}

std::vector<std::string> PersistenceBaseRepo::fetchBook(std::string& book_id) {
    return {};
}

void PersistenceBaseRepo::displayBooks() {}
