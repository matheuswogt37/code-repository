#ifndef CompIncome_hpp
#define CompIncome_hpp
#include "../../BaseVerify/BaseVerify.hpp"
#include "../../Client/Client.hpp"
#include "../../Bank/Bank.hpp"

class CompIncome : public BaseVerify
{
public:
    CompIncome(Handler *n);
    CompIncome();
    ~CompIncome();
    void releaseCredits(Client *c, Bank *b, float creds);
};

#endif