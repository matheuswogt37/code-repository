#include "HDMItoVGAadapter.hpp"

HDMItoVGAadapter::HDMItoVGAadapter(VGA *vga) {
    std::cout << "conectando ao adaptador vga\n";
    this->vga = vga;
}

void HDMItoVGAadapter::setImage(char *image) {
    std::cout << "convertendo imagem HDMI para VGA\n";
    this->vga->setImage(image);
}