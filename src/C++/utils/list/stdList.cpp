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

int main() {
    std::list<Num*> objectList{new Num(1), new Num(7), new Num(3), new Num(91), };
    std::list<int> intList{1, 5, 2, 8};

    std::cout << "object list" << std::endl;
    for (auto i : objectList) {
        std::cout << i->getNum() << ' ';
    }
    std::cout << std::endl << std::endl;

    std::cout << "int list" << std::endl;
    for (auto i : intList) {
        std::cout << i << ' ';
    }
    std::cout << std::endl << std::endl;

    return 0;
}