#ifndef Eco_hpp
#define Eco_hpp
#include "../../BaseDecorator/BaseDecorator.hpp"

class Eco : public BaseDecorator
{
    public:
        Eco(Music *w);
        ~Eco();
        void play(std::string music);
};


#endif