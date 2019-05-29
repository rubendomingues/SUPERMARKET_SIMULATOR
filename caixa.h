#ifndef _CAIXA
#define _CAIXA
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// # - os clientes na fila dessa caixa
// # - uma "estimativa" tempo em que a caixa estara disponivel
// # - o numero de clientes ja'atendidos por essa caixa
// # - o numero de produtos processados nessa caixa
// # - o tempo total de espera nessa caixa
// # - o numero da caixa
// # - a "velocidade" de processamento da caixa, isto e', quantos produtos processa
// #   por unidade de tempo

typedef struct caixa {
  QUEUE *fila;
  QUEUE *filap;
  int eta;
  int clientes;
  int produtos;
  int espera;
  int numero;
  int velocidade;
} CAIXA;

//Construtor das caixas
CAIXA *__init__(int numero);
//Atualiza o valor do tempo que falta para a caixa estar disponivel
void disponivel(CAIXA *caixa, int valor);
//Atualiza o valor de clientes atendidos
void cliente_atendido(CAIXA *caixa);
//Atualiza o numero de produtos da caixa
void actualiza_produtos(CAIXA *caixa, int produtos);
//Atualiza o tempo de espera da caixa
void actualiza_espera(CAIXA *caixa, int espera);
//Remove um cliente da caixa
void remove_cliente(CAIXA *caixa);
//Remove um cliente da caixa de prioridade
void remove_clienteP(CAIXA *caixa);
//Retorna a fila de clientes da caixa
QUEUE *fila_caixa(CAIXA *caixa);
//Retorna a fila de clientes da caixa de prioridade
QUEUE *fila_caixaP(CAIXA *caixa);
//Retorna o numero da caixa(caixa nº x)
int numero(CAIXA *caixa);
//Retorna a estimativa de tempo para a caixa estar pronta
int pronta(CAIXA *caixa);
//Retorna os clientes da caixa
int clientes(CAIXA *caixa);
//Retorna os produtos da caixa
int produtos(CAIXA *caixa);
//Retorna o tempo de espera da caixa
int espera(CAIXA *caixa);
//Retorna o numero de produtos processados por unidade de tempo na caixa
int tempo_processamento(CAIXA *caixa);
//Retorna se caixa(Prioridade) está vazia ou não
BOOL vazia_P(CAIXA *caixa);
//Retorna se caixa está vazia ou não
BOOL vazia_(CAIXA *caixa);
//Print dos clientes da Caixa
void print_caixa(CAIXA *caixa);
#endif
