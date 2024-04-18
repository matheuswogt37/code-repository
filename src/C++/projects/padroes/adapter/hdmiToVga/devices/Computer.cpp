#include "Computer.hpp"

void Computer::connectPort(HDMI *cable) {
    std::cout << "conectado porta HDMI\n";
    this->port = cable;
}

void Computer::sendImageAndSound(char *image, char *sound) {
    this->port->setImage(image);
    this->port->setSound(sound);
}