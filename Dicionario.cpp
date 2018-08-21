
/* Dicionario.cpp
*
*  Número do Grupo: 9
*  Membros:
*    → Bianca Gomes Rodrigues    RA: 743512
*    → Pietro Zuntini Bonfim     RA: 743588
*
*  Contém as implementações da classe Dicionario
*/

#include "Dicionario.h"

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
    Palavras_Do_Dicionario.EmOrdem();
    cout << endl;
}


// → Consulta de palavras
bool Dicionario::Consulta(Palavra &P) {
    return Palavras_Do_Dicionario.Busca(P) != false;
}


// → Inclusão de palavras
void Dicionario::InserirPalavra(Palavra &P) {
    Palavras_Do_Dicionario.Inserir(P);
}


// → Fornecer uma LISTA de palavras semelhantes à determinada palavra (palavras semelhantes começam com as duas mesmas letras)
void Dicionario::setSemelhantes(Palavra &P) {
    Semelhantes.clear(); // A cada chamada da função setSemelhantes, esvaziamos a lista de Semelhantes
    Iterador it = Palavras_Do_Dicionario.begin();
    while (it != Palavras_Do_Dicionario.end() && !(*it).Semelhante(P))
        it++;
    while (it != Palavras_Do_Dicionario.end() && (*it).Semelhante(P)) {
        Semelhantes.push_back(*it);
        it++;
    }
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

bool Dicionario::ConsultaSemelhantes(Palavra &P) {
    for (list<Palavra>::iterator it = Semelhantes.begin(); it != Semelhantes.end(); it++)
        if (*it == P)
            return true;
    return false;
}



// → Gravar Dicionario Original
void Dicionario::GravarDicionario() {

    ofstream Original;
    Original.open("dic.txt", ofstream::out);

    // A função GravarDicionario itera pela árvore do Dicionário Em-Ordem, e coloca no Arquivo Original (dic.txt)
    for (Iterador it = Palavras_Do_Dicionario.begin(); it != Palavras_Do_Dicionario.end(); it++)
        Original << *it << endl;

    Original.close();

}