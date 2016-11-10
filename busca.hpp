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
//#include <sys/time.h> // PARA USAR O gettimeofday() (MEDIDOR DE TEMPO)
#include <chrono>
//#include "basededados.hpp"

using namespace std;
using namespace std::chrono;

void BuscarPalavraNoArquivo(string, string);
void BuscarPalavra(string palavra);


#endif
