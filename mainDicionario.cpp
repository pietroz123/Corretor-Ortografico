#include <iostream>
using namespace std;

#include "Dicionario.h"

int main() {

    Dicionario D;

    ifstream arquivo("teste.txt");
    D.InserirPalavras(arquivo);
    D.ImprimirPalavras();

    Palavra P("bananoide");
    D.setSemelhantes(P);
    cout << "Mostrando palavras semelhantes a '" << P << "' ..." << endl;
    D.MostrarSemelhantes();


    return 0;
}