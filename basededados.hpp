//basededados.hpp
//Tony

#ifndef BASEDEDADOS_HPP
#define BASEDEDADOS_HPP

#include <iostream>
#include <cstring>
//#include <locale.h> // PARA USAR O setlocale (TRABALHAR COM LETRAS ACENTUADAS)
#include <stdlib.h>
#include <fstream>
#include <stdio.h> // PARA USAR O REMOVE();
#include <dirent.h>
#include <sys/time.h> // PARA USAR O gettimeofday() (MEDIDOR DE TEMPO)
//#include "busca.hpp"

#define MAX_TAM 100
using namespace std;

/*struct palavras
{
	string palavra;
	struct no* primieroNoDaLista;
};

struct no
{
	string nomeDoArquivo;
	int linhaDaPalNoArq;
	struct no* proximoNo;
};
*/
typedef struct arquivo
{
	string nomeDoArquivo;
	int qtdDePalDoArq;	
} arquivo; 


/*no criarNo();
palavra criarPalavras();
*/

//bool VerificarOpcoes(char palavras[MAX_TAM][MAX_TAM]);
bool InserirArquivos(char *nomeArquivo);
bool RemoverArquivos(string arquivo);
void ListarOrdemAlfabetica();
void ListarOrdemInsercao();
void ListarOrdemDecrescenteDePalavras();
void insertionSort(string vetor[], int fim, int inicio);
void insertionSort(arquivo vetor[], int fim, int inicio);
int contadorDePalavras(char* nomeArquivo);

#endif
