#ifndef BOOKSTORESERVICE_H
#define BOOKSTORESERVICE_H

#include <memory>
#include "../repository/BookStoreRepo.h"


class BookStoreService {
    std::unique_ptr<BookStoreRepo> book_store_repo_;

public:
     BookStoreService(){
         std::string path("tcp://127.0.0.1:6379");

         book_store_repo_ = std::make_unique<BookStoreRepo>(path);


     }

    ~BookStoreService() = default;

    // CRUD operation
    void create_book() ;
    void read_book() ;
    void update_book() ;
    void delete_book() ;
    void display_book() ;
};



#endif //BOOKSTORESERVICE_H
