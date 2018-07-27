
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
        Arvore Palavras_Do_Arquivo;
        list<Palavra> Semelhantes;

    public:
        void InserirPalavras(ifstream &arquivo);
        void ImprimirPalavras();
        void setSemelhantes(Palavra &P);
        void setSemelhantes_Privado(No *N, Palavra &P);
        void MostrarSemelhantes();

};


#endif 