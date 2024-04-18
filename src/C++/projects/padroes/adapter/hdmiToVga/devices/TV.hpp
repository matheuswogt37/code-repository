#ifndef TV_hpp
#define TV_hpp
#include "../interfaces/HDMI.hpp"

class TV:public HDMI {
    public:
        void setImage(char *image);
        void setSound(char *sound);
};

#endif