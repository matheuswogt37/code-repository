#ifndef IssueCompose_hpp
#define IssueCompose_hpp
#include <list>
#include <bits/stdc++.h>
#include <string.h>
#include "../Issue/Issue.hpp"

class IssueCompose : public Issue
{
private:
    std::string title;
    std::list<Issue *> tasks;

public:
    IssueCompose(std::string t);
    void add(Issue *task);
    void remove(Issue *task);
    std::list<Issue *> getChildren();
    void list(std::string initPrint);
    std::string getTitle() {
        return this->title;
    };
};

#endif