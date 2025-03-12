#ifndef BOOKSTORESERVICE_H
#define BOOKSTORESERVICE_H

#include <memory>
#include "../repository/BookStoreRepo.h"


class BookStoreService {
    std::unique_ptr<BookStoreRepo> book_store_repo_;

public:
     BookStoreService(){
         std::string path("tcp://127.0.0.1:6379");
         sw::redis::ConnectionOptions opts;
         sw::redis::ConnectionPoolOptions pool_opts;
         opts.host = "127.0.0.1";
         opts.port = 6379;
         opts.socket_timeout = std::chrono::milliseconds(50);
         pool_opts.size = 3;
         pool_opts.wait_timeout = std::chrono::milliseconds(50);
         try {
             book_store_repo_ = std::make_unique<BookStoreRepo>(opts, pool_opts);
         } catch (const std::exception& e) {
             std::cout << e.what() << std::endl;
         }
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
