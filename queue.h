#ifndef _QUEUE
#define _QUEUE
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
typedef enum {FALSE,TRUE} BOOL;

typedef struct fila {
  int inicio, fim, nmax;
  int size;
  CLIENTE *queue;
} QUEUE;
// criar fila com capacidade para n inteiros
QUEUE *_fila(int n);
// colocar valor na fila
void coloca(CLIENTE v,QUEUE *f);
// retirar valor na fila
CLIENTE retira(QUEUE *f);
// verificar se a fila está vazia
BOOL vazia(QUEUE *f);
// verificar se a fila não admite mais elementos
BOOL queue_is_full(QUEUE *f);
// liberta fila
void free_queue(QUEUE *f);
// retorna o tamanho da fila
int size(QUEUE *f);
// retorna o inicio da fila
CLIENTE inicio(QUEUE *q);
// print da fila
void printFila(QUEUE *f);
// funcao auxiliar (privada)
static void queue_exit_error(char *msg);

#endif
