#include <iostream>
using namespace std;

#include "Dicionario.h"

int main() {

    Dicionario D;

    ifstream arquivo("teste.txt");
    D.InserirPalavras(arquivo);
    D.ImprimirPalavras();

    Palavra P("Bananoide");
    D.setSemelhantes(P);
    D.MostrarSemelhantes();


    return 0;
}