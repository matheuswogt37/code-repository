#include "DispCredits.hpp"

DispCredits::DispCredits(Handler *n) : BaseVerify(n){};

DispCredits::DispCredits() : BaseVerify(){};

DispCredits::~DispCredits(){};

void DispCredits::releaseCredits(Client *c, Bank *b, float creds)
{
    if (c->getNegative())
    {
        std::cout << "Créditos insuficientes, favor contatar a central. Créditos NEGADOS" << std::endl;
    }
    else
    {
        std::cout << "Creditos suficientes. Verificação concluída" << std::endl;
        BaseVerify::releaseCredits(c, b, creds);
    }
};