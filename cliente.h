#ifndef _CLIENTE
#define _CLIENTE
#include <stdio.h>
#include <stdlib.h>
typedef struct{
  int items;
  int entrada;
} CLIENTE;

//Construtor do cliente
CLIENTE init(int items, int entrada );
//Retorna quantos artigos o cliente tem
int artigos(CLIENTE cliente);
//Retorna o tempo em que o cliente entrou
int tempo_entrada(CLIENTE cliente);
//Print dos items do cliente e do tempo de entrada
void repr(CLIENTE cliente);
#endif
