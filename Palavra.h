
/* Palavra.h
* 
* Número do Grupo: 9
* Membros:
*    → Bianca Gomes Rodrigues    RA: 743512
*    → Pietro Zuntini Bonfim     RA: 743588
*
* Classe Palavra
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

        friend bool operator>(Palavra &, Palavra &);
        friend bool operator<(Palavra &, Palavra &);
        friend bool operator==(Palavra &, Palavra &);
        friend ostream & operator << (ostream &saida, Palavra &P);
        friend istream & operator >> (istream &entrada, Palavra &P);

};



#endif 

