#include "Dicionario.h"
#include <vector>
#include <stack>


void Dicionario::InserirPalavras(ifstream &arquivo) {

    Palavra temp;
    
    while (arquivo >> temp)
        Palavras_Do_Dicionario.Inserir(temp);
    
    arquivo.close();

}

list<Palavra> Dicionario::getSemelhantes(){
    return Semelhantes;    
}


void Dicionario::ImprimirPalavras() {
    cout << "Imprimindo arvore..." << endl;
    Palavras_Do_Dicionario.PreOrdem(Palavras_Do_Dicionario.getPrimeiro());
    cout << endl;
}


bool Dicionario::Consulta(Palavra &P) {
    return Palavras_Do_Dicionario.Busca(P) != NULL;
}


void Dicionario::InserirPalavra(Palavra &P) {
    Palavras_Do_Dicionario.Inserir(P);
}



void Dicionario::setSemelhantes_Privado(No *N, Palavra &P) {
    if (N == NULL)  return;
    if ((N->P).Semelhante(P)) {
        Semelhantes.push_back(N->P);
    }
    setSemelhantes_Privado(N->Filho_Esquerdo, P);
    setSemelhantes_Privado(N->Filho_Direito, P);
}
void Dicionario::setSemelhantes(Palavra &P) {
    Dicionario::setSemelhantes_Privado(Palavras_Do_Dicionario.getPrimeiro(), P);
}
// Passar a Palavra e a Lista???

void Dicionario::MostrarSemelhantes() {

    if (Palavras_Do_Dicionario.Vazia()) {
        cout << "Nao foram inseridas palavras no Dicionario!" << endl;
        return;
    }

    list<Palavra>::iterator it;
    for (it = Semelhantes.begin(); it != Semelhantes.end(); it++)
        cout << *it << " ";

    cout << endl;

}

void IterarDicionario_EmOrdem(No *Raiz, ofstream &Original) {
    
    if (Raiz == NULL)   return;

    stack<No*> s;

    No *Atual = Raiz;
    while ( !s.empty() || Atual != NULL) {

        while (Atual != NULL) {
            s.push(Atual);
            Atual = Atual->Filho_Esquerdo;
        }

        Atual = s.top();
        Original << Atual->P << endl;
        s.pop();
        Atual = Atual->Filho_Direito;

    }

}
void Dicionario::GravarDicionario() {

    ofstream Original;
    Original.open("dic.txt", ofstream::out);

    IterarDicionario_EmOrdem(Palavras_Do_Dicionario.getPrimeiro(), Original);

    Original.close();

}