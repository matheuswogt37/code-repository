#include <iostream>
#include <string>
#include <array>

class Casa;
class Fabrica;
class Loja;

class Visitor {
   public:
    virtual void VisitCasa(Casa *element) = 0;
    virtual void VisitFabrica(Fabrica *element) = 0;
    virtual void VisitLoja(Loja *element) = 0;
};

class SeguroBase {
   public:
    SeguroBase(){};
    virtual ~SeguroBase(){};
    virtual void oferecer(Visitor *visitor) = 0;
};

class Casa : public SeguroBase {
   public:
    void oferecer(Visitor *visitor) override {
        visitor->VisitCasa(this);
    }

    std::string tipoSeguro() {
        return "casa - seguro domiciliar\n";
    }
};

class Fabrica : public SeguroBase {
   public:
    void oferecer(Visitor *visitor) override {
        visitor->VisitFabrica(this);
    }

    std::string tipoSeguro() {
        return "fabrica - seguro desemprego\n";
    }
};

class Loja: public SeguroBase {
   public:
    void oferecer(Visitor *visitor) override {
        visitor->VisitLoja(this);
    }

    std::string tipoSeguro() {
        return "loga - seguro contra roubos e incêndios\n";
    }
};

class SeguradoraJamil : public Visitor {
   public:
    void VisitCasa(Casa *element) override {
        std::cout << "---------Jamil---------\n"
                  << element->tipoSeguro() << "Custo mensal R$250,00\n";
    }

    void VisitFabrica(Fabrica *element) override {
        std::cout << "---------Jamil---------\n"
                  << element->tipoSeguro() << "Custo mensal R$1500,00\n";
    }
    void VisitLoja(Loja *element) override {
        std::cout << "---------Jamil---------\n"
                  << element->tipoSeguro() << "Custo mensal R$500,00\n";
    }
};

class SeguradoraMarco : public Visitor {
   public:
    void VisitCasa(Casa *element) override {
        std::cout << "---------Marco---------\n"
                  << element->tipoSeguro() << "Custo mensal R$150,00\n";
    }

    void VisitFabrica(Fabrica *element) override {
        std::cout << "---------Marco---------\n"
                  << element->tipoSeguro() << "Custo mensal R$2000,00\n";
    }
    void VisitLoja(Loja *element) override {
        std::cout << "---------Marco---------\n"
                  << element->tipoSeguro() << "Custo mensal R$450,00\n";
    }
};

void oferecerAlvos(std::array<SeguroBase *, 3> alvos, Visitor *visitor) {
    for (SeguroBase *alvo: alvos) {
        alvo->oferecer(visitor);
    }
};

int main() {
    std::array<SeguroBase *, 3> alvos = {new Casa, new Fabrica, new Loja};

    SeguradoraJamil jamil;
    SeguradoraMarco marco;

    //* jamil ofertas
    oferecerAlvos(alvos, &jamil);

    //* only for break line
    std::cout << "\n";

    //* marco ofertas
    oferecerAlvos(alvos, &marco);

    for (SeguroBase *alvo: alvos) {
        delete alvo;
    }

    return 0;
}