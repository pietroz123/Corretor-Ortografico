#include "Dicionario.h"
#include <vector>


void Dicionario::InserirPalavras(ifstream &arquivo) {
    
    // vector<Palavra> words;
    // Palavra temp;
    
    // while (arquivo >> temp)
    //     words.push_back(temp);
    
    // arquivo.close();

    // cout << "Palavras do arquivo texto: ";
    // for (int i = 0; i < words.size(); i++)
    //     cout << words.at(i) << " ";
    // cout << endl;

    // cout << "Inserindo na arvore..." << endl;
    // for (int i = 0; i < words.size(); i++)
    //     Palavras_Do_Arquivo.Inserir(words.at(i));

    list<Palavra> words;
    Palavra temp;
    
    while (arquivo >> temp)
        words.push_back(temp);
    
    arquivo.close();

    list<Palavra>::iterator it;

    cout << "Palavras do arquivo texto: ";
    for (it = words.begin(); it != words.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "Inserindo na arvore..." << endl;
    for (it = words.begin(); it != words.end(); it++)
        Palavras_Do_Arquivo.Inserir(*it);
    cout << endl;

}

void Dicionario::ImprimirPalavras() {
    cout << "Imprimindo arvore..." << endl;
    Palavras_Do_Arquivo.PreOrdem(Palavras_Do_Arquivo.getPrimeiro());
    cout << endl;
}


bool Dicionario::Consulta(Palavra &P) {
    return Palavras_Do_Arquivo.Busca(P) != NULL;
}


void Dicionario::InserirPalavra(Palavra &P) {
    Palavras_Do_Arquivo.Inserir(P);
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
    Dicionario::setSemelhantes_Privado(Palavras_Do_Arquivo.getPrimeiro(), P);
}

void Dicionario::MostrarSemelhantes() {

    if (Palavras_Do_Arquivo.Vazia()) {
        cout << "Nao foram inseridas palavras na arvore!" << endl;
        return;
    }

    list<Palavra>::iterator it;
    for (it = Semelhantes.begin(); it != Semelhantes.end(); it++)
        cout << *it << " ";

    cout << endl;

}