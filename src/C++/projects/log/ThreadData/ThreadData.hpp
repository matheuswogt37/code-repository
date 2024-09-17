#ifndef ThreadData_hpp
#define ThreadData_hpp

#include <string>

class ThreadData {
    private:
        std::string str;
        int id;
        int status200;
        int sumHour[24];

    public:
        ThreadData(int id);
        ~ThreadData();
        void addStatus200();
        int getStatus200();
        void addSumHour(int index);
        void getSumHour(int *rValue);
        void setId(int id);
        int getId();
        void setStr(std::string st);
        std::string getStr();
};

#endif