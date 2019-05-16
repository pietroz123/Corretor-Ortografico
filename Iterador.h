#ifndef ITERADOR_H
#define ITERADOR_H

#include "Arvore.h"

class Iterador {

    friend class Arvore;

    private:
        No *Atual;
        No *SucessorEmOrdem(No *N);
        No *PredecessorEmOrdem(No *N);

        // Funções Auxiliares
        No *Min(No *N);
        No *Max(No *N);


    public:
        Iterador(No *raiz);                         // construtor por nó
        Iterador(const Iterador &Outro);            // construtor por cópia
        bool operator==(const Iterador &it);        // comparação entre iteradores (it1 == it2)
        bool operator!=(const Iterador &Outro);     // comparação entre iteradores (it1 != it2)
        Palavra &operator*() const;                 // acessa e retorna a Palavra (*it)
        Iterador operator++();                      // incrementa para o próximo valor maior (++it)
        Iterador operator++(int n);                 // incrementa para o próximo valor maior (it++)
        Iterador operator--();                      // decrementa para o valor anterior (--it)
        Iterador operator--(int n);                 // decrementa para o valor anterior (it--)


};

#endif