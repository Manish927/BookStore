#ifndef BOOKREADREPO_H
#define BOOKREADREPO_H
#include "PersistenceBaseRepo.h"

class BookReadRepo final : public PersistenceBaseRepo{
public:
    explicit BookReadRepo(const std::string&);
    explicit BookReadRepo(const sw::redis::ConnectionOptions&, const sw::redis::ConnectionPoolOptions& );
    ~BookReadRepo() override;
    std::vector<std::string> fetchBook(std::string& book_id) override;
    void displayBooks() override;
};

#endif //BOOKREADREPO_H
