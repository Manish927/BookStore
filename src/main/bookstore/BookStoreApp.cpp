#include "BookStoreApp.h"

void BookStoreApp::init() {
    book_store_service_.create_book();
    book_store_service_.display_book();
    book_store_service_.read_book();
    book_store_service_.update_book();
    book_store_service_.display_book();
    book_store_service_.delete_book();
}
