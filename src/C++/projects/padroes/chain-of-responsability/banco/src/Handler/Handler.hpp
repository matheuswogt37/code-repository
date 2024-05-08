#ifndef Handler_hpp
#define Handler_hpp
#include "../Client/Client.hpp"
#include "../Bank/Bank.hpp"

class Handler {
    public:
        Handler(Handler *n) {};
        Handler() {};
        virtual ~Handler() {};
        virtual Handler *setNext(Handler *n) = 0;
        virtual void releaseCredits(Client *c, Bank *b, float creds) = 0;
};

#endif