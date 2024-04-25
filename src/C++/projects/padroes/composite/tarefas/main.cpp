#include <memory>
#include "src/Issue/Issue.hpp"
#include "src/IssueUnique/IssueUnique.hpp"
#include "src/IssueCompose/IssueCompose.hpp"
#include "src/Utils/DataStruct/DataStruct.hpp"

int main()
{
    auto issue1 = new IssueCompose("Motor");
    DataStruct dataIssue2 = {.day = 30, .month = 04, .year = 2004 };
    auto issue2 = new IssueUnique("Parafuso", "16 Parafusos 3x4", dataIssue2);
    auto issue3 = new IssueCompose("Carro");

    issue1->add(issue2);
    issue3->add(issue1);
    
    issue3->list("");

    delete issue1;
    delete issue2;
    delete issue3;
    return 0;
}