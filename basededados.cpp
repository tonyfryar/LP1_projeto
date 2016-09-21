//basededados.cpp
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

/*
 *   Função que verifica se as operações passadas são válidas.
 *   @param palavras >> recebe o vetor de strings com os argc que contém as funções para serem verificados.
 *   @retorno >> retorna true se todas as operações forem válida, ou false se uma ou mais não forem.
 */
bool VerificarOpcoes(char palavras[MAX_TAM][MAX_TAM]){
    char op[4][4] = {"-i","-r","-la","-OR"};
    char h = '-';
    int j;
    
    for(int i=0; i<MAX_TAM; i++){
       for(j=0; j<4; j++){
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
 *   @param nomeArquivo >> recebe a char com o nome do texto a ser incluído na Base de Dados.
 *   @retorno >> retorna true se o texto for incluído na Base de Dados com sucesso, ou false se não for.
 */  
bool InserirArquivos(char nomeArquivo[]){
	string vetor[100];
	int tam;
	ifstream infile;
	infile.open("basededados.txt");

	if (infile.is_open()){
		for (tam = 0; infile >> vetor[tam]; tam++);
		infile.close();
	}
	for (int ii; ii < tam; ii++){
		if (vetor[ii].compare(nomeArquivo) == 0){
			cout << "Arquivo " << vetor[ii] << " já existe!" << endl;
			return false;
		}
	}
	vetor[tam++] = nomeArquivo;

	ofstream outfile;
	outfile.open("basededados.txt", ofstream::app);
	if (outfile.is_open())
		outfile << vetor[tam-1] << endl;

	cout << "Arquivo " << vetor[tam-1] << " inserido!" << endl;	
	outfile.close();
}
/*
 *   Função que remove um arquivo da Base de Dados.
 *   @param arquivo >> recebe a string com o nome do arquivo a ser removido da Base de Dados.
 *   @retorno >> retorna true se o texto for removido da Base de Dados com sucesso, ou false se não for.
 */  
bool RemoverArquivos(string arquivo){
	string vetor[100];
	int tam;
	ifstream infile;
	infile.open("basededados.txt");

	if (infile.is_open())
		for (tam = 0; infile >> vetor[tam]; tam++);

	infile.close();

	for (int ii = 0; ii < tam; ii++){
		if (vetor[ii].compare(arquivo) == 0){
			ofstream outfile;
			outfile.open("basededados.txt");

			if (outfile.is_open()){
				for (int jj = 0; jj < tam; jj++){
					if (jj != ii)
						outfile << vetor[jj] << endl;
				}
				cout << "Arquivo " << vetor[ii] << " removido!" << endl;
				outfile.close();
				return true;
			}
		}	
	}
	cout << "Arquivo não existe na Base de Dados" << endl;  
}
/*
 *   Função que recebe por ponteiro de função, uma função que ordenará os arquivos da Base de Dados.  
 *   @param  *função >> recebe uma das funções acima: Inserção, Lexico, Decrescente;
 *   @retorno >> não possui return (void).
 */
void ListarArquivos(){
    	ifstream infile;
        infile.open("basededados.txt");


        if (!infile.is_open()){
            cout << "Arquivo não encotrado" << endl;
        }
        
        else{
            int ii;
            string palavras[100];
            
            for(ii=0; infile >> palavras[ii]; ii++)
            	//cout << palavras[ii] << endl;

            insertionSort(palavras, ii, 0);
            //quickSort(palavras, ii, 0);
            //ordenaTexto( palavras, ii, 0, selecionaFuncao(1));
            //ordenaTexto(palavras, ii, 0, pFuncao);

            ofstream outfile;
            outfile.open("basededados.txt");

            for(int jj=0; jj <= ii; jj++)
                outfile << palavras[jj] << endl;
        }  
}
/*
Insertion Sort
*/
void insertionSort(string vetor[], int fim, int inicio){
    int ii, jj; 
    string chave;

    for (ii = 1; ii <= fim; ii++){
        chave = vetor[ii];
        jj = ii - 1;

        while ((jj >= 0) && (chave.compare(vetor[jj]) < 0)){
            vetor[jj + 1] = vetor[jj];
            jj = jj - 1;
        }
        vetor[jj + 1] = chave;
    }
}
