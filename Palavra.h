
/*Classe Palavra - "Mínimo"
    - Contém ao menos a Palavra;
    - Um método que verifique se duas Palavras são semelhantes (começam com as duas mesmas letras);
    - Contém operador == sobrecarregado para verificar se duas Palavras são idênticas.
*/

#ifndef PALAVRA_H
#define PALAVRA_H

// #include "Texto.h"
// #include "Dicionario.h"

#include <iostream>
using namespace std;

class Palavra {

    private:
        string palavra;

    public:
        Palavra(string P = "");
        string getPalavra();
        void setPalavra(string);
        bool Semelhante(Palavra &);

};

bool operator>(Palavra &, Palavra &);
bool operator<(Palavra &, Palavra &);
bool operator==(Palavra &, Palavra &);
ostream & operator << (ostream &saida, Palavra &P);
istream & operator >> (istream &entrada, Palavra &P);

#endif 

