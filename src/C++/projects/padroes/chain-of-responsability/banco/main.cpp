#include "src/Bank/Bank.hpp"
#include "src/Client/Client.hpp"
#include "src/BaseVerify/BaseVerify.hpp"
#include "src/Verifications/CheckNegative/CheckNegative.hpp"
#include "src/Verifications/CheckPatrimony/CheckPatrimony.hpp"
#include "src/Verifications/CompIncome/CompIncome.hpp"
#include "src/Verifications/DispCredits/DispCredits.hpp"

int main() {
    Bank *santander = new Bank(50000);
    Client *c1 = new Client("Jose Amianto da Silva", 5000, 100000, false);

    BaseVerify *chainVerify;
    chainVerify = new CheckNegative(new CheckPatrimony(new CompIncome(new DispCredits())));
    chainVerify->releaseCredits(c1, santander, 1000);

    // CheckNegative *chkNeg = new CheckNegative();
    // CheckPatrimony *chkPat = new CheckPatrimony();
    // CompIncome *compIn = new CompIncome();
    // DispCredits *dispCr = new DispCredits();
    // chkNeg->setNext(chkPat)->setNext(compIn)->setNext(dispCr);
    // chkNeg->releaseCredits(c1, santander, 1000);



    std::cout << "Finalizando requisições" << std::endl;

    return 0;
}