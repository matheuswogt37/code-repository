#include "IssueCompose.hpp"

IssueCompose::IssueCompose(std::string t) : Issue()
{
    this->title = t;
}

void IssueCompose::add(Issue *issue)
{
    this->tasks.insert(this->tasks.end(), issue);
}

/*
void add(Issue *task);
        void remove(Issue *task);
        std::list <Issue*> getChildren();
        void list(std::string initPrint);
*/

void IssueCompose::remove(Issue *task)
{
    std::list<Issue *>::iterator taskIt;
    taskIt = std::find(this->tasks.begin(), this->tasks.end(), task);
}

std::list<Issue *> IssueCompose::getChildren()
{
    return this->tasks;
}

void IssueCompose::list(std::string initPrint)
{
    std::list<Issue *>::iterator it;
    std::string newInitPrint = "|  " + initPrint;

    std::cout << initPrint << this->title << std::endl;
    for (it = this->tasks.begin(); it != this->tasks.end(); it++)
    {
        (*it)->list(newInitPrint);
    }
}