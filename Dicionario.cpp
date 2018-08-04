
/* Número do Grupo: 9
*  Membros:
*    → Bianca Gomes Rodrigues    RA: 743512
*    → Pietro Zuntini Bonfim     RA: 743588
*/

#include "Dicionario.h"
#include <vector>
#include <stack>

// → Armazena as palavras do arquivo “dict.txt” em uma árvore balanceada
void Dicionario::InserirPalavras(ifstream &arquivo) {

    Palavra temp;
    
    // Coloca todas as Palavras do arquivo na Árvore do Dicionário
    while (arquivo >> temp)
        Palavras_Do_Dicionario.Inserir(temp);
    
    arquivo.close();

}

// → Imprime as Palavras do Dicionário Em-Ordem
void Dicionario::ImprimirPalavras() {
    cout << "Imprimindo arvore..." << endl;
    Palavras_Do_Dicionario.EmOrdem(Palavras_Do_Dicionario.getPrimeiro());
    cout << endl;
}


// → Consulta de palavras
bool Dicionario::Consulta(Palavra &P) {
    return Palavras_Do_Dicionario.Busca(P) != NULL;
}


// → Inclusão de palavras
void Dicionario::InserirPalavra(Palavra &P) {
    Palavras_Do_Dicionario.Inserir(P);
}


// → Fornecer uma LISTA de palavras semelhantes à determinada palavra (palavras semelhantes começam com as duas mesmas letras)
void setSemelhantes_Privado(list<Palavra> &Semelhantes, No *N, Palavra &P) {
    if (N == NULL)  return;
    if ((N->P).Semelhante(P)) { // Se a Palavra em N (N->P) for semelhante a Palavra, a colocamos na Lista de Semelhantes
        Semelhantes.push_back(N->P);
    }
    setSemelhantes_Privado(Semelhantes, N->Filho_Esquerdo, P);
    setSemelhantes_Privado(Semelhantes, N->Filho_Direito, P);
}
void Dicionario::setSemelhantes(Palavra &P) {
    Semelhantes.clear(); // A cada chamada da função setSemelhantes, esvaziamos a lista de Semelhantes
    setSemelhantes_Privado(Semelhantes, Palavras_Do_Dicionario.getPrimeiro(), P);
}

// Método Get que retorna a lista de Semelhantes
list<Palavra> Dicionario::getSemelhantes(){
    return Semelhantes;    
}


// → Função para mostrar todas as Palavras Semelhantes
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


// → Gravar Dicionario Original
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

    // A função GravarDicionario utiliza uma função Auxiliar que itera pela árvore do Dicionário Em-Ordem, e coloca no Arquivo Original (dic.txt)
    IterarDicionario_EmOrdem(Palavras_Do_Dicionario.getPrimeiro(), Original);

    Original.close();

}