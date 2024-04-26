#ifndef BaseDecorator_hpp
#define BaseDecorator_hpp
#include "../Music/Music.hpp"

class BaseDecorator : public Music {
    protected:
        Music *wrapper;
    public:
        BaseDecorator(Music *w);
        ~BaseDecorator();
        void play(std::string music);
};

#endif