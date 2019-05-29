#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
//seletores

//Construtor do cliente
CLIENTE init(int items, int entrada){
  CLIENTE cliente;
  cliente.items = items;
  cliente.entrada = entrada;
  return cliente;
}

//Retorna quantos artigos o cliente tem
int artigos(CLIENTE cliente){
  return cliente.items;
}

//Retorna o tempo em que o cliente entrou
int tempo_entrada(CLIENTE cliente){
  return cliente.entrada;
}

// transformador de saida
//Print dos items do cliente e do tempo de entrada
void repr(CLIENTE cliente){
  printf("[ %d : %d ]", cliente.items, cliente.entrada);
}
