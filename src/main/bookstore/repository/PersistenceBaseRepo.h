#ifndef PersistenceBaseRepo_H
#define PersistenceBaseRepo_H
#include <string>
#include <sw/redis++/redis++.h>

class PersistenceBaseRepo {
protected:
    sw::redis::Redis conn;
public:
    explicit PersistenceBaseRepo(const sw::redis::ConnectionOptions& opts, const sw::redis::ConnectionPoolOptions& pool_opts);
    explicit PersistenceBaseRepo(const std::string&);
    virtual ~PersistenceBaseRepo() = 0;
    virtual std::vector<std::string> fetchBook(std::string& book_id);
    virtual void displayBooks();
};

#endif //PeristenceBaseRepo_H
