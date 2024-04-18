#ifndef HDMItoVGAadapter_hpp
#define HDMItoVGAadapter_hpp
#include "../interfaces/HDMI.hpp"
#include "../interfaces/VGA.hpp"

class HDMItoVGAadapter:public HDMI {
    private:
        VGA *vga;
    public:
        HDMItoVGAadapter(VGA *vga);
        void setImage(char *image);
        void setSound(char *sound);
};


#endif