
/* Número do Grupo: 9
*  Membros:
*    → Bianca Gomes Rodrigues    RA: 743512
*    → Pietro Zuntini Bonfim     RA: 743588
*/

#include <iostream>
using namespace std;

#include "Corretor.h"
#include <string>

#define SAIR            0
#define COMPARAR        1
#define DICIONARIO      2
#define TEXTO           3

int main() {

    Corretor C;
    Dicionario D;
    Texto T;

    ifstream Arquivo_Dicionario("dic.txt");
    cout << "Inserindo palavras..." << endl;
    D.InserirPalavras(Arquivo_Dicionario);

    T.CarregarTexto();


    int Opcao = -1;


    while (Opcao != SAIR) { // 0

        cout << endl;
        cout << "Digite uma opcao do Corretor:" << endl;
        cout << "\t(0) Sair" << endl;
        cout << "\t(1) Comparar Texto e Dicionario" << endl;
        cout << "\t(2) Gerenciar Dicionario" << endl;
        cout << "\t(3) Gerenciar Texto" << endl;        
        
        cout << "Opcao (Corretor): ";
        cin >> Opcao;


        switch(Opcao) {

            case COMPARAR: { // 1
                cout << "Comparando Texto e Dicionario..." << endl;
                C.Compara(T, D);
                break;
            }
            case DICIONARIO: { //2
   
                int Opcao_Dicionario = -1;
                
                while(Opcao_Dicionario != SAIR) {

                    cout << endl;
                    cout << "Digite uma opcao do Dicionario:" << endl;
                    cout << "\t(0) Sair" << endl;        
                    cout << "\t(1) Imprimir Dicionario" << endl;
                    cout << "\t(2) Buscar Palavra no Dicionario" << endl;

                    cout << "Opcao (Dicionario): ";
                    cin >> Opcao_Dicionario;
                    
                    switch(Opcao_Dicionario) {

                        case 1: { // IMPRIMIR
                            cout << "Imprimindo palavras..." << endl;
                            D.ImprimirPalavras();
                            break;
                        }
                        case 2: { // BUSCAR

                            Palavra B;
                            cout << "Digite a palavra a ser procurada: ";
                            cin >> B;

                            if (D.Consulta(B))
                                cout << "Palavra '" << B << "' encontrada!" << endl;
                            else
                                cout << "Palavra '" << B << "' NAO encontrada!" << endl;

                            break;
                        }               
                    }
                }
                break;
            }
            case TEXTO: { // 3
                
                int Opcao_Texto = -1;

                while (Opcao_Texto != 0) {
                    
                    cout << endl;
                    cout << "Digite uma opcao do Texto:" << endl;
                    cout << "\t(0) Sair" << endl;        
                    cout << "\t(1) Imprimir Texto" << endl;
                    cout << "\t(2) Buscar Palavra no Texto" << endl;

                    cout << "Opcao (Texto): ";
                    cin >> Opcao_Texto;

                    switch(Opcao_Texto) {

                        case 1: { // IMPRIMIR
                            T.ImprimirTexto();
                            break;
                        }
                        case 2: { // BUSCAR
                            Palavra B;
                            cout << "Digite a palavra a ser procurada: ";
                            cin >> B;

                            if (T.Buscar(B))
                                cout << "Palavra '" << B << "' encontrada!" << endl;
                            else
                                cout << "Palavra '" << B << "' NAO encontrada!" << endl;
                            break;
                        }

                    }

                }
                break;
            }
        }
    }

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

    return 0;
}

