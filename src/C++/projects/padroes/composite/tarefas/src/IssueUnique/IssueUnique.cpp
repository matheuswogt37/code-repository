#include "IssueUnique.hpp"

IssueUnique::IssueUnique(std::string t, std::string d, DataStruct dt) : Issue()
{
    this->tittle = t;
    this->description = d;
    this->data = dt;
}

void IssueUnique::list(std::string initPrint)
{
    std::cout << initPrint << this->tittle << " - " << this->description << "(" << this->data.day << "/" << this->data.month << "/" << this->data.year << ")\n";
}