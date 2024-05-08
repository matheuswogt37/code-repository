#ifndef DispCredits_hpp
#define DispCredits_hpp
#include "../../BaseVerify/BaseVerify.hpp"
#include "../../Client/Client.hpp"
#include "../../Bank/Bank.hpp"

class DispCredits : public BaseVerify
{
public:
    DispCredits(Handler *n);
    DispCredits();
    ~DispCredits();
    void releaseCredits(Client *c, Bank *b, float creds);
};

#endif