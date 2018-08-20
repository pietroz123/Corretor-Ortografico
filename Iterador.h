#ifndef ITERADOR_H
#define ITERADOR_H

#include "Arvore.h"

class Iterador {

    friend class Arvore;

    private:
        No *Atual;
        No *SucessorEmOrdem(No *N);

    public:
        Iterador(No *raiz);
        bool operator==(const Iterador &it);        // comparação entre iteradores
        bool operator!=(const Iterador &Outro);      
        Palavra &operator*() const;                 // acessa e retorna a Palavra
        Iterador operator++();                      // incrementa para o próximo valor maior
        Iterador operator++(int n);                 // incrementa em n posições
        Iterador operator--();                      // decrementa para o valor anterior
        Iterador operator--(int n);                 // decrementa em n posições


};

#endif