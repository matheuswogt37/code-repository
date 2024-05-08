#ifndef BaseVerify_hpp
#define BaseVerify_hpp
#include "../Handler/Handler.hpp"
#include "../Client/Client.hpp"
#include "../Bank/Bank.hpp"

class BaseVerify : public Handler
{
private:
    Handler *next;

public:
    BaseVerify(Handler *n);
    BaseVerify();
    Handler *setNext(Handler *n);
    void releaseCredits(Client *c, Bank *b, float creds);
};

#endif