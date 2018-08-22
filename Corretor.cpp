
/* Corretor.cpp
*
*  Número do Grupo: 9
*  Membros:
*    → Bianca Gomes Rodrigues    RA: 743512
*    → Pietro Zuntini Bonfim     RA: 743588
*
*  Contém as implementações da classe Corretor
*/

#include "Corretor.h"
#include <string>
#include <algorithm>

void Finalizar(list<Palavra> &TextWords, Corretor &C, Texto &T, Dicionario &D) {

    T.setPalavrasTexto(TextWords);
    C.GravarErros();
    
    int Opcao = -1;
    while(Opcao != 2){
        cout << endl;
        cout << "Deseja gravar o texto em um arquivo diferente?" << endl << "\t(1) SIM" << endl << "\t(2) NAO" << endl;
        cin >> Opcao;
        if (Opcao == 1){
            T.GravarTextoDiferente();
            cout << "Texto gravado com sucesso!" << endl;
        }
    }

    cout << "Gravando Arquivo Texto Original..." << endl;
    T.GravarTextoOriginal();
    cout << "Gravando Dicionario..." << endl;
    D.GravarDicionario();

}

void ImprimeContexto(list<Palavra>::iterator Inicio, list<Palavra>::iterator Atual, list<Palavra>::iterator Fim) {

    list<Palavra>::iterator Anterior = prev(Atual, 1);       
    list<Palavra>::iterator Proximo = next(Atual, 1);

    Fim = prev(Fim, 1);

    if(Atual == Inicio)
        cout << "(Inexistente)" << " - " << *Atual << " - " << *Proximo << endl;
    else if (Atual == Fim)
        cout << *Anterior << " - " << *Atual << " - " << "(Inexistente)" << endl;
    else
        cout << *Anterior << " - " << *Atual << " - " << *Proximo << endl;    

}

void InicializaTexto(Texto &T) {

    int flag = false;
    while (flag == false) {
        flag = true;
        try {
            T.CarregarTexto();
            cout << "Arquivo carregado com sucesso!" << endl;
        }
        catch (const char *s) {
            cout << s << endl;
            flag = false;
        }
    }

}
void InicializaDicionario(Dicionario &D) {

    ifstream Arquivo_Dicionario("dic.txt");
    cout << "Inserindo palavras..." << endl;
    D.InserirPalavras(Arquivo_Dicionario);

}

// Remove a pontuação de uma Palavra e retorna uma nova string
string RemovePontuacao(Palavra P) {

    string palavra = P.getPalavra();

    for (int i = palavra.size() - 1; i > 0; i--) {
        if (ispunct(palavra[i])) {
            if (palavra[i] == '-')  // cuida do caso de Palavras com hífen, como louva-a-Deus
                return palavra;
            palavra.erase(i--, 1);
        }
    }

    return palavra;
}

bool ExistePontuacao(Palavra P, char &c) {
    
    string Word = P.getPalavra();

    for (int i = 0; i < Word.size(); i++)
        if (ispunct(Word[i])) {
            c = Word[i];
            return true;
        }

    return false;
}

void Corretor::Compara() {

    InicializaDicionario(D);
    InicializaTexto(T);

    list<Palavra> TextWords = T.getPalavrasTexto();
    list<Palavra>::iterator it;


    for(it = TextWords.begin(); it != TextWords.end(); it++) {
        
        // Converte a string presente na Palavra do iterador para letras minúsculas 
        std::string palavra = (*it).getPalavra();
        std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
        (*it).setPalavra(palavra);

        Palavra Temp(RemovePontuacao(*it));
        char c;

        // Verifica se a Palavra está no Dicionario      
        // Caso não esteja: 
        if( D.Consulta(Temp) == false ) {

            int Opcao;

            // Coloca a palavra errada na lista de Erros do Corretor
            Erros.push_back(Temp);

            cout << endl << "Palavra '" << Temp << "' NAO pertence ao dicionario!" << endl;
            
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
                
                    Finalizar(TextWords, *this, T, D);
                    return;
                
                    break;
                }

                case 1: {

                    Palavra P2;
                    cout << "Digite a Palavra desejada: ";
                    cin >> P2;
                    
                    if (ExistePontuacao(*it, c)) {
                        (*it).setPalavra(P2.getPalavra() += c);
                    }
                    else {
                        T.AlterarPalavra(it, P2);
                    }
                    
                    cout << "Palavra alterada com sucesso!" << endl;
                    
                    break;
                }
                
                case 2: {
                
                    cout << "Palavra ignorada" << endl;
                
                    break;
                }
                
                case 3: {

                    D.setSemelhantes(Temp); // Descobrimos as palavras semelhantes
                
                    cout << "Lista de Palavras Semelhantes: ";
                    D.MostrarSemelhantes();

                    int Resposta;
                    cout << endl << "Deseja selecionar uma Palavra Semelhante?" << endl << "\t(1) SIM" << endl << "\t(2) NAO" << endl;
                    cin >> Resposta;
                    
                    if (Resposta == 1) {
                        Palavra P2;
                        cout << "Digite a Palavra desejada: ";
                        cin >> P2;
                        try {
                            if (!D.ConsultaSemelhantes(P2))
                                throw 0;
                            else { 
                                if (ExistePontuacao(*it, c)) {
                                    (*it).setPalavra(P2.getPalavra() += c);
                                }
                                else {
                                    T.AlterarPalavra(it, P2);
                                }
                                cout << "Palavra alterada com sucesso!" << endl;
                            }            
                        }
                        catch (int Erro) {
                            if (Erro == 0)
                               cout << "Palavra nao disponivel na lista de semelhanca!" << endl;
                        }

                    }
                
                    break;
                }
                
                case 4: {
                
                    D.InserirPalavra(Temp);
                    cout << "Palavra Adicionada!" << endl;                   
                
                    break;
                }
                
                default: {
                    cout << "Digite uma opcao valida!" << endl;
                    break;
                }
            }
        }
    }

    Finalizar(TextWords, *this, T, D);

}



int BuscaErro(Palavra &P, list<Palavra> &Erros){
    int Contador = 0;
    list<Palavra>::iterator it;
    for(it = Erros.begin(); it != Erros.end(); it++){
        if(*it == P){
            Contador++;
            Erros.erase(it);
        }

    }

    return Contador;

}

void Corretor::GravarErros() {

    ofstream Original;
    Original.open("Erros.txt", ofstream::out);

    int i;
    
    list<Palavra>::iterator it;
    
    for(it = Erros.begin(); it != Erros.end(); it++){
        i = BuscaErro(*it, Erros);
        Original << "Erro: " << *it << endl << "Numero de vezes: " << i << endl << endl;
    }

    Original.close();
}
