#ifndef ConcMusic_hpp
#define ConcMusic_hpp
#include "../Music/Music.hpp"

class ConcMusic : public Music
{
    public:
        ConcMusic();
        ~ConcMusic();
        void play(std::string music);
};

#endif