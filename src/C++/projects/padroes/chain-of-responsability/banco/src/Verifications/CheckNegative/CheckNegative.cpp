#include "CheckNegative.hpp"

CheckNegative::CheckNegative(Handler *n) : BaseVerify(n){};

CheckNegative::CheckNegative() : BaseVerify(){};

CheckNegative::~CheckNegative(){};

void CheckNegative::releaseCredits(Client *c, Bank *b, float creds)
{
    if (c->getNegative())
    {
        std::cout << "Nome negativado! Créditos NEGADOS" << std::endl;
    }
    else
    {
        std::cout << "Nome positivado! Verificação concluída" << std::endl;
        BaseVerify::releaseCredits(c, b, creds);
    }
};