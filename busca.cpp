//busca.cpp
// Tony

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

/**
 *  Função que implementa busca sequencial em sua versão iterativa. Não requer que o vetor de entrada esteja ordenado.
 *
 *  @param  chave   - chave de busca
 *  @param  vetor[] - vetor de inteiros onde a busca é realizada
 *  @param  tamanho - tamanho do vetor
 *
 *  @return índice, caso exista um elemento em vetor[] tal que chave == vetor[índice]. Caso contrário, -1.
 */
int busca_sequencial_ite(int chave, int vetor[], int tamanho){
    // Inicializa posição de busca
    int posicao = 0;
    
    do{
        // Verifica se encontrou elemento
        if(chave == vetor[posicao]){
            // Encontrou elemento
            return posicao;
        }
        
        // Incrementa posição de busca
        posicao = posicao + 1;
    } while( posicao < tamanho );
    
    // Não encontrou elemento
    return -1;
}

/**
 *  Função que implementa busca sequencial em sua versão recursiva. Não requer que o vetor de entrada esteja ordenado.
 *
 *  @param  chave   - chave de busca
 *  @param  vetor[] - vetor de inteiros onde a busca é realizada
 *  @param  tamanho - tamanho do vetor
 *
 *  @return índice, caso exista um elemento em vetor[] tal que chave > vetor[índice]. Caso contrário -1 ou a própria função novamente.
 */
int busca_sequencial_rec(int chave, int vetor[], int tamanho){

    if (tamanho == 0){
        return -1; // INSUCESSO
    }
    if (chave > vetor[tamanho-1]){
        return tamanho; // SUCESSO
    }
    else {
        return busca_sequencial_rec(chave, vetor, tamanho-1);
    }
}
/*
 *   Função que busca palavras na Base de Dados, de acordo com as opções do usuário.
 *   @param bd >> recebe a ListaGestao contendo a Base de Dados, um um clone ordenado dela.
 *   @param palavras >> recebe o vetor de strings contendo as palavras a serem buscadas.
 *   @param argc >> recebe a quantidade de argumentos do usuário, para controlar laços de repetições.
 *   @param tipo >> recebe o inteiro que define qual opção de busca o usuário escolheu (-bAND ou -bOR).
 *   @param impTempo >> recebe o inteiro que define se o tempo de busca será ou não registrado.
 *   @retorno >> retorna true se a função funcionar adequadamente, ou false se não funcionar.
 */  
bool BD_BuscarPalavras(ListaGestao bd, char palavras[MAX_TAM][MAX_TAM], int argc,int tipo, int impTempo){
   
    Lista lista = CriarLista();
    Lista dual = CriarLista();
    int w;
    
    int linha = 1;
    char buffer[MAX_LENGTH];
    
    
    struct timeval inicio, final;
    int tempo_mili=0;
    if(impTempo==1){ 
       gettimeofday(&inicio, NULL); 
    }
   
    for(NoGestao i = bd->cabeca->proximo; i != bd->cauda; i = i->proximo){
        i->tabela = BD_CriarTabelaPalavras(i->arquivo);
        for(int w=0; w<argc-2; w++){
            if(w==0){
                dual = TAB_Buscar(i->tabela, palavras[0]);
            }
            lista=TAB_Buscar(i->tabela, palavras[w]);
            dual = LIS_Intercalar(dual, lista, tipo);
        } 
          
        if(dual == NULL){
            cout << "\t>> Foram encontradas 0 linhas no arquivo \"" << i->arquivo << "\":" << endl;
        }else{
            cout << "\t>> Foram encontradas "<< dual->tamanho <<" linhas no arquivo \"" << i->arquivo << "\":" << endl;
            BD_ImprimirLinhas(i->arquivo,dual);
            
        }
    }
       
    if(impTempo==1){   
        gettimeofday(&final, NULL);
        tempo_mili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
        cout << "\t>> Tempo total de execução: "<<tempo_mili<<" ms" << endl;
    }
    return true;
}

/*
 *   Função sobrecarregada que busca palavras na Base de Dados, de acordo com as opções do usuário.
 *   @param bd >> recebe a ListaGestao contendo a Base de Dados, um um clone ordenado dela.
 *   @param palavras >> recebe o vetor de strings contendo as palavras a serem buscadas.
 *   @param argc >> recebe a quantidade de argumentos do usuário, para controlar laços de repetições.
 *   @param tipo >> recebe o inteiro que define qual opção de busca o usuário escolheu (-bAND ou -bOR).
 *   @param impTempo >> recebe o inteiro que define se o tempo de busca será ou não registrado.
 *   @param impDec >> recebe o inteiro (sobrecarga) que define o estilo de impressão -pC.
 *   @retorno >> retorna true se a função funcionar adequadamente, ou false se não funcionar.
 */  
bool BD_BuscarPalavras(ListaGestao bd, char palavras[MAX_TAM][MAX_TAM], int argc,int tipo, int impTempo, char impDec){
   
    Lista lista = CriarLista();
    Lista dual = CriarLista();
    ListaGestao dec = LIS_CriarGestao();
    Tabela t = TAB_CriarTabela(10);
    int w, p =0;
    
    int linha = 1;
    char buffer[MAX_LENGTH];
    
    struct timeval inicio, final;
    int tempo_mili=0;
    if(impTempo==1){ 
       gettimeofday(&inicio, NULL); 
    }
   
    for(NoGestao i = bd->cabeca->proximo; i != bd->cauda; i = i->proximo){
        i->tabela = BD_CriarTabelaPalavras(i->arquivo);
        for(int w=0; w<argc-2; w++){
            if(w==0){
                dual = TAB_Buscar(i->tabela, palavras[0]);
            }
            lista=TAB_Buscar(i->tabela, palavras[w]);
            dual = LIS_Intercalar(dual, lista, tipo);
             
        }
        
        if(dual == NULL){
            NoGestao nodec = CriarNoGestao(i->arquivo);
            nodec->qtd_palavras = 0;
            LIS_InserirFimGestao(dec, nodec);
            Chave chave = TAB_CriarChave(i->arquivo);
            Item item = TAB_CriarItem(0);
            TAB_Inserir(t,chave,item);
        }else{
            NoGestao nodec = CriarNoGestao(i->arquivo);
            nodec->qtd_palavras = dual->tamanho;
            LIS_InserirFimGestao(dec, nodec);
            Chave chave = TAB_CriarChave(i->arquivo);
            for(No z = dual->cabeca->proximo; z != dual->cauda; z = z->proximo){
                 Item item = TAB_CriarItem(z->valor);
                 TAB_Inserir(t,chave,item);
            }
        }
    }
    LIS_SelectionSort(dec);
        
    for(NoGestao i = dec->cabeca->proximo; i != dec->cauda; i = i->proximo){
        cout << "\t>> Foram encontradas "<< i->qtd_palavras <<" linhas no arquivo \"" << i->arquivo << "\":" << endl;
        BD_ImprimirLinhas(i->arquivo,TAB_Buscar(t,i->arquivo));
    }
    
    if(impTempo==1){   
        gettimeofday(&final, NULL);
        tempo_mili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
        cout << "\t>> Tempo total de execução: "<<tempo_mili<<" ms" << endl;
    }
