#include "BookStoreService.h"

#include "../entity/book.h"

void BookStoreService::display_book() {
    book_store_repo_->displayBooks();
}

void BookStoreService::read_book()  {
    std::string str = "book-isbn:1";
    book_store_repo_->fetchBook(str);
}

void BookStoreService::create_book() {
    book_store_repo_->store_book("book-isbn:1", {{"title", "Introduction to Algorithms"},
        {"author", "Cormen, Thomas"},{"genre", "computer_science"},
        {"page", "232"},{"rating", "1.1"}});
}

void BookStoreService::update_book()  {
    std::string str = "book-isbn:1";
    std::unordered_map<std::string, std::string> fields = {{"page", "350"}};
    book_store_repo_->updateBook(str, fields);
}
void BookStoreService::delete_book()  {
    std::string str = "book-isbn:1";

    book_store_repo_->deleteBook(str);
}

