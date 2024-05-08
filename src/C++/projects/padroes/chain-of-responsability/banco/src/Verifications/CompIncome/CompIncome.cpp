#include "CompIncome.hpp"

CompIncome::CompIncome(Handler *n) : BaseVerify(n){};

CompIncome::CompIncome() : BaseVerify(){};

CompIncome::~CompIncome(){};

void CompIncome::releaseCredits(Client *c, Bank *b, float creds)
{
    if (c->getIncome() < (creds * 0.25))
    {
        std::cout << "Renda abaixo de 25% do requisitado! Créditos NEGADOS" << std::endl;
    }
    else
    {
        std::cout << "Renda suficiente! Verificação concluída" << std::endl;
        BaseVerify::releaseCredits(c, b, creds);
    }
};