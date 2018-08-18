#ifndef NO_H_
#define NO_H_
#include "Palavra.h"

class No {

    private:
        Palavra P;
        int Fb;
        No *Filho_Direito;
        No *Filho_Esquerdo;
    
    public:
        No(Palavra P);
        ~No();

};

#endif