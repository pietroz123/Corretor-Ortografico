
/* Número do Grupo: 9
*  Membros:
*    → Bianca Gomes Rodrigues    RA: 743512
*    → Pietro Zuntini Bonfim     RA: 743588
*/

#include "Palavra.h"

// Construtor
Palavra::Palavra(string P) {
    palavra = P;
}


// Métodos Get e Set
string Palavra::getPalavra() {
    return palavra;
}
void Palavra::setPalavra(string Palavra) {
    palavra = Palavra;
}


// → Verifica se duas Palavras são semelhantes
bool Palavra::Semelhante(Palavra &p2){
    
    string P1 = palavra;
    string P2 = p2.getPalavra();

    for(int i = 0; i<2; i++)
        if(P1[i] != P2[i])
            return false;
    
    return true;    
}

// Operador > sobrecarregado
bool operator>(Palavra &p1, Palavra &p2){

    string P1 = p1.getPalavra();
    string P2 = p2.getPalavra();

    if (P1 > P2)
        return true;
    return false;
}

// Operador < sobrecarregado
bool operator<(Palavra &p1, Palavra &p2){

    string P1 = p1.getPalavra();
    string P2 = p2.getPalavra();

    if (P1 < P2)
        return true;
    return false;
}

// Operador == sobrecarregado
bool operator==(Palavra &p1, Palavra &p2){

    string P1 = p1.getPalavra();
    string P2 = p2.getPalavra();

    if (P1 == P2)
        return true;
    return false;
}

// Operador << sobrecarregado (SAIDA)
ostream & operator << (ostream &saida, Palavra &P) {
    saida << P.getPalavra();
    return saida;
}

// Operador >> sobrecarregado (ENTRADA)
istream & operator >> (istream &entrada, Palavra &P) {
    string Palavra;
    entrada >> Palavra;
    P.setPalavra(Palavra);
    return entrada;
}