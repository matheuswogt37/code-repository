#include <iostream>
#include "core/Application.hpp"

int main() {
    Application app = Application();
    //* Inicia tudo o que a aplicacao precisa para rodar
    app.initialize(1920, 1080, "Hello World");
    //* Roda a aplicacao
    app.run();
    //* O destrutor da Application finaliza tudo o que precisou para rodar
    return 0;
}