
/* Número do Grupo: 9
*  Membros:
*    → Bianca Gomes Rodrigues    RA: 743512
*    → Pietro Zuntini Bonfim     RA: 743588
*
* → Classe Corretor (contém um dicionário, um texto e a lista de palavras erradas)
* → Desenvolver um CORRETOR ORTOGRÁFICO, que permita verificação de erros em um TEXTO comparando cada palavra do texto com um DICIONÁRIO
* → Se o corretor encontrar uma palavra que não pertença ao dicionário, será possível:
*	1. Corrigir a palavra
*	2. Ignorar o erro
*	3. Selecionar uma palavra a partir de uma lista de palavras semelhantes
*	4. Adicionar a palavra ao dicionário
* → Ao encontrar uma palavra que não pertença ao dicionário, deverá ser apresentado também a palavra anterior e próxima do texto
* → Todos os erros devem ser armazenados em uma lista de erros (corrigidos ou não) uma única vez, com o número de vezes que o erro ocorreu 
*/

#ifndef CORRETOR_H
#define CORRETOR_H

#include "Texto.h"
#include "Dicionario.h"

class Corretor {

    private:
		list<Palavra> Erros;

    public:
		void Compara(Texto &T, Dicionario &D);


};


#endif 