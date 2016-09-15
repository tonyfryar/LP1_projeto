//busca.hpp
// Tony

#ifndef BUSCA_HPP
#define BUSCA_HPP

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
//#include "busca.hpp"

using namespace std;

int busca_sequencial_ite(int chave, int vetor[], int tamanho);
int busca_sequencial_rec(int chave, int vetor[], int tamanho);

bool BD_BuscarPalavras(ListaGestao bd, char palavras[MAX_TAM][MAX_TAM], int argc,int tipo, int impTempo);
bool BD_BuscarPalavras(ListaGestao bd, char palavras[MAX_TAM][MAX_TAM], int argc,int tipo, int impTempo, char impDec);

#endif