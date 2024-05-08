#ifndef CheckPatrimony_hpp
#define CheckPatrimony_hpp
#include "../../BaseVerify/BaseVerify.hpp"
#include "../../Client/Client.hpp"
#include "../../Bank/Bank.hpp"

class CheckPatrimony : public BaseVerify
{
public:
    CheckPatrimony(Handler *n);
    CheckPatrimony();
    ~CheckPatrimony();
    void releaseCredits(Client *c, Bank *b, float creds);
};

#endif