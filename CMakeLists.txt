cmake_minimum_required(VERSION 3.10)
project(BookStore)

set(CMAKE_CXX_STANDARD 20)

add_executable(BookStore main.cpp
        src/main/bookstore/repository/BookReadRepo.cpp
        src/main/bookstore/service/BookStoreService.cpp
        src/main/bookstore/repository/BookStoreRepo.cpp
        src/main/bookstore/BookStoreApp.cpp
        src/main/bookstore/repository/PersistenceBaseRepo.cpp)

target_link_libraries(BookStore hiredis redis++)
