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
#include "analise.hpp"
//#include "basededados.hpp"
#include "busca.hpp"

using namespace std;

bool VerificarOpcoes(char palavras[MAX_TAM][MAX_TAM]);
bool BD_InserirArquivos(ListaGestao bd, char nomeArquivo[MAX_TAM]);
bool BD_RemoverArquivos(ListaGestao bd, char nomeArquivo[MAX_TAM]);
void BD_ListarArquivos(void (*funcao)(ListaGestao),ListaGestao bd);

#endif