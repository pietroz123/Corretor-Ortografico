#include <iostream>
using namespace std;

#include "Dicionario.h"

int main() {

    Dicionario D;

    ifstream arquivo("dic.txt");
    D.InserirPalavras(arquivo);

    int Opcao = -1;
    while (Opcao != 0) {

        cout << "(0) Sair (1) Consulta" << endl;
        cout << "Opcao: ";
        cin >> Opcao;

        Palavra P2;
        cout << endl << "Digite uma palavra para busca: ";
        cin >> P2;

        if (D.Consulta(P2))
            cout << "A palavra '" << P2 << "' pertence ao dicionario!" << endl << endl;
        else
            cout << "A palavra '" << P2 << "' NAO pertence ao dicionario!" << endl << endl;


    }


    return 0;
}