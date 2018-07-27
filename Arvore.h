
/*Bianca Gomes Rodrigues
  Pietro Zuntini Bonfim*/


#ifndef AVL_H
#define AVL_H

#include <iostream>
using namespace std;

#include "Palavra.h"

struct No {
    Palavra P;
    int Fb;
    No *Filho_Direito;
    No *Filho_Esquerdo;
    No *Pai;
};

class Arvore {

    private:
        int nFilhos;
        No *Raiz;
    
    public:
        Arvore();
        ~Arvore();
        bool Vazia();
        void Inserir(Palavra);
        void Remover();
        No* Busca(Palavra);
        void PreOrdem(No*);
        No *getPrimeiro();
        void MostraFbs(No*);
        void AtualizaFbs(No*);
};

#endif