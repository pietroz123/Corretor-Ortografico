#include "Arvore.h"
#include "Palavra.h"

#include <stack>
#include <queue>


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
    if (Raiz == NULL)
        return true;
    else 
        return false;
}


// Funções Auxiliares para o Fator de Balanceamento (Fb = Hd - He)
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
    nFilhos++;
}


// Remoção
No *Minimo(No *N) {
    while (N->Filho_Esquerdo)
        N = N->Filho_Esquerdo;
    return N;
}
No *Remover_Privado(No *N, Palavra P) {
    if (N == NULL)
        return NULL;
    else if (P < N->P)              // vá para a sub-árvore direita
        N->Filho_Esquerdo = Remover_Privado(N->Filho_Esquerdo, P);
    else if (P > N->P)              // vá para a sub-árvore esquerda
        N->Filho_Direito = Remover_Privado(N->Filho_Direito, P);
    else {                                              // atualize os dados (dados.valor == N->dados.valor)
        if (!N->Filho_Esquerdo) {
            No *direita = N->Filho_Direito;
            free(N);
            return direita;
        }
        if (!N->Filho_Direito) {
            No *esquerda = N->Filho_Esquerdo;
            free(N);
            return esquerda;
        }
        N->P = Minimo(N->Filho_Direito)->P;
        N->Filho_Direito = Remover_Privado(N->Filho_Direito, N->P);
    }

    N->Fb = Fb(N);

    // Caso Rotação RR
    if (N->Fb > 1 && Fb(N->Filho_Direito) >= 0)
        return RotacaoRR(N);

    // Caso Rotação LL
    if (N->Fb < -1 && Fb(N->Filho_Esquerdo) <= 0)
        return RotacaoLL(N);

    // Caso Rotação LR
    if (N->Fb < -1 && Fb(N->Filho_Esquerdo) > 0)
        return RotacaoLR(N);

    // Caso Rotação RL
    if (N->Fb > 1 && Fb(N->Filho_Direito) < 0)
        return RotacaoRL(N);    

    return N;   
}
void Arvore::Remover(Palavra P) {
    Raiz = Remover_Privado(Raiz, P);
    nFilhos--;
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
void Arvore::EmOrdem(No *N) {
    if (N == NULL)  return;
    cout << N->P << " ";
    EmOrdem(N->Filho_Esquerdo);
    EmOrdem(N->Filho_Direito);
}


// Função para pegar a Raiz
No *Arvore::getPrimeiro() {
    return Arvore::Raiz;
}

