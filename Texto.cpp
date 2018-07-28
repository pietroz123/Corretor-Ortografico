#include "Texto.h"


void Texto::setNomeArquivo(string Nome) {
    Nome_Arquivo_Texto = Nome;
}

void Texto::CarregarTexto() {

    ifstream Arquivo;
    Arquivo.open(Nome_Arquivo_Texto, ifstream::in);

    Palavra Temp;
    while (Arquivo >> Temp)
        Palavras_Texto.push_back(Temp);

    Arquivo.close();

}


void Texto::ImprimirTexto() {

    list<Palavra>::iterator it;
    for (it = Palavras_Texto.begin(); it != Palavras_Texto.end(); it++)
        cout << *it << " ";
    
    cout << endl;

}


void Texto::GravarTexto(ofstream &Arquivo) {
    
    list<Palavra>::iterator it;
    for (it = Palavras_Texto.begin(); it != Palavras_Texto.end(); it++)
        Arquivo << *it << " ";
    
    Arquivo.close();

}