
/* Texto.cpp
*
*  Número do Grupo: 9
*  Membros:
*    → Bianca Gomes Rodrigues    RA: 743512
*    → Pietro Zuntini Bonfim     RA: 743588
*
*  Contém as implementações da classe Texto
*/

#include "Texto.h"

// → Permite carregar um Texto a partir de um ARQUIVO;
void Texto::setNomeArquivo(string Nome) {
    Nome_Arquivo_Texto = Nome;
}
void Texto::CarregarTexto() {

    string Nome_Texto;
    cout << "Digite o nome do arquivo texto (formato nome.txt): ";
    cin >> Nome_Texto;

    Nome_Arquivo_Texto = Nome_Texto;

    ifstream Arquivo;
    Arquivo.open(Nome_Arquivo_Texto, ifstream::in);

    if (Arquivo) {

        Palavra Temp;
        while (Arquivo >> Temp)
            Palavras_Texto.push_back(Temp);

        Arquivo.close();

    }
    else{
        cout << "Arquivo inexistente!" << endl;
        CarregarTexto();
    }

}

// → Permite percorrer o texto, palavra por palavra;
void Texto::ImprimirTexto() {

    list<Palavra>::iterator it;
    for (it = Palavras_Texto.begin(); it != Palavras_Texto.end(); it++)
        cout << *it << " ";
    
    cout << endl;

}
bool Texto::Buscar(Palavra &P) {

    list<Palavra>::iterator it;

    for (it = Palavras_Texto.begin(); it != Palavras_Texto.end(); it++) {
        if (P == *it)
            return true;
    }
    
    return false;
}


// → Permite GRAVAR o Texto em um ARQUIVO (Não necessariamente o Original);
void Texto::GravarTextoArquivo(ofstream &Arquivo) {
    
    list<Palavra>::iterator it;
    for (it = Palavras_Texto.begin(); it != Palavras_Texto.end(); it++)
        Arquivo << *it << " ";
    
    Arquivo.close();

}
void Texto::GravarTextoDiferente() {
    
    string Nome;
    cout << "Digite o nome do arquivo que quer abrir: ";
    cin >> Nome;

    ofstream Arquivo;
    Arquivo.open(Nome, ofstream::out);

    list<Palavra>::iterator it;
    for (it = Palavras_Texto.begin(); it != Palavras_Texto.end(); it++) 
        Arquivo << *it << " ";

    Arquivo.close();

}
void Texto::GravarTextoOriginal() {

    ofstream Original;
    Original.open(Nome_Arquivo_Texto, ofstream::out);

    list<Palavra>::iterator it;
    for (it = Palavras_Texto.begin(); it != Palavras_Texto.end(); it++)
        Original << *it << " ";

    Original.close();
    
}


// Métodos Get e Set
list<Palavra> Texto::getPalavrasTexto() {
    return Palavras_Texto;
}
void Texto::setPalavrasTexto(list<Palavra> &Lista) {
    Palavras_Texto = Lista;
}


// → Permite alterar uma Palavra;
void Texto::AlterarPalavra(list<Palavra>::iterator &it) {
    Palavra P2;
    cout << "Digite a Palavra desejada: ";
    cin >> P2;
    *it = P2;
}
