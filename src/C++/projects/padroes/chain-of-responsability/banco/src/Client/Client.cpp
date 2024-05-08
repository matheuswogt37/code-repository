#include "Client.hpp"

Client::Client(std::string na, float i, float p, bool ne) {
    this->name = na;
    this->income = i;
    this->patrimony = p;
    this->negative = ne;
};

Client::~Client() {};

std::string Client::getName() {
    return this->name;
};

float Client::getIncome() {
    return this->income;
};

float Client::getPatrimony() {
    return this->patrimony;
};

bool Client::getNegative() {
    return this->negative;
}