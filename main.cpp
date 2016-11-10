//main.cpp
//Tony

#include <iostream>
#include <cstring>
//#include <locale.h> // PARA USAR O setlocale (TRABALHAR COM LETRAS ACENTUADAS)
#include <stdlib.h>
#include <fstream>
#include <stdio.h> // PARA USAR O REMOVE();
#include <dirent.h>
#include <chrono>
//#include <sys/time.h> // PARA USAR O gettimeofday() (MEDIDOR DE TEMPO)
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
        cout << "\t\t>> <-lI> : para Listar os arquivos da base de dados, por ordem de inserção." << endl;
        cout << "\t\t>> <-lA> : para Listar os arquivos da base de dados, alfabeticamente." << endl;
        cout << "\t\t>> <-lT> : para Listar os arquivos da base de dados, por quantidade de palavras." << endl;
        //cout << "\t\t>> <-OR> <nome_arquivo> : para Buscar palavras na base de dados." << endl;
        return 0;
    }
    if(strcmp(argv[1],"-i")==0){
        //char palavras[MAX_TAM][MAX_TAM];
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
            //for(int i=2; i<argc; i++){
            //    strcpy(palavras[i-2],argv[i]);
            //}
            //if(VerificarOpcoes(argc,argv)){
            for(int ii=2; ii<argc;ii++){
            	InserirArquivos(argv[ii]); 
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
    if(strcmp(argv[1],"-lA")==0){
        ListarOrdemAlfabetica();
    }
    if(strcmp(argv[1],"-lI")==0){
        ListarOrdemInsercao();
    }
    if(strcmp(argv[1],"-lT")==0){
        ListarOrdemDecrescenteDePalavras();
    }
    /*if(strcmp(argv[1],"-OR")==0){
        int j=0;
        string palavra;
        int tipo = 1;
            
        if(argc == 2){
            cout << "Opção requer argumento(s)" << endl;

            if(VerificarOpcoes(palavras)){
            	BuscarPalavra(arquivo, argv[ii]);
            }
        }
        else{
        	for(int i =2;i<argc;i++){
        		//strcpy(palavras[j], argv[2]);
                //j++;
                cout << "Buscando palavra "  << argv[i] << endl;
                BuscarPalavra(argv[i]);
            }
            
        }
    }*/
    return 0;
}
