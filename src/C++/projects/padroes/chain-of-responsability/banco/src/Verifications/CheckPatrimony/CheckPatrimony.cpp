#include "CheckPatrimony.hpp"

CheckPatrimony::CheckPatrimony(Handler *n) : BaseVerify(n){};

CheckPatrimony::CheckPatrimony() : BaseVerify(){};

CheckPatrimony::~CheckPatrimony(){};

void CheckPatrimony::releaseCredits(Client *c, Bank *b, float creds)
{
    if (c->getPatrimony() < creds)
    {
        std::cout << "Não tem garantias/patrimonio suficiente! Créditos NEGADOS!!!" << std::endl;
    }
    else
    {
        std::cout << "Garantia/patrimonio suficiente! Verificação concluída" << std::endl;
        BaseVerify::releaseCredits(c, b, creds);
    }
};