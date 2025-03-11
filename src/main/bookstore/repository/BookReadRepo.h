
#ifndef BOOKREADREPO_H
#define BOOKREADREPO_H
#include "PersistenceBaseRepo.h"

class BookReadRepo final : public PersistenceBaseRepo{
public:
    explicit BookReadRepo(const std::string&);
    ~BookReadRepo() override;
    std::string fetchBook(std::string& book_id) override;
    void displayBooks() override;
};



#endif //BOOKREADREPO_H
