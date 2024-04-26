#ifndef Music_hpp
#define Music_hpp
#include <iostream>
#include <string>

class Music {
    public:
        Music();
        ~Music();
        virtual void play(std::string music);
};


#endif