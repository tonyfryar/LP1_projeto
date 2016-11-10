//busca.cpp
// Tony

#include <iostream>
#include <cstring>
//#include <locale.h> // PARA USAR O setlocale (TRABALHAR COM LETRAS ACENTUADAS)
#include <stdlib.h>
#include <fstream>
#include <stdio.h> // PARA USAR O REMOVE();
#include <dirent.h>
//#include <sys/time.h> // PARA USAR O gettimeofday() (MEDIDOR DE TEMPO)
//#include <chrono>
//#include "basededados.hpp"
#include "busca.hpp"

using namespace std;


void BuscarPalavra(string palavra){

    ifstream infile;
    infile.open("basededados.txt");


        if (!infile.is_open()){
            cout << "Arquivo não encotrado" << endl;
        }
        
        else{
            int ii;
            string arquivo;
            
            for(ii=0; infile >> arquivo; ii++){
                //cout << palavras[ii] << endl;
                cout << "Buscando no arquivo "  << arquivo << endl;
                
                BuscarPalavraNoArquivo(arquivo, palavra);
            }
        }
    // listar os arquivos na base de dados
    // chamar buscarpalavranoarquivo para cada arquivo na base de dados
}

void BuscarPalavraNoArquivo(string arquivo, string palavra){

    //high_resolution_clock::time_point t1 = high_resolution_clock::now(); // inicio da medição

    string busca;

    ifstream infile;
    infile.open(arquivo);

    while (infile >> busca){
        //cout << busca.compare(palavra) << " " <<  busca << endl;
        while (!isalnum(busca[busca.length()-1]) && busca.length() > 1){ // verifica se string não toda alfanumerica e maior que 1
            busca.erase(busca.length()-1,1); // apaga os caracateres especiais no final da string
        }
        if (busca.compare(palavra) == 0){
            
            //infile.close();
            //high_resolution_clock::time_point t2 = high_resolution_clock::now(); // fim da medição

            //auto duracao = duration_cast<microseconds>(t2-t1).count();
            //long double duracao = duration<long double, std::micro>(t2 - t1).count(); // duração da medição

            cout << "Encontrou a palavra " << palavra << " no arquivo " << arquivo << endl; 
        }
    }
    infile.close();

    //high_resolution_clock::time_point t2 = high_resolution_clock::now(); // fim da medição
    //auto duracao = duration_cast<microseconds>(t2-t1).count(); // duração da medição
    //long double duracao = duration<long double, std::micro>(t2 - t1).count();

    //cout << "Não encontrou a palavra " << palavra << " em " << duracao << " microssegundos." << endl;
}
