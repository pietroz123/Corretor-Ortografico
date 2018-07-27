
/*
→ Classe Arvore
- Deve ter na interface apenas os métodos:
	→ Vazia
	→ Insere
	→ Remove
	→ Busca
*/


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
        No *Inserir_Privado(No *N, Palavra P);
        void Remover();
        No* Busca(Palavra);
        void PreOrdem(No*);
        No *getPrimeiro();
        void MostraFbs(No*);
        void AtualizaFbs(No*);
        int altura(No *N);
        int Fb(No *N);
};

#endif