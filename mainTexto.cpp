#include <iostream>
using namespace std;

#include "Texto.h"

int main() {

    Texto T;
    string Nome_Arquivo;

    cout << "Digite o nome do arquivo que quer abrir: ";
    getline(cin, Nome_Arquivo);

    T.setNomeArquivo(Nome_Arquivo);
    T.CarregarTexto();

    cout << "Texto do arquivo:" << endl;
    T.ImprimirTexto();


    return 0;
}