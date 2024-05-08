#ifndef Client_hpp
#define Client_hpp
#include <iostream>
#include <string.h>

class Client {
    private:
        std::string name;
        float income;
        float patrimony;
        bool negative;
    public:
        Client(std::string n, float i, float p, bool ne);
        ~Client();
        std::string getName();
        float getIncome();
        float getPatrimony();
        bool getNegative();
};



#endif