#include "Palavra.h"

Palavra::Palavra(string P) {
    palavra = P;
}

string Palavra::getPalavra() {
    return palavra;
}
void Palavra::setPalavra(string Palavra) {
    palavra = Palavra;
}

bool Palavra::Semelhante(Palavra &p2){
    
    string P1 = palavra;
    string P2 = p2.getPalavra();

    for(int i = 0; i<2; i++)
        if(P1[i] != P2[i])
            return false;
    
    return true;    
}


bool operator>(Palavra &p1, Palavra &p2){

    string P1 = p1.getPalavra();
    string P2 = p2.getPalavra();

    if (P1 > P2)
        return true;
    return false;
}

bool operator<(Palavra &p1, Palavra &p2){

    string P1 = p1.getPalavra();
    string P2 = p2.getPalavra();

    if (P1 < P2)
        return true;
    return false;
}

bool operator==(Palavra &p1, Palavra &p2){

    string P1 = p1.getPalavra();
    string P2 = p2.getPalavra();

    if (P1 == P2)
        return true;
    return false;
}

ostream & operator << (ostream &saida, Palavra &P) {
    saida << P.getPalavra();
    return saida;
}

istream & operator >> (istream &entrada, Palavra &P) {
    string Palavra;
    entrada >> Palavra;
    P.setPalavra(Palavra);
    return entrada;
}