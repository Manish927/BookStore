#include "BookStoreService.h"

#include "../entity/book.h"

void BookStoreService::display_book() {
    book_store_repo_->displayBooks();
}

void BookStoreService::read_book()  {
    std::string str = "isbn-1234";
    book_store_repo_->fetchBook(str);
}

void BookStoreService::create_book()  {
    Book book;
    book.set_title("Title1").set_author("Author1").set_publisher("Publisher1")
    .set_genre("Mystery").set_rating(4.5).set_page(300).set_price(99.90).set_isbn("isbn-1234");
    std::string res = book_store_repo_->storeBook(book);
    std::cout << res << std::endl;
}

void BookStoreService::update_book()  {
    std::string str = "isbn-1234";
    std::unordered_map<std::string, std::string> fields = {{"page", "350"}};
    book_store_repo_->updateBook(str, fields);
}
void BookStoreService::delete_book()  {
    std::string str = "isbn-1234";

    book_store_repo_->deleteBook(str);
}
