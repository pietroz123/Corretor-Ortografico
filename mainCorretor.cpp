#include <iostream>
using namespace std;

#include "Corretor.h"
#include <string>

#define SAIR            0
#define COMPARAR        1
#define DICIONARIO      2

int main() {

    Corretor C;
    Dicionario D;
    Texto T;

    ifstream Arquivo_Dicionario("dic.txt");
    cout << "Inserindo palavras..." << endl;
    D.InserirPalavras(Arquivo_Dicionario);
    cout << "Imprimindo palavras..." << endl;
    D.ImprimirPalavras();

    string Nome_Texto;
    cout << "Digite o nome do arquivo texto: ";
    cin >> Nome_Texto;

    T.setNomeArquivo(Nome_Texto);
    T.CarregarTexto();

    T.ImprimirTexto();

    C.Compara(T, D);

    int Opcao;

    while(Opcao != 2){
        cout << "Deseja gravar o texto em um arquivo diferente?" << endl << "(1) SIM" << endl << "(2) NAO" << endl;
        cin >> Opcao;
        if (Opcao == 1){
            T.GravarTexto();   
            cout << "Texto gravado com sucesso!" << endl;
        }
    }

    return 0;
}