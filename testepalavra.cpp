#include <iostream>
using namespace std;

#include "Palavra.h"
#include <string>

string RemovePontuacao(Palavra P) {

    string palavra = P.getPalavra();

    for (int i = palavra.size() - 1; i > 0; i--) {
        if (ispunct(palavra[i])) {
            if (palavra[i] == '-')  // cuida do caso de Palavras com hífen, como louva-a-Deus
                return palavra;
            palavra.erase(i--, 1);
        }
    }

    return palavra;
}

int main() {

    Palavra P1("Bianca.");
    Palavra P2("Pietro!");
    Palavra P3("serio?");
    Palavra P4("louva-a-Deus");

    cout << RemovePontuacao(P4) << endl;




    return 0;    
}