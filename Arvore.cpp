
/* Arvore.cpp 
*
*  Número do Grupo: 9
*  Membros:
*    → Bianca Gomes Rodrigues    RA: 743512
*    → Pietro Zuntini Bonfim     RA: 743588
*
*  Contém as implementações da classe Arvore
*/

#include "Arvore.h"
#include "Palavra.h"


// Construtor
Arvore::Arvore() {
    Arvore::Raiz = NULL;
    Arvore::nFilhos = 0;
}
// Destrutor
Arvore::~Arvore() {
    delete Raiz;
}


// Vazia
bool Arvore::Vazia() {
    if (Raiz == NULL)
        return true;
    else 
        return false;
}


// Funções Auxiliares para o Fator de Balanceamento (Fb = Hd - He)
int altura(No *no) {
    if (no == NULL)  return 0;
    int He = altura(no->Filho_Esquerdo); // He = Altura Esquerda
    int Hd = altura(no->Filho_Direito);  // Hd = Altura Direita
    if (Hd > He)
        return Hd + 1;
    else
        return He + 1;
}
int Fb(No *no) {
    return altura(no->Filho_Direito) - altura(no->Filho_Esquerdo);
}


// Rotações
No *RotacaoRL(No *A) {
    No *B = A->Filho_Direito;
    No *C = B->Filho_Esquerdo;
    No *h2 = C->Filho_Esquerdo;
    No *h3 = C->Filho_Direito;

    C->Filho_Esquerdo = A;
    C->Filho_Direito = B;    
    B->Filho_Esquerdo = h3;
    A->Filho_Direito = h2;

    C->Pai = A->Pai;
    B->Pai = C;
    A->Pai = C;
    if (h2)
        h2->Pai = A;
    if (h3)
        h3->Pai = B; 

    return C;   
}
No *RotacaoLR(No *A) {
    No *B = A->Filho_Esquerdo;
    No *C = B->Filho_Direito;
    No *h2 = C->Filho_Esquerdo;
    No *h3 = C->Filho_Direito;

    C->Filho_Esquerdo = B;
    C->Filho_Direito = A;
    B->Filho_Direito = h2;
    A->Filho_Esquerdo = h3;

    C->Pai = A->Pai;
    A->Pai = C;
    B->Pai = C;
    if (h2)
        h2->Pai = B;
    if (h3)
    h3->Pai = A;

    return C;
}
No *RotacaoLL(No *A) {
    No *B = A->Filho_Esquerdo;
    No *h2 = B->Filho_Direito;

    B->Filho_Direito= A;
    A->Filho_Esquerdo= h2;

    B->Pai = A->Pai;
    A->Pai = B;
    if (h2)
        h2->Pai = A;

    return B;    
}
No *RotacaoRR(No *A) {
    No *B = A->Filho_Direito; 
    No *h2 = B->Filho_Esquerdo;

    B->Filho_Esquerdo = A;
    A->Filho_Direito = h2;

    B->Pai = A->Pai;
    A->Pai = B;
    if (h2)
        h2->Pai = A;

    return B;
}
// Inserção
No *Inserir_Privado(No *no, Palavra P) {
    if (no == NULL) {
        return new No(P);
    }
    else if (P > no->P) {
        No *direito = Inserir_Privado(no->Filho_Direito, P);
        no->Filho_Direito = direito;
        direito->Pai = no;
    }
    else if (P < no->P) {
        No *esquerdo = Inserir_Privado(no->Filho_Esquerdo, P);
        no->Filho_Esquerdo = esquerdo;
        esquerdo->Pai = no;
    }
    else
        return no;

    no->Fb = Fb(no);                                                

    // Caso Rotação à Esquerda (RR)
    if (no->Fb > 1 && P > no->Filho_Direito->P)
        return RotacaoRR(no);

    // Caso Rotação à Direita (LL)
    if (no->Fb < -1 && P < no->Filho_Esquerdo->P)
        return RotacaoLL(no);

    // Caso Rotação à Esquerda e à Direita (LR)
    if (no->Fb < -1 && P > no->Filho_Esquerdo->P)
        return RotacaoLR(no);

    // Caso Rotação à Direita e à Esquerda (RL)
    if (no->Fb > 1 && P < no->Filho_Direito->P)
        return RotacaoRL(no);

    return no;
}
void Arvore::Inserir(Palavra P) {
    Raiz = Inserir_Privado(Raiz, P);
    nFilhos++;
}


