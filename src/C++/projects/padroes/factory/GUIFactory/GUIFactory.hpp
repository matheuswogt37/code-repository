#ifndef GUIFactory_hpp
#define GUIFactory_hpp
#include <stdio.h>
#include "Button.hpp";
#include "CheckBox.hpp";

class GUIFactory : public Button, CheckBox {
    protected:
        GUIFactory();
    public:
        ~GUIFactory();
        Button* createButton();
        CheckBox createCheckBox();
};


#endif