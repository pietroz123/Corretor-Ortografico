#include "Iterador.h"

Iterador::Iterador(No *raiz) : Atual(raiz) { }

No *Minimo(No *N) {
    while (N->Filho_Esquerdo)
        N = N->Filho_Esquerdo;
    return N;
}
No *Iterador::SucessorEmOrdem(No *N) {
    if (N == NULL)  return NULL;

    if (N->Filho_Direito)
        return Minimo(N->Filho_Direito);

    else {
        No *Ancestral = N->Pai;
        while (Ancestral) {
            if (Atual == Ancestral->Filho_Esquerdo)
                return Ancestral;
            else if (Atual == Ancestral->Filho_Direito) {
                Atual = Ancestral;
                Ancestral = Ancestral->Pai;
            }
        }
    }
    return NULL;
}

bool Iterador::operator==(const Iterador &it) {

}

bool Iterador::operator!=(const Iterador &Outro) {

}

Palavra &Iterador::operator*() const {
    return Atual->P;
}

Iterador Iterador::operator++() {
    Atual = SucessorEmOrdem(Atual);
    return Iterador(Atual);
}

Iterador Iterador::operator++(int n) {

}

Iterador Iterador::operator--() {

}

Iterador Iterador::operator--(int n) {

}