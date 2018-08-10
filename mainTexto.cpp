#include <iostream>
using namespace std;

#include "Texto.h"

int main() {

    Texto T;

    T.CarregarTexto();

    int Opcao = -1;
    while (Opcao != 0) {

        cout << "(0) Sair (1) Imprimir (2) Buscar" << endl;
        cout << "Opcao: ";
        cin >> Opcao;

        switch(Opcao) {

            case 1: {
                T.ImprimirTexto();
                break;
            }
            case 2: {

                Palavra P2;
                cout << endl << "Digite uma palavra para busca: ";
                cin >> P2;
                
                if (T.Buscar(P2))
                    cout << "A palavra '" << P2 << "' pertence ao texto!" << endl << endl;
                else
                    cout << "A palavra '" << P2 << "' NAO pertence ao texto!" << endl << endl;

                break;
            }

        }

    }

    cout << endl << "Deseja gravar o texto em outro arquivo? (1) SIM (2) NAO: ";
    int Resposta;
    cin >> Resposta;
    if (Resposta == 1) {
        T.GravarTextoDiferente();
    }



    return 0;
}