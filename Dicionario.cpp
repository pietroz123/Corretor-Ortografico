#include "Dicionario.h"
#include <vector>


void Dicionario::InserirPalavras(ifstream &arquivo) {
    
    vector<Palavra> words;
    Palavra temp;
    
    while (arquivo >> temp)
        words.push_back(temp);
    
    arquivo.close();

    for (int i = 0; i < words.size(); i++)
        cout << words.at(i) << " ";

}

void Dicionario::ImprimirPalavras() {
    
}