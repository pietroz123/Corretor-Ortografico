#include <iostream>
using namespace std;

#include "Arvore.h"

int main() {

    Arvore A;

    int Opcao = -1;
    while (Opcao != 0) {

        cout << "(0) Sair (1) Inserir (2) Remover (3) Imprimir (4) Buscar" << endl;
        cout << "Opcao: ";
        cin >> Opcao;

        switch(Opcao) {

            case 1: { // Insercao
                
                Palavra P;
                cout << "Digite a palavra para inserir: ";
                cin >> P;
                
                A.Inserir(P);
                
                break;
            }
            
            case 2: { // Remover

                Palavra R;
                cout << "Digite a palavra para remover: ";
                cin >> R;

                A.Remover(R);

                break;
            }

            case 3: { // Imprimir
                
                A.EmOrdem();
                cout << endl;
                
                break;
            }

            case 4: { // Busca
                
                Palavra B;
                cout << "Digite a palavra a ser procurada: ";
                cin >> B;
                
                if (A.Busca(B))
                    cout << "Palavra '" << B << "' encontrada!" << endl;
                else
                    cout << "Nao encontrou" << endl;
                
                break;
            }

            case 5: { // Pais

                A.MostraPais();

                break;
            }

            case 6: { // Iterador

                for (Iterador it = A.begin(); it != A.end(); ++it)
                    cout << *it << " ";
                cout << endl;

                break;
            }

        }
    }



    return 0;
}