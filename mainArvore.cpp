#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

#include "Arvore.h"

int main() {

    Arvore A;

    vector<Palavra> words;
    Palavra temp;
    ifstream file("dic.txt");

    while (file >> temp) {
        words.push_back(temp);
    }
    file.close();

    cout << "Palavras encontradas: ";
    for (int i = 0; i < words.size(); i++)
        cout << words.at(i) << " ";
    cout << endl;

    cout << "Inserindo na Arvore...";
    for (int i = 0; i < words.size(); i++)
        A.Inserir(words.at(i));
    cout << endl;

    int Opcao = -1;
    while (Opcao != 0) {

        cout << "Digite a opcao: ";
        cin >> Opcao;

        switch(Opcao) {

            case 1: { // Insercao
                Palavra P;
                cout << "Digite a palavra: ";
                cin >> P;
                A.Inserir(P);
                A.AtualizaFbs(A.getPrimeiro());
                break;
            }

            case 3: { // Imprimir
                A.PreOrdem(A.getPrimeiro());
                cout << endl;
                break;
            }

            case 4: { // MostraFbs
                A.AtualizaFbs(A.getPrimeiro());
                A.MostraFbs(A.getPrimeiro());
                cout << endl;
                cout << "Altura = " << A.altura(A.getPrimeiro()) << endl;
                break;
            }

            case 5: { // Busca
                Palavra R;
                cout << "Digite a palavra a ser procurada: ";
                cin >> R;
                No *Temp = A.Busca(R);
                if (Temp)
                    cout << "Palavra '" << Temp->P << "' encontrada!" << endl;
                else
                    cout << "Nao encontrou" << endl;
                break;
            }

            case 6: { // Teste semelhantes

                Palavra P1("Banana"), P2("Bananoide");
                if (P1.Semelhante(P2))
                    cout << "Semelhantes!" << endl;
                else
                    cout << "Nao semelhantes!" << endl;

                break;
            }

        }
    }



    return 0;
}