#ifndef Equalizer_hpp
#define Equalizer_hpp
#include "../../BaseDecorator/BaseDecorator.hpp"

class Equalizer : public BaseDecorator
{
    public:
        Equalizer(Music *w);
        ~Equalizer();
        void play(std::string music);
};


#endif