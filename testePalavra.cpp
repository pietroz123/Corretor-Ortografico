#include <iostream>
using namespace std;
#include <string>

#include "Palavra.h"


bool VerificaPontuacao(Palavra &P, char &c) {
    string Word = P.getPalavra();
    for (int i = 0; i < Word.size(); i++) {
        if (ispunct(Word[i])) {
            c = Word[i];
            return 1;
        }
    }
    return 0;
}

int main() {

    Palavra P("legal.");
    char c;

    cout << "Palavra = '" << P << "'" << endl;

    if (VerificaPontuacao(P, c)) {
        cout << "Char = '" << c << "'" << endl;
    }

    cout << "Digite a palavra para corrigir: ";
    Palavra C;
    cin >> C;

    string p = P.getPalavra();
    p = C.getPalavra();
    p += c;
    P.setPalavra(p);
    cout << "Palavra corrigida: " << P;


    return 0;
}