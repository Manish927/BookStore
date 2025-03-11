#ifndef BOOKSTOREAPP_H
#define BOOKSTOREAPP_H
#include "service/BookStoreService.h"


class BookStoreApp {
    BookStoreService book_store_service_ = BookStoreService();
public:
    BookStoreApp() noexcept{
    }
    void init() ;
};

#endif //BOOKSTOREAPP_H
