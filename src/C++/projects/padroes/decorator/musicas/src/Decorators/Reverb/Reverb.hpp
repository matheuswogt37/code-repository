#ifndef Reverb_hpp
#define Reverb_hpp
#include "../../BaseDecorator/BaseDecorator.hpp"

class Reverb : public BaseDecorator
{
    public:
        Reverb(Music *w);
        ~Reverb();
        void play(std::string music);
};


#endif