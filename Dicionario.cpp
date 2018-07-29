#include "Dicionario.h"
#include <vector>


void Dicionario::InserirPalavras(ifstream &arquivo) {

    // list<Palavra> words;
    Palavra temp;
    
    while (arquivo >> temp)
        // words.push_back(temp);
        Palavras_Do_Dicionario.Inserir(temp);
    
    arquivo.close();

    // list<Palavra>::iterator it;

    // cout << "Palavras do arquivo texto dic.txt: ";
    // for (it = words.begin(); it != words.end(); it++)
    //     cout << *it << " ";
    // cout << endl;

    // cout << "Inserindo na arvore..." << endl;
    // for (it = words.begin(); it != words.end(); it++)
    //     Palavras_Do_Dicionario.Inserir(*it);
    // cout << endl;

}

void Dicionario::ImprimirPalavras() {
    cout << "Imprimindo arvore..." << endl;
    Palavras_Do_Dicionario.PreOrdem(Palavras_Do_Dicionario.getPrimeiro());
    cout << endl;
}


bool Dicionario::Consulta(Palavra &P) {
    return Palavras_Do_Dicionario.Busca(P) != NULL;
}


void Dicionario::InserirPalavra(Palavra &P) {
    Palavras_Do_Dicionario.Inserir(P);
}



void Dicionario::setSemelhantes_Privado(No *N, Palavra &P) {
    if (N == NULL)  return;
    if ((N->P).Semelhante(P)) {
        Semelhantes.push_back(N->P);
    }
    setSemelhantes_Privado(N->Filho_Esquerdo, P);
    setSemelhantes_Privado(N->Filho_Direito, P);
}
void Dicionario::setSemelhantes(Palavra &P) {
    Dicionario::setSemelhantes_Privado(Palavras_Do_Dicionario.getPrimeiro(), P);
}

void Dicionario::MostrarSemelhantes() {

    if (Palavras_Do_Dicionario.Vazia()) {
        cout << "Nao foram inseridas palavras na arvore!" << endl;
        return;
    }

    list<Palavra>::iterator it;
    for (it = Semelhantes.begin(); it != Semelhantes.end(); it++)
        cout << *it << " ";

    cout << endl;

}