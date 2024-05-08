#ifndef CheckNegative_hpp
#define CheckNegative_hpp
#include "../../BaseVerify/BaseVerify.hpp"
#include "../../Client/Client.hpp"
#include "../../Bank/Bank.hpp"

class CheckNegative : public BaseVerify
{
public:
    CheckNegative(Handler *n);
    CheckNegative();
    ~CheckNegative();
    void releaseCredits(Client *c, Bank *b, float creds);
};

#endif