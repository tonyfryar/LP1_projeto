//baseDeDados.cpp
//Tony

#include <iostream>
#include <cstring>
//#include <locale.h> // PARA USAR O setlocale (TRABALHAR COM LETRAS ACENTUADAS)
#include <stdlib.h>
#include <fstream>
#include <stdio.h> // PARA USAR O REMOVE();
#include <dirent.h>
#include <sys/time.h> // PARA USAR O gettimeofday() (MEDIDOR DE TEMPO)
#include "analise.hpp"
#include "basededados.hpp"
#include "busca.hpp"

using namespace std;

/*
 *   Função que verifica se as operações passadas são válidas.
 *   @param palavras >> recebe o vetor de strings com os argc que contém as funções para serem verificados.
 *   @retorno >> retorna true se todas as operações forem válida, ou false se uma ou mais não forem.
 */
bool VerificarOpcoes(char palavras[MAX_TAM][MAX_TAM]){
    char op[9][9] = {"-i","-r","-li","-la","-ld","-bAND","-bOR","-tT","-tF"};
    char h = '-';
    int j;
    
    for(int i=0; i<MAX_TAM; i++){
       for(j=0; j<9; j++){
            if(strcmp(palavras[i],op[j])==0){
                
                cout <<"\t>> ERRO! - Conflito de operações: \"" <<op[j]<<"\"" << endl;
                return false;
                
            }
       }
       if(palavras[i][0] == '-'){
           cout <<"\t>> ERRO! - Operação Inexistente \"" <<palavras[i]<<"\"" << endl;
           return false;
       }
    }
    
    return true; 
}
/*
 *   Função que insere um arquivo na Base de Dados.
 *   @param bd >> recebe a ListaGestao contendo a Base de Dados.
 *   @param nomeArquivo >> recebe a string com o nome do texto a ser incluído na Base de Dados.
 *   @retorno >> retorna true se o texto for incluído na Base de Dados com sucesso, ou false se não for.
 */  
bool BD_InserirArquivos(ListaGestao bd, char nomeArquivo[MAX_TAM]){
    
    if(VerificarArquivoTxt(nomeArquivo)==false){
        
        if(strcmp(nomeArquivo,"BD_Arquivos.txt")==0){
            cout << "\t>> ERRO! - Nao é permitido inserir a base de dados!" << endl;
            return false;
        }
        cout << "\t>> ERRO! - Arquivo \""<<nomeArquivo<<"\" nao permitido (somente arquivos .txt)" << endl;    
        return false;
    }
        
    int retorno;
    NoGestao no = CriarNoGestao(nomeArquivo);
     
    no->tabela = BD_CriarTabelaPalavras(nomeArquivo);
    no->qtd_palavras = ContadorPalavras(no->tabela);
    
    
   
    if(no->tabela == NULL){
        cout << "\t>> Arquivo \""<<nomeArquivo<<"\" nao foi encontrado no caminho." << endl;
        return false;
    }
    else{
        retorno = LIS_InserirFimGestao(bd,no);

        switch(retorno){
        	case 1:
        	cout << "\t>> Arquivo \"" << nomeArquivo << "\" já estava na base de buscas" << endl << "\tSeu registro foi atualizado." << endl;
            break;
            case 0:
            cout << "\t>> Arquivo \""<<nomeArquivo<<"\" inserido na base de buscas." << endl;
            break;
            default:
            cout << "\t>> ERRO! = Arquivo \""<<nomeArquivo<<"\" não Inserido" << endl;
            break;
        }
    
        return true;
    }
}
/*
 *   Função que remove um arquivo da Base de Dados.
 *   @param bd >> recebe a ListaGestao com a Base de Dados.
 *   @param nomeArquivo >> recebe a string com o nome do arquivo a ser removido da Base de Dados.
 *   @retorno >> retorna true se o texto for removido da Base de Dados com sucesso, ou false se não for.
 */  
bool BD_RemoverArquivos(ListaGestao bd, char nomeArquivo[MAX_TAM]){

    if(LIS_RemoverGestao(bd, nomeArquivo) < 0){
    	cout << "\t>> Arquivo \""<< nomeArquivo <<"\" não estava na base de buscas." << endl;
    }
    else{
        cout << "\t>> Arquivo \""<< nomeArquivo << "\" removido da base de buscas" << endl;
    }        
}
/*
 *   Função que recebe por ponteiro de função, uma função que ordenará os arquivos da Base de Dados.  
 *   @param  *função >> recebe uma das funções acima: Inserção, Lexico, Decrescente;
 *   @retorno >> não possui return (void).
 */ 
void BD_ListarArquivos(void (*funcao)(ListaGestao),ListaGestao bd){
    
    if(bd->tamanho >0){
    	cout << "\t>> Arquivos contidos na base de buscas:" << endl;
      
    	funcao(bd);    
    }
    else{
    	cout << "\t>> ERRO! - Base de dados vazia." << endl; 
    }    
}