#include <iostream>
using namespace std;

#include "Dicionario.h"

int main() {

    Dicionario A;

    ifstream arquivo("teste.txt");
    A.InserirPalavras(arquivo);


    return 0;
}