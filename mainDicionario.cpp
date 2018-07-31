#include <iostream>
using namespace std;

#include "Dicionario.h"

int main() {

    Dicionario D;

    ifstream arquivo("dic.txt");
    D.InserirPalavras(arquivo);
    D.ImprimirPalavras();

    Palavra P("bananoide");
    D.setSemelhantes(P);
    cout << endl << "Mostrando palavras semelhantes a '" << P << "' ..." << endl;
    D.MostrarSemelhantes();

    Palavra P2;
    cout << endl << "Digite uma palavra para busca: ";
    cin >> P2;
    if (D.Consulta(P2))
        cout << "Existe a palavra '" << P2 << "' na arvore do dicionario!" << endl;
    else {
        cout << "NAO existe a palavra '" << P2 << "' na arvore do dicionario!" << endl;
        int Opcao;
        cout << "Deseja inserir a palavra? (1) SIM (2) NAO : ";
        cin >> Opcao;
        if (Opcao == 1)
            D.InserirPalavra(P2);
    }

    D.ImprimirPalavras();


    return 0;
}