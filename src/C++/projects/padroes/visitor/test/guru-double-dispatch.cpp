// Online C++ compiler to run C++ program online
    #include <iostream>
    #include <string>
    
    class Method {
        public:
            virtual std::string getName() = 0;
    };
    
    class NodeAbs : public Method {
        public:
            virtual std::string getName() {
                return "node abs";
            }
    };
    
    class City : public NodeAbs {
        public:
            std::string getName() {
                return "city";
            }
    };
    
    class Road : public City {
        public:
            std::string getName() {
                return "road";
            }
    };
    
    class Shop : public NodeAbs {
        public:
            std::string getName() {
                return "shop";
            }
    };
    
    class Exporter {
        public:
            void exporte(NodeAbs *node) {
                std::cout << "nodeAbs exported";
            }
            void exporte(City *node) {
                std::cout << "city exported";
            }
            void exporte(Road *node) {
                std::cout << "road exported";
            }
            void exporte(Shop *node) {
                std::cout << "shop exported";
            }
    };
    
    class App {
        public:
            void exporte(NodeAbs *node) {
                Exporter *exp = new Exporter();
                exp->exporte(node);
            }
    };
    
    
    int main() {
        
        App app;
        NodeAbs *road = new Road();
        app.exporte(road);
        
        return 0;
    }