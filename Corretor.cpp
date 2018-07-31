#include "Corretor.h"

void ImprimeContexto(list<Palavra>::iterator Inicio, list<Palavra>::iterator Atual, list<Palavra>::iterator Fim) {

    list<Palavra>::iterator Anterior = prev(Atual, 1);       
    list<Palavra>::iterator Proximo = next(Atual, 1);

    if( Atual == Inicio )
        cout << "NULL" << " - " << *Atual << " - " << *Proximo << endl;
    else if (Atual == Fim )
        cout << *Anterior << " - " << *Atual << " - " << "NULL" << endl;
    else
        cout << *Anterior << " - " << *Atual << " - " << *Proximo << endl;    


}
void Corretor::Compara(Texto &T, Dicionario &D) {

    list<Palavra> TextWords = T.getPalavrasTexto();
    
    list<Palavra>::iterator it;

    for(it = TextWords.begin(); it != TextWords.end(); it++) {
    
        //Verifica se a Palavra está no Dicionario                         
        if( D.Consulta(*it) == false ) {
            
            cout << "Palavra '" << *it << "' nao pertence ao dicionario!" << endl;
            cout << "Contexto da Palavra:" << endl;
  
            list<Palavra>::iterator Anterior = prev(it, 1);       
            list<Palavra>::iterator Proximo = next(it, 1);

            ImprimeContexto(TextWords.begin(), it, TextWords.end());         
            

            // Coloca a palavra errada na lista de Erros do Corretor
            Erros.push_back(*it);

            int Opcao;
            cout << "Palavra encontrada no Dicionario!" << endl;
            cout << "Opcoes:" << endl; 
            cout << "(1) Corrigir" << endl << "(2) Ignorar" << endl << "(3) Selecionar uma Palavra Semelhante" << endl << "(4) Adicionar ao Dicionario" << endl;
            cin >> Opcao;


        }
        

    }

}
