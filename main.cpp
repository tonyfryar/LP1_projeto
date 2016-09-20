//main.cpp
//Tony

#include <iostream>
#include <cstring>
//#include <locale.h> // PARA USAR O setlocale (TRABALHAR COM LETRAS ACENTUADAS)
#include <stdlib.h>
#include <fstream>
#include <stdio.h> // PARA USAR O REMOVE();
#include <dirent.h>
#include <sys/time.h> // PARA USAR O gettimeofday() (MEDIDOR DE TEMPO)
//#include "analise.hpp"
#include "basededados.hpp"
//#include "busca.hpp"

using namespace std;

int main(int argc, char* argv[]){

	//setlocale(LC_ALL, "Portuguese"); //PARA ADICIONAR AS PALAVRAS ACENTUADAS ÀS BUSCAS

	if(argc == 1){
        cout << "\t>> Informar Parâmetros:" << endl; //TERMINAR AQUI ! HELP DOS PARAMETROS
        cout << "\t\t>> <-i> <nome_arquivo> : para Inserir arquivos na base de dados." << endl;
        cout << "\t\t>> <-r> <nome_arquivo> : para Remover arquivos na base de dados." << endl;
        //cout << "\t\t>> <-txt> : para inserir todos os arquivos da pasta na base de dados." << endl;
        //cout << "\t\t>> <-clr> : para remover todos os arquivos da pasta na base de dados." << endl;
        //cout << "\t\t>> <-li> : para Listar os arquivos da base de dados, por data de Inserção." << endl;
        cout << "\t\t>> <-la> : para Listar os arquivos da base de dados, Alfabeticamente." << endl;
        //cout << "\t\t>> <-ld> : para Listar os arquivos da base de dados, por quantidade Decrescente de palavras." << endl;
        cout << "\t\t>> <-OR> <nome_arquivo> : para Buscar palavras na base de dados." << endl;
        return 0;
    }
    if(strcmp(argv[1],"-i")==0){
        char palavras[MAX_TAM][MAX_TAM];
        if(argc == 2){
            cout << "Opção requer argumento(s)" << endl;
            /*cin >> argv[2];
            for(int i=2; i<argc; i++){
            	strcpy(palavras[i-2],argv[i]);
            }
            if(VerificarOpcoes(palavras)){
            	for(int i=0; i<argc-2;i++){
                	BD_InserirArquivos(bd,palavras[i]); 
                }
            }*/
        }
        else{
            for(int i=2; i<argc; i++){
                strcpy(palavras[i-2],argv[i]);
            }
            if(VerificarOpcoes(palavras)){
                for(int i=0; i<argc-2;i++){
                    InserirArquivos(palavras[i]); 
                }
            }     
        }
    }
    if(strcmp(argv[1],"-r")==0){
        if(argc == 2){
            cout << "Opção requer argumento(s)" << endl;
        }
        else{
            for(int i=2;i<argc;i++){
                RemoverArquivos(argv[i]);
            } 
        }
    }
/*    if(strcmp(argv[1],"-la")==0){
        BD_ListarArquivos(Lexico,bd);
    }
    if(strcmp(argv[1],"-OR")==0){
        int j=0;
        char palavras[MAX_TAM][MAX_TAM];
        int tipo = 1;
            
        if(argc == 2){
            cout << "Opção requer argumento(s)" << endl;
            cin >> argv[2];
            for(int i =2;i<argc;i++){
        		strcpy(palavras[j], argv[i]);
                j++;
            }
            if(VerificarOpcoes(palavras)){
            	BD_BuscarPalavras(bd,palavras, argc, tipo, 0);
            }
        }
        else{
        	for(int i =2;i<argc;i++){
        		strcpy(palavras[j], argv[i]);
                j++;
            }
            if(VerificarOpcoes(palavras)){
            	BD_BuscarPalavras(bd,palavras, argc, tipo, 0);
            }
        }*/
    return 0;
}
