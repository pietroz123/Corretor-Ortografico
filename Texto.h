
/*
 - Classe Texto:
    → Contém uma LISTA de Palavras;
    → Contém nome do ARQUIVO original do Texto;
    → Permite carregar um Texto a partir de um ARQUIVO;
    → Permite percorrer o texto, palavra por palavra;
    → Permite alterar uma Palavra;
    → Permite GRAVAR o Texto em um ARQUIVO (Não necessariamente o Original).
*/

#ifndef TEXTO_H
#define TEXTO_H

#include <list>
#include <fstream>

#include "Palavra.h"

class Texto {

    private:
        string Nome_Arquivo_Texto;
        list<Palavra> Palavras_Texto;

    public:
        // → Contém nome do ARQUIVO original do Texto;
        // → Permite carregar um Texto a partir de um ARQUIVO;
        void setNomeArquivo(string Nome);
        void CarregarTexto();

        void ImprimirTexto();

};


#endif 