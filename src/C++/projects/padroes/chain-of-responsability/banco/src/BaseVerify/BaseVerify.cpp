#include "BaseVerify.hpp"

BaseVerify::BaseVerify(Handler *n) {
    this->next = n;
}

BaseVerify::BaseVerify() : next(nullptr) {};

Handler *BaseVerify::setNext(Handler *n)
{
    this->next = n;
    return n;
};

void BaseVerify::releaseCredits(Client *c, Bank *b, float creds)
{
    if (this->next)
    {
        this->next->releaseCredits(c, b, creds);
    }
};