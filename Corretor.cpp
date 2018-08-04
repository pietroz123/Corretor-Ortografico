
/* Número do Grupo: 9
*  Membros:
*    → Bianca Gomes Rodrigues    RA: 743512
*    → Pietro Zuntini Bonfim     RA: 743588
*/

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
    
        // Verifica se a Palavra está no Dicionario      
        // Caso não esteja: 
        if( D.Consulta(*it) == false ) {

            int Opcao;

            // Coloca a palavra errada na lista de Erros do Corretor
            Erros.push_back(*it);

            cout << endl << "Palavra '" << *it << "' NAO pertence ao dicionario!" << endl;
            
            // Imprime o Contexto da palavra (anterior - atual - próxima)
            cout << "Contexto da Palavra:" << endl;
            ImprimeContexto(TextWords.begin(), it, TextWords.end());         

            cout << endl << "Digite uma opcao:" << endl; 
            cout << "\t(0) Sair" << endl;
            cout << "\t(1) Corrigir" << endl;
            cout << "\t(2) Ignorar" << endl;
            cout << "\t(3) Selecionar uma Palavra Semelhante" << endl;
            cout << "\t(4) Adicionar ao Dicionario" << endl;
            cout << "Opcao: ";
            cin >> Opcao;

            switch(Opcao) {

                case 0: {
                    T.setPalavrasTexto(TextWords);
                    return;
                    break;
                }
                case 1: {
                    T.AlterarPalavra(it);
                    cout << "Palavra alterada com sucesso!" << endl;
                    break;
                }
                case 2: {
                    cout << "Palavra ignorada" << endl;
                    break;
                }
                case 3: {

                    D.setSemelhantes(*it); // Descobrimos as palavras semelhantes
                
                    cout << "Lista de Palavras Semelhantes: ";
                    D.MostrarSemelhantes();

                    int Resposta;
                    cout << "Deseja selecionar uma Palavra Semelhante?" << endl << "(1) SIM" << endl << "(2) NAO" << endl;
                    cin >> Resposta;
                    
                    if(Resposta == 1) {
                        T.AlterarPalavra(it);
                        cout << "Palavra alterada com sucesso!" << endl;
                    }
                    break;
                }
                case 4: {
                    D.InserirPalavra(*it);
                    cout << "Palavra Adicionada!" << endl;                   
                    break;
                }
            }
        }
    }
    
}
