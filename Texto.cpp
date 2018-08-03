#include "Texto.h"


void Texto::setNomeArquivo(string Nome) {
    Nome_Arquivo_Texto = Nome;
}

void Texto::CarregarTexto() {

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
    }

}


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


void Texto::GravarTexto(ofstream &Arquivo) {
    
    list<Palavra>::iterator it;
    for (it = Palavras_Texto.begin(); it != Palavras_Texto.end(); it++)
        Arquivo << *it << " ";
    
    Arquivo.close();

}
void Texto::GravarTexto() {
    
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



list<Palavra> Texto::getPalavrasTexto() {
    return Palavras_Texto;
}

void Texto::AlterarPalavra(list<Palavra> &Lista, Palavra &P) {

    Palavras_Texto = Lista;

    Palavra P2;
    cout << "Digite a Palavra desejada: ";
    cin >> P2;

    for (list<Palavra>::iterator it = Palavras_Texto.begin(); it != Palavras_Texto.end(); it++) {
        if (*it == P) {
            *it = P2;
            break;
        }
    }

}
