/*Bianca Gomes Rodrigues
  Pietro Zuntini Bonfim*/

#include "Arvore.h"

#include <stack>
#include <queue>

#include "Palavra.h"

// Construtor
Arvore::Arvore() {
    Arvore::Raiz = NULL;
    Arvore::nFilhos = 0;
}

// Destrutor
void Destrutor_Privado(No *N) {
    if (N == NULL)  return;
    Destrutor_Privado(N->Filho_Esquerdo);
    Destrutor_Privado(N->Filho_Direito);
    delete N;
}
Arvore::~Arvore() {
    cout << "Entrou no destrutor" << endl;
    Destrutor_Privado(Raiz);
}

// Vazia
bool Arvore::Vazia() {
    if (nFilhos == 0)
        return true;
    else 
        return false;
}

// Funções Auxiliares para o Fator de Balanceamento (Fb = Hd - He)
void Arvore::MostraFbs(No *N) {
    if (N == NULL)  return;
    cout << N->P.getPalavra() << " = " << N->Fb << endl;
    MostraFbs(N->Filho_Esquerdo);
    MostraFbs(N->Filho_Direito);
}
int altura(No *N) {
    if (N == NULL)  return 0;
    int He = altura(N->Filho_Esquerdo); // He = Altura Esquerda
    int Hd = altura(N->Filho_Direito);  // Hd = Altura Direita
    if (Hd > He)
        return Hd + 1;
    else
        return He + 1;
}
int Fb(No *N) {
    return altura(N->Filho_Direito) - altura(N->Filho_Esquerdo);
}
void Arvore::AtualizaFbs(No *N) {
    if (N == NULL)  return;
    N->Fb = Fb(N);
    AtualizaFbs(N->Filho_Esquerdo);
    AtualizaFbs(N->Filho_Direito);
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
    
    return C;
}
No *RotacaoLL(No *A) {
    No *B = A->Filho_Esquerdo;
    No *h2 = B->Filho_Direito;

    B->Filho_Direito= A;
    A->Filho_Esquerdo= h2;

    return B;    
}
No *RotacaoRR(No *A) {
    No *B = A->Filho_Direito; 
    No *h2 = B->Filho_Esquerdo;

    B->Filho_Esquerdo = A;
    A->Filho_Direito = h2;

    return B;
}
// Inserção
No *Inserir_Privado(No *N, Palavra P) {
    if (N == NULL) {
        No *Novo = new No;
        Novo->Filho_Esquerdo = Novo->Filho_Direito = NULL;
        Novo->P = P;
        return Novo;
    }
    else if (P > N->P)
        N->Filho_Direito = Inserir_Privado(N->Filho_Direito, P);
    else if (P < N->P)
        N->Filho_Esquerdo = Inserir_Privado(N->Filho_Esquerdo, P);
    else
        return N;

    N->Fb = Fb(N);

    // if(N->Fb > 1)
    //     if(P > N->Filho_Direito->P)
    //         return RotacaoRR(N);
    //     else 
    //         return RotacaoRL(N);
    
    // else if(N->Fb < -1)
    //     if(P < N->Filho_Esquerdo->P)
    //         return RotacaoLL(N);
    //     else 
    //         return RotacaoLR(N);                                                    

    // Caso Rotação à Esquerda (RR)
    if (N->Fb > 1 && P > N->Filho_Direito->P)
        return RotacaoRR(N);

    // Caso Rotação à Direita (LL)
    if (N->Fb < -1 && P < N->Filho_Esquerdo->P)
        return RotacaoLL(N);

    // Caso Rotação à Esquerda e à Direita (LR)
    if (N->Fb < -1 && P > N->Filho_Esquerdo->P)
        return RotacaoLR(N);

    // Caso Rotação à Direita e à Esquerda (RL)
    if (N->Fb > 1 && P < N->Filho_Direito->P)
        return RotacaoRL(N);

    return N;
}
void Arvore::Inserir(Palavra P) {
    Raiz = Inserir_Privado(Raiz, P);
}


// Remoção
void Arvore::Remover() {

}


// Busca
No *Arvore::Busca(Palavra P) {
    No *Atual = Raiz;
    while (Atual) {
        if (P == Atual->P)
            return Atual;
        else if (P > Atual->P)
            Atual = Atual ->Filho_Direito;
        else if (P < Atual->P)
            Atual = Atual->Filho_Esquerdo;
    }
    return NULL;
}


// Percurso
void Arvore::PreOrdem(No *N) {
    if (N == NULL)  return;
    cout << N->P.getPalavra() << " ";
    PreOrdem(N->Filho_Esquerdo);
    PreOrdem(N->Filho_Direito);
}


// Função para pegar a Raiz
No *Arvore::getPrimeiro() {
    return Arvore::Raiz;
}

