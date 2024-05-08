#include "Bank.hpp"

Bank::Bank(float c)
{
    this->creds = c;
};

Bank::~Bank(){};

float Bank::getCreds()
{
    return this->creds;
}