// Online C++ compiler to run C++ program online
#include <iostream>
#include <list>
#include <bits/stdc++.h>

class Num
{
private:
    int num;

public:
    Num(int n)
    {
        this->num = n;
    }
    int getNum()
    {
        return this->num;
    }
};

void printNumList(std::list<Num *> list)
{
    std::cout << "object list"
              << "\n";
    for (auto i : list)
    {
        std::cout << i->getNum() << ' ';
    }
    std::cout << "\n\n";
}

void printIntLis(std::list<int> list)
{
    std::cout << "int list"
              << "\n";
    for (auto i : list)
    {
        std::cout << i << ' ';
    }
    std::cout << "\n\n";
}

void removeFromNumList(std::list<Num *> *list, Num *rem) {
    std::list<Num *>::iterator objectIt;
    objectIt = std::find(list->begin(), list->end(), rem);
    objectIt = list->erase(objectIt);
}

void removeFromIntList(std::list<int> *list, int num) {
    std::list<int>::iterator intIt;
    intIt = std::find(list->begin(), list->end(), num);
    intIt = list->erase(intIt);
}

void forEachNumList(std::list<Num *> list)
{
    std::list<Num *>::iterator it;
    for (it = list.begin(); it != list.end(); it++)
    {
        std::cout << (*it)->getNum() << " ";
    }
    std::cout << std::endl;
}

void forEachIntList(std::list<int> list)
{
    std::list<int>::iterator it;
    for (it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::list<Num *> objectList{new Num(1), new Num(7), new Num(3), new Num(91)};
    std::list<Num *>::iterator objectIt;
    std::list<int> intList{1, 5, 2, 8};
    std::list<int>::iterator intIt;

    printNumList(objectList);
    printIntLis(intList);

    // insert
    objectIt = objectList.end();
    Num *num = new Num(70);
    objectList.insert(objectIt, num);

    intList.insert(intList.begin(), 45);

    std::cout << "Inserts" << std::endl;
    printNumList(objectList);
    printIntLis(intList);

    // remove
    // remove last item
    // objectIt = objectList.end();
    // objectIt--;
    // objectIt = objectList.erase(objectIt);

    // intIt = intList.end();
    // intIt--;
    // intIt = intList.erase(intIt);

    // remove searched item
    // num = 70 | line 56

    std::cout << "Remove" << std::endl;
    removeFromNumList(&objectList, num);
    removeFromIntList(&intList, 45);
    printNumList(objectList);
    printIntLis(intList);

    std::cout << "For each" << std::endl;
    forEachNumList(objectList);
    forEachIntList(intList);

    return 0;
}