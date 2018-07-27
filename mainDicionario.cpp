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

    Palavra P2("edson");
    if (D.Consulta(P2))
        cout << "Existe a palavra na arvore do dicionario!" << endl;
    else
        cout << "NAO existe a palavra na arvore do dicionario!" << endl;


    return 0;
}