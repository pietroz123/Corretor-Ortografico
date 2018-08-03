
/*
→ Classe Dicionário (contém palavras)
- Contém até 10000 palavras
- Armazena as palavras do arquivo “dict.txt”
- Deve permitir:
	→ Consulta de palavras
	→ Inclusão de palavras
	→ Fornecer uma LISTA de palavras semelhantes à determinada palavra (palavras semelhantes começam com as duas mesmas letras)
- O relacionamento entre as classes Dicionário e Palavra deve ser feito por uma árvore balanceada (AVL)
*/

#ifndef DICIONARIO_H
#define DICIONARIO_H

#include "Arvore.h"
#include <fstream>
#include <list>

class Dicionario{

    private:
        Arvore Palavras_Do_Dicionario;
        list<Palavra> Semelhantes;

    public:
        // → Armazena as palavras do arquivo “dict.txt” em uma árvore balanceada
        void InserirPalavras(ifstream &arquivo);
        void ImprimirPalavras();
    
        // → Consulta de palavras
        bool Consulta(Palavra &P);

        // → Inclusão de palavras
        void InserirPalavra(Palavra &P);

        // → Fornecer uma LISTA de palavras semelhantes à determinada palavra (palavras semelhantes começam com as duas mesmas letras)
        void setSemelhantes(Palavra &P);
        void setSemelhantes_Privado(No *N, Palavra &P);
        void MostrarSemelhantes();

        // Funções Auxiliares
        list<Palavra> getSemelhantes();
        void GravarDicionario();
};


#endif 