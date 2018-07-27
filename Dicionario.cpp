#include "Dicionario.h"
#include <vector>


void Dicionario::InserirPalavras(ifstream &arquivo) {
    
    vector<Palavra> words;
    Palavra temp;
    
    while (arquivo >> temp)
        words.push_back(temp);
    
    arquivo.close();

    cout << "Palavras do arquivo texto: ";
    for (int i = 0; i < words.size(); i++)
        cout << words.at(i) << " ";
    cout << endl;

    cout << "Inserindo na arvore..." << endl;
    for (int i = 0; i < words.size(); i++)
        A.Inserir(words.at(i));

}

void Dicionario::ImprimirPalavras() {
    A.PreOrdem(A.getPrimeiro());
}