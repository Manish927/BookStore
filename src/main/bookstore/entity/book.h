#ifndef BOOK_H
#define BOOK_H
#include <ostream>
#include <string>

class Book {
    std::string title;
    std::string author;
    std::string publisher;
    std::string genre;  //'fiction, 'mystery', science-fiction', 'technical', 'thriller', 'narrative', 'novel'
    std::string isbn;
    float rating;
    int page_num;
    float price;
public:

    Book() = default;
    ~Book() = default;
    Book& set_title(const std::string &title) {this->title = title; return *this;}
    Book& set_author(const std::string &author) {this->author = author; return *this;}
    Book& set_publisher(const std::string &publisher) {this->publisher = publisher; return *this;}
    Book& set_genre(const std::string &genre) {this->genre = genre; return *this;}
    Book& set_isbn(const std::string &isbn) {this->isbn = isbn; return *this;}
    Book& set_rating(float counter) {this->rating = counter; return *this;}
    Book& set_page(int page_num) {this->page_num = page_num; return *this;}
    Book& set_price(float price) {this->price = price; return *this;}
    std::string& get_isbn() { return this->isbn; }
    friend std::ostream & operator<<(std::ostream &os, const Book &obj) {
        return os << obj.title << ":" << obj.author << ":" << obj.publisher<< ":" << obj.genre << ":" << obj.rating
               << ":" << obj.page_num << ":" << obj.price;
    }
};

// store the keys in redis in this way
// convention: entity:id:attribute
// Key: "user:777:name"
// Value: "Manish Srivastava"


#endif //BOOK_H
