#include "Corretor.h"

void ImprimeContexto(list<Palavra>::iterator Inicio, list<Palavra>::iterator Atual, list<Palavra>::iterator Fim) {

    list<Palavra>::iterator Anterior = prev(Atual, 1);       
    list<Palavra>::iterator Proximo = next(Atual, 1);

    if( Atual == Inicio )
        cout << "(Inexistente)" << " - " << *Atual << " - " << *Proximo << endl;
    else if (Atual == Fim )
        cout << *Anterior << " - " << *Atual << " - " << "(Inexistente)" << endl;
    else
        cout << *Anterior << " - " << *Atual << " - " << *Proximo << endl;    

}

void Corretor::Compara(Texto &T, Dicionario &D) {

    list<Palavra> TextWords = T.getPalavrasTexto();
    
    list<Palavra>::iterator it;

    for(it = TextWords.begin(); it != TextWords.end(); it++) {
    
        /*Verifica se a Palavra está no Dicionario      
        * Caso não esteja : */
        if( D.Consulta(*it) == false ) {

            // Coloca a palavra errada na lista de Erros do Corretor
            Erros.push_back(*it);
          
            // Imprime a palavra anterior e a próxima
            cout << endl << "Palavra '" << *it << "' NAO pertence ao dicionario!" << endl;
            
            cout << "Contexto da Palavra:" << endl;
  
            list<Palavra>::iterator Anterior = prev(it, 1);       
            list<Palavra>::iterator Proximo = next(it, 1);

            ImprimeContexto(TextWords.begin(), it, TextWords.end());         
            

            int Opcao;
            cout << endl << "Opcoes:" << endl; 
            cout << "(1) Corrigir" << endl << "(2) Ignorar" << endl << "(3) Selecionar uma Palavra Semelhante" << endl << "(4) Adicionar ao Dicionario" << endl;
            cout << "Opcao: ";
            cin >> Opcao;

            if (Opcao == 3) {

                // Descobrimos as palavras semelhantes
                D.setSemelhantes(*it);

                list<Palavra> Semelhante = D.getSemelhantes();                                
            
                cout << "Lista de Palavras Semelhantes: ";
                // list<Palavra>::iterator it_S;
                // for( it_S = Semelhante.begin(); it_S != Semelhante.end(); it++)
                //     cout << *it_S;
                // cout << endl;
                D.MostrarSemelhantes();

                int Resposta;
                cout << "Deseja selecionar uma Palavra Semelhante? (1) SIM (2) NAO " << endl;
                cin >> Resposta;
                if(Resposta == 1){

                    Palavra P;
                    cout << "Digite a Palavra desejada: ";
                    cin >> P;
                    *it = P;
                    cout << "Palavra Alterada!" << endl;
                                            
                }
                else {

                }

                // Acho que basicamente imprimimos a lista toda de semelhantes e o usario pode escolher selecionar uma ou nao, tipo
                // Mostra todas Semelhantes
                // Deseja selecionar uma (1) SIM (2) NAO
                // Se SIM {
                //     Qual voce quer?
                //     Digite qual voce quer
                //     cin >> P;
                //     E coloca o P na posicao da lista do texto que a o iterador esta apontando
                //     Acho que eh isso ne amor?
                // }
                                                                            
                
            }
        }
    }
}
