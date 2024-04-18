#ifndef Sistema_hpp
#define Sistema_hpp
#include "../XML/XML.hpp"
#include "../DataBase/DataBase.hpp"

class Sistema {
    private:
        DataBase dataBase;
    public:
        Sistema(DataBase database);
        ~Sistema();
        void inserirNoBanco(XML *data);
};


#endif