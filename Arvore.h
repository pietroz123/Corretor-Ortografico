
/* Arvore.h 
*
*  Número do Grupo: 9
*  Membros:
*    → Bianca Gomes Rodrigues    RA: 743512
*    → Pietro Zuntini Bonfim     RA: 743588
*
* → Classe Arvore
* - Deve ter na interface apenas os métodos:
*	→ Vazia
*	→ Insere
*	→ Remove
*	→ Busca
*/


#ifndef AVL_H
#define AVL_H

#include <iostream>
using namespace std;

#include "Palavra.h"
#include "No.h"
#include <list>
#include <fstream>


class Arvore {

    private:
        int nFilhos;
        No *Raiz;
    
    public:
        Arvore();
        ~Arvore();
        bool Vazia();
        void Inserir(Palavra);
        void Remover(Palavra);
        bool Busca(Palavra);
        void EmOrdem();
        void Busca_Semelhante(list<Palavra> &, Palavra);
        void GravarArvore(ofstream &);
        
};

#endif