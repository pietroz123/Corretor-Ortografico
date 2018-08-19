#ifndef NO_H_
#define NO_H_
#include "Palavra.h"

class No {

    
    public:
        Palavra P;
        int Fb;
        No *Filho_Direito;
        No *Filho_Esquerdo;
        No *Pai;
        No(Palavra P);
        ~No();

};

#endif