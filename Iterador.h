#ifndef ITERADOR_H
#define ITERADOR_H

#include "Arvore.h"

class Iterador {

    friend class Arvore;

    private:
        No *Atual;

    public:
        Iterador(No *Raiz) {
            this->Atual = Raiz;
        }
        Iterador Proximo(Iterador it) {
            it.Atual = sucessor_em_ordem(it);
            return it;
        }

};

#endif