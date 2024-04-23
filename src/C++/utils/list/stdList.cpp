// Online C++ compiler to run C++ program online
#include <iostream>
#include <list>

class Num 
{
    private:
        int num;
    public:
        Num(int n) {
            this->num = n;
        }
        int getNum() {
            return this->num;
        }
};

void printNumList(std::list<Num*> list) {
    std::cout << "object list" << "\n";
    for (auto i : list) {
        std::cout << i->getNum() << ' ';
    }
    std::cout << "\n\n";
}

void printIntLis(std::list<int> list) {
    std::cout << "int list" << "\n";
    for (auto i : list) {
        std::cout << i << ' ';
    }
    std::cout << "\n\n";
}

int main() {
    std::list<Num*> objectList{new Num(1), new Num(7), new Num(3), new Num(91)};
    std::list<Num*>::iterator objectIt;
    std::list<int> intList{1, 5, 2, 8};
    std::list<int>::iterator intIt;


    std::cout << "object list" << "\n";
    for (auto i : objectList) {
        std::cout << i->getNum() << ' ';
    }
    std::cout << "\n\n";

    std::cout << "int list" << "\n";
    for (auto i : intList) {
        std::cout << i << ' ';
    }
    std::cout << "\n\n";

    // insert
    objectIt = objectList.end();
    objectList.insert(objectIt, new Num(70));

    intList.insert(intList.begin(), 45);

    std::cout << "Inserts" << std::endl;


    return 0;
}