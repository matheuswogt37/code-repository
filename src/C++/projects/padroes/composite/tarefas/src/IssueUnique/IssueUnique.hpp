#ifndef IssueUnique_hpp
#define IssueUnique_hpp
#include <iostream>
#include "../Issue/Issue.hpp"
#include "../Utils/DataStruct/DataStruct.hpp"

class IssueUnique : public Issue
{
private:
    std::string tittle;
    std::string description;
    DataStruct data;

public:
    IssueUnique(std::string t, std::string d, DataStruct dt);
    void list(std::string initPrint);
};

#endif