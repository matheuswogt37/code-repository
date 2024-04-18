#ifndef OldMonitor_hpp
#define OldMonitor_hpp
#include "../interfaces/VGA.hpp"

class OldMonitor:public VGA {
    public:
        void setImage(char *video);
};


#endif