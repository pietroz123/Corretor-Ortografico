#include <iostream>
using namespace std;

#include "Dicionario.h"

int main() {

    Dicionario D;

    ifstream arquivo("teste.txt");
    D.InserirPalavras(arquivo);

    D.ImprimirPalavras();


    return 0;
}