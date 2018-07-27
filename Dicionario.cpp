#include "Dicionario.h"
#include <vector>
#include <list>


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
    //     A.Inserir(words.at(i));

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
        A.Inserir(*it);
    cout << endl;

}

void Dicionario::ImprimirPalavras() {
    cout << "Imprimindo arvore..." << endl;
    A.PreOrdem(A.getPrimeiro());
    cout << endl;
}