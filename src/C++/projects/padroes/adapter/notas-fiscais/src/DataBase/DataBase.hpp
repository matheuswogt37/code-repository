#ifndef DataBase_hpp
#define DataBase_hpp
#include <iostream>
#include "../XML/XML.hpp"

class DataBase {
    public:
        DataBase();
        ~DataBase();
        void insert(XML *data);
};

#endif