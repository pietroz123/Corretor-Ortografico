#include "No.h"

No::No(Palavra P) {
    this->P = P;
    this->Fb = 0;
    this->Filho_Esquerdo = NULL;
    this->Filho_Direito = NULL;
    this->Pai = NULL;
}

No::~No() {
    if (this->Filho_Esquerdo)
        delete this->Filho_Esquerdo;
    if (this->Filho_Direito)
        delete this->Filho_Direito;
}