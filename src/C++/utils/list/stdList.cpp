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
    objectIt = std::find(objectList.begin(), objectList.end(), num);
    objectIt = objectList.erase(objectIt);

    intIt = std::find(intList.begin(), intList.end(), 45);
    intIt = intList.erase(intIt);


    std::cout << "Remove" << std::endl;
    printNumList(objectList);
    printIntLis(intList);

    return 0;
}