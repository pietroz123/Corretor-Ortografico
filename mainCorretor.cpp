#include <iostream>
using namespace std;

#include "Corretor.h"
#include <string>

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
    cout << "Deseja gravar o texto em um arquivo diferente? (1) SIM (2) NAO : ";
    cin >> Opcao;

    if (Opcao == 1)
        T.GravarTexto();   


    return 0;
}