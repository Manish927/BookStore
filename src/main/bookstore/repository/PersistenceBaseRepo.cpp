#include "PersistenceBaseRepo.h"

#include <iostream>
#include <bits/ostream.tcc>

PersistenceBaseRepo::PersistenceBaseRepo(const std::string& path): conn(path) {
    conn.ping();
    std::cout << "PersistenceBaseRepo::PersistenceBaseRepo created: " <<conn.ping() << std::endl;
}

PersistenceBaseRepo::~PersistenceBaseRepo() {
    std::cout << "PersistenceBaseRepo::~PersistenceBaseRepo" << std::endl;
}

std::string PersistenceBaseRepo::fetchBook(std::string& book_id) {
    return "";
}

void PersistenceBaseRepo::displayBooks() {}
