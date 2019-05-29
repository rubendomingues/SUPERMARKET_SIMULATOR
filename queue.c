#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
//-------------- Implementação ---------------------------------------

static void queue_exit_error(char *msg)
{
  fprintf(stderr,"Error: %s.\n",msg);
  exit(EXIT_FAILURE);
}

// criar fila com capacidade para n inteiros
QUEUE *_fila(int n)
{
  QUEUE *q = (QUEUE *) malloc(sizeof(QUEUE));
  if (q == NULL)
    queue_exit_error("sem memoria");

  q -> queue =  (CLIENTE *) malloc(sizeof(CLIENTE)*n);
  if (q -> queue == NULL)
    queue_exit_error("sem memoria");
  q -> size = 0;
  q -> nmax = n;
  q -> inicio = -1;
  q -> fim = 0;
  return q;
}

// libertar fila
void free_queue(QUEUE *q)
{
  if (q != NULL) {
    free(q -> queue);
    free(q);
  } else
    queue_exit_error("fila mal construida");
}


// colocar valor na fila
void coloca(CLIENTE v,QUEUE *q)
{
  if (queue_is_full(q) == TRUE)
    queue_exit_error("fila sem lugar");

  if (q -> queue == NULL)
    queue_exit_error("fila mal construida");

  if (vazia(q)==TRUE)
    q -> inicio = q -> fim; // fila fica com um elemento
  q -> queue[q->fim] = v;
  q -> fim = (q -> fim+1)%(q->nmax);
  q -> size +=1;
}

// retirar valor na fila
CLIENTE retira(QUEUE *q)
{
  CLIENTE aux;
  if (vazia(q) == TRUE)
    queue_exit_error("fila sem valores!!");

  if (q -> queue == NULL)
    queue_exit_error("fila mal construida");

  aux = q ->queue[q ->inicio];
  q -> inicio = (q -> inicio+1)%(q -> nmax);
  if (q -> inicio ==  q -> fim) {  // se só tinha um elemento
    q -> inicio = -1; q -> fim = 0;
  }
  q -> size -=1;
  return aux;
}

// verificar se a fila está vazia
BOOL vazia(QUEUE *q)
{
  if (q == NULL)
    queue_exit_error("fila mal construida");

  if (q -> inicio == -1) return TRUE;
  return FALSE;
}
// retorna o tamanho da fila
int size(QUEUE *q){
  return q->size;
}

// retorna o primeiro elemento da fila
CLIENTE inicio(QUEUE *q){
  if(q == NULL)
    queue_exit_error("fila mal construida");
  if(vazia(q))
    queue_exit_error("fila sem valores");

  return q->queue[q->inicio];
}

// verificar se a fila não admite mais elementos
BOOL queue_is_full(QUEUE *q)
{
  if (q == NULL)
    queue_exit_error("fila mal construida");

  if (q -> fim == q -> inicio) return TRUE;
  return FALSE;
}

// print da fila
void printFila(QUEUE *q){
  if(q == NULL)
    queue_exit_error("fila mal construida");
  if(vazia(q)){
    printf("< <\n");
    return;
  }
  printf("< ");
  int aux = q->inicio;
  while(aux < q->fim){
    repr(q->queue[aux]);
    aux = (aux+1)%(q->nmax);
  }
  printf(" <\n");
}
