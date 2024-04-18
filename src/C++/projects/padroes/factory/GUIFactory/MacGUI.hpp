#ifndef MacGUI_hpp
#define MacGUI_hpp
#include "GUIFactory.hpp";

class MacGUI : public GUIFactory {
    public:
        MacGUI();
        ~MacGUI();
        void print();
};

#endif