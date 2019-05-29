#include "caixa.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_FILA 100

//Construtor das caixas
CAIXA *__init__(int numero){
  CAIXA *caixa = (CAIXA*)malloc(sizeof(CAIXA));
  caixa->fila = _fila(MAX_FILA);
  caixa->filap = _fila(MAX_FILA);
  caixa->eta = 0;
  caixa->clientes = 0;
  caixa->produtos = 0;
  caixa->espera = 0;
  caixa->numero = numero;
  caixa->velocidade = (rand() % 5) + 1;
  return caixa;
}

//Atualiza o valor do tempo que falta para a caixa estar disponivel
void disponivel(CAIXA *caixa, int valor){
  caixa->eta = valor;
}

//Atualiza o valor de clientes atendidos
void cliente_atendido(CAIXA *caixa){
  caixa->clientes += 1;
}

//Atualiza o numero de produtos da caixa
void actualiza_produtos(CAIXA *caixa, int produtos){
  caixa->produtos += produtos;
}

//Atualiza o tempo de espera da caixa
void actualiza_espera(CAIXA *caixa, int espera){
  caixa->espera = espera;
}

//Remove um cliente da caixa
void remove_cliente(CAIXA *caixa){
  retira(caixa->fila);
}

//Remove um cliente da caixa de prioridade
void remove_clienteP(CAIXA *caixa){
  retira(caixa->filap);
}

//Retorna a fila de clientes da caixa
QUEUE *fila_caixa(CAIXA *caixa){
  return caixa->fila;
}

//Retorna a fila de clientes da caixa de prioridade
QUEUE *fila_caixaP(CAIXA *caixa){
  return caixa->filap;
}

//Retorna o numero da caixa(caixa nº x)
int numero(CAIXA *caixa){
  return caixa->numero;
}

//Retorna a estimativa de tempo para a caixa estar pronta
int pronta(CAIXA *caixa){
  return caixa->eta;
}

//Retorna os clientes da caixa
int clientes(CAIXA *caixa){
  return caixa->clientes;
}

//Retorna os produtos da caixa
int produtos(CAIXA *caixa){
  return caixa->produtos;
}

//Retorna o tempo de espera da caixa
int espera(CAIXA *caixa){
  return caixa->espera;
}

//Retorna o numero de produtos processados por unidade de tempo na caixa
int tempo_processamento(CAIXA *caixa){
  return caixa->velocidade;
}

//Retorna se caixa(Prioridade) está vazia ou não
BOOL vazia_P(CAIXA *caixa){
  return vazia(caixa->filap);
}

//Retorna se caixa está vazia ou não
BOOL vazia_(CAIXA *caixa){
  return vazia(caixa->fila);
}

//Print dos clientes da Caixa
void print_caixa(CAIXA *caixa){
  printf("Caixa %d ( %d ):\n", caixa->numero ,caixa->eta), printf("FILA SEM PRIORIDADE: "),printFila(caixa->fila), printf("FILA COM PRIORIDADE: "),printFila(caixa->filap);

}