// Remoção
No *Minimo(No *no) {
    while (no->Filho_Esquerdo)
        no = no->Filho_Esquerdo;
    return no;
}
No *Remover_Privado(No *no, Palavra P) {
    if (no == NULL)
        return NULL;
    else if (P < no->P)              // vá para a sub-árvore direita
        no->Filho_Esquerdo = Remover_Privado(no->Filho_Esquerdo, P);
    else if (P > no->P)              // vá para a sub-árvore esquerda
        no->Filho_Direito = Remover_Privado(no->Filho_Direito, P);
    else {                                              // atualize os dados (dados.valor == no->dados.valor)
        if (!no->Filho_Esquerdo) {
            No *direita = no->Filho_Direito;
            free(no);
            return direita;
        }
        if (!no->Filho_Direito) {
            No *esquerda = no->Filho_Esquerdo;
            free(no);
            return esquerda;
        }
        no->P = Minimo(no->Filho_Direito)->P;
        no->Filho_Direito = Remover_Privado(no->Filho_Direito, no->P);
    }

    no->Fb = Fb(no);

    // Caso Rotação RR
    if (no->Fb > 1 && Fb(no->Filho_Direito) >= 0)
        return RotacaoRR(no);

    // Caso Rotação LL
    if (no->Fb < -1 && Fb(no->Filho_Esquerdo) <= 0)
        return RotacaoLL(no);

    // Caso Rotação LR
    if (no->Fb < -1 && Fb(no->Filho_Esquerdo) > 0)
        return RotacaoLR(no);

    // Caso Rotação RL
    if (no->Fb > 1 && Fb(no->Filho_Direito) < 0)
        return RotacaoRL(no);    

    return no;   
}
void Arvore::Remover(Palavra P) {
    Raiz = Remover_Privado(Raiz, P);
    nFilhos--;
}


// Busca
bool Arvore::Busca(Palavra P) {
    No *Atual = Raiz;
    while (Atual) {
        if (P == Atual->P)
            return true;
        else if (P > Atual->P)
            Atual = Atual ->Filho_Direito;
        else if (P < Atual->P)
            Atual = Atual->Filho_Esquerdo;
    }
    return false;
}


// Percurso
void EmOrdem_Privado(No *no) {
    if (no == NULL)  return;
    EmOrdem_Privado(no->Filho_Esquerdo);
    cout << no->P << " ";
    EmOrdem_Privado(no->Filho_Direito);
}
void Arvore::EmOrdem() {
    EmOrdem_Privado(Raiz);
}


//deletaar
void MostraPais_Privado(No *N) {
    if (N == NULL)  return;
    MostraPais_Privado(N->Filho_Esquerdo);
    cout << N->P << " - Pai: ";
    if (N->Pai)
        cout << N->Pai->P << endl;
    else
        cout << "NULL" << endl;
    MostraPais_Privado(N->Filho_Direito);

}
void Arvore::MostraPais() {
    MostraPais_Privado(Raiz);
}

// Iterador
Iterador Arvore::begin() const {
    No *Atual = Raiz;
    while (Atual->Filho_Esquerdo)
        Atual = Atual->Filho_Esquerdo;
    return Iterador(Atual);
}

Iterador Arvore::end() const {
    return Iterador(NULL);
}


Iterador Arvore::rbegin() const {
    No *Atual = Raiz;
    while (Atual->Filho_Direito)
        Atual = Atual->Filho_Direito;
    return Iterador(Atual);
}

Iterador Arvore::rend() const {
    return Iterador(NULL);
}