#include "DataBase/DataBase.hpp"
#include "JSON/JSON.hpp"
#include "JSONtoXMLAdapter/JSONtoXMLAdapter.hpp"
#include "NotaJSON/NotaJSON.hpp"
#include "NotaXML/NotaXML.hpp"
#include "Sistema/Sistema.hpp"
#include "Utils/SimulateFile/SimulateFile.hpp"
#include "XML/XML.hpp"


int main() {

    DataBase mysql;
    Sistema sistema(mysql);

    // simular insercao XML
    std::cout << "\nXML\n";
    SimulateFile simulateXml;
    simulateXml = (SimulateFile){.nome = "CSV Confecoes", .cnpj = "13.673.981/0001-98", .valorTotal = 55000.87};
    XML *notaXML = new NotaXML();
    notaXML->getDadosFromFile(simulateXml);
    sistema.inserirNoBanco(notaXML);

    // simular insercao JSON
    std::cout << "\nJSON\n";
    SimulateFile simulateJson;
    simulateJson = (SimulateFile){.nome = "Backman Tinturas", .cnpj = "17.293.876/0091-76", .valorTotal = 89000.50};
    JSON *jsonNota = new NotaJSON();
    XML *notaJson = new JSONtoXMLAdapter(jsonNota);
    notaJson->getDadosFromFile(simulateJson);
    sistema.inserirNoBanco(notaJson);



    return 0;
}