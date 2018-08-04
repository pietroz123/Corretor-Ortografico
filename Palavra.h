
/* Número do Grupo: 9
*  Membros:
*    → Bianca Gomes Rodrigues    RA: 743512
*    → Pietro Zuntini Bonfim     RA: 743588
*
* Classe Palavra - "Mínimo"
*    → Contém ao menos a Palavra;
*    → Um método que verifique se duas Palavras são semelhantes (começam com as duas mesmas letras);
*    → Contém operador == sobrecarregado para verificar se duas Palavras são idênticas.
*/

#ifndef PALAVRA_H
#define PALAVRA_H

#include <iostream>
using namespace std;

class Palavra {

    private:
        // → Contém ao menos a Palavra;
        string palavra;

    public:
        Palavra(string P = "");
        string getPalavra();
        void setPalavra(string);
        
        // → Verifica se duas Palavras são semelhantes
        bool Semelhante(Palavra &);

};

bool operator>(Palavra &, Palavra &);
bool operator<(Palavra &, Palavra &);
bool operator==(Palavra &, Palavra &);
ostream & operator << (ostream &saida, Palavra &P);
istream & operator >> (istream &entrada, Palavra &P);

#endif 

