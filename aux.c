#include <stdio.h>
#include <stdlib.h>
#include "aux.h"
#include <time.h>

//Funções auxiliares------------------------------------------------------------
//ESCOLHER A MELHOR CAIXA(CLIENTES SEM PRIORIDADE)
int bestChoice(CAIXA *lista_caixas[], int n_caixas, CLIENTE cliente){
  int best=0;
  int pessoas=size(fila_caixa(lista_caixas[0]));
  for(int i=0; i<n_caixas; i++){
    if(size(fila_caixa(lista_caixas[i]))<pessoas){
      best=i;
      pessoas=size(fila_caixa(lista_caixas[i]));
    }
  }
  return best;
}

//ESCOLHER A MELHOR CAIXA(CLIENTES COM PRIORIDADE)
int bestChoiceP(CAIXA *lista_caixas[], int n_caixas, CLIENTE cliente){
  int best=0;
  int pessoas=size(fila_caixaP(lista_caixas[0]));
  for(int i=0; i<n_caixas/4; i++){
    if(size(fila_caixaP(lista_caixas[i]))<pessoas){
      best=i;
      pessoas=size(fila_caixaP(lista_caixas[i]));
    }
  }
  if(pessoas>bestChoice(lista_caixas,n_caixas,cliente))
    return bestChoice(lista_caixas,n_caixas,cliente);
  return best;
}
//TRATA DOS CLIENTES SEM PRIORIDADE
void trata_primeiro(int passo, CAIXA *caixa_atual){
  CLIENTE c;
  int espera, processados;
  c = inicio(fila_caixa(caixa_atual));
  espera = passo - pronta(caixa_atual);
  processados = espera * tempo_processamento(caixa_atual);

  if(processados >= artigos(c)){
    disponivel(caixa_atual,passo+1);
    cliente_atendido(caixa_atual);
    actualiza_produtos(caixa_atual,artigos(c));
    actualiza_espera(caixa_atual,passo-tempo_entrada(c));
    remove_cliente(caixa_atual);

    printf("Cliente atendido na caixa %d\n",numero(caixa_atual));

  }
}
//TRATA DOS CLIENTES COM PRIORIDADE
void trata_primeiroP(int passo, CAIXA *caixa_atual){
  CLIENTE c;
  int espera, processados;
  c = inicio(fila_caixaP(caixa_atual));
  espera = passo- pronta(caixa_atual);
  processados = espera * tempo_processamento(caixa_atual);

  if(processados >= artigos(c)){
    disponivel(caixa_atual,passo+1);
    cliente_atendido(caixa_atual);
    actualiza_produtos(caixa_atual,artigos(c));
    actualiza_espera(caixa_atual,passo-tempo_entrada(c));
    remove_clienteP(caixa_atual);

    printf("Cliente atendido na caixa %d\n",numero(caixa_atual));

  }
}

void trata_clientes(int passo, CAIXA *lista_caixas[], int n_caixas){
  for(int i=0; i<n_caixas;i++){
    if(vazia_P(lista_caixas[i])){ //CASO A FILA DE PRIORIDADE SEJA VAZIA TRATA DA OUTRA
      if(vazia_(lista_caixas[i])){
        disponivel(lista_caixas[i],passo);
      }
      else{
        trata_primeiro(passo,lista_caixas[i]);
      }
    }
    else
      trata_primeiroP(passo,lista_caixas[i]);
  }
}

BOOL caixas_cheias(CAIXA *lista_caixas[], int n_caixas){
  for(int i=0; i<n_caixas; i++){
    if(!vazia(fila_caixa(lista_caixas[i])) || !vazia(fila_caixaP(lista_caixas[i]))){
      return TRUE;
    }
  }
  return FALSE;
}

void mostra_caixas(CAIXA *lista_caixas[], int n_caixas){
  for(int i=0; i<n_caixas;i++){
    print_caixa(lista_caixas[i]);
  }
}

void processa_resultados(CAIXA *lista_caixas[], int n_caixas){
  printf("\n***RESULTADOS DAS CAIXAS***\n");
  for(int i=0; i<n_caixas; i++){
    printf("#Caixa %d# \n[%d produtos por ciclo]\n", numero(lista_caixas[i]), tempo_processamento(lista_caixas[i]));

    if(clientes(lista_caixas[i])!=0){
      printf("%d clientes atendidos \nmedia %.2f produtos/cliente\n", clientes(lista_caixas[i]), (double)(produtos(lista_caixas[i])/clientes(lista_caixas[i])));
    }
    else
      printf("%d clientes atendidos\n", clientes(lista_caixas[i]));
    printf("\n");
  }
}

void simulador(int afluencia, int apetencia, int n_caixas, int n_ciclos){
  srand(time(NULL));
  CAIXA *caixas[n_caixas];

  for(int i=0; i<n_caixas; i++){
    caixas[i] = __init__(i);
  }

  for(int t=1; t<n_ciclos+1; t++){
    printf("== CICLO %d\n", t);
    //Processa clientes nas caixas
    trata_clientes(t,caixas,n_caixas);

    //Cria novo cliente aleatoriamente
    if(rand()%100 <= afluencia){
      int produtos = (rand() % (3*apetencia)) + 1;
      CLIENTE novo_cliente = init(produtos,t);
      printf("--> Criado cliente com %d produtos.\n", produtos);
      int caixa_escolhida = rand() % n_caixas;
      //Coloca cliente na fila
      if(produtos<11){
        caixa_escolhida = bestChoiceP(caixas,n_caixas,novo_cliente);
        coloca(novo_cliente,fila_caixaP(caixas[caixa_escolhida]));
      }
      else{
        caixa_escolhida = bestChoice(caixas,n_caixas,novo_cliente);
        coloca(novo_cliente,fila_caixa(caixas[caixa_escolhida]));
      }
    }

    mostra_caixas(caixas,n_caixas);
  }

  //Fecho de simulacao
  printf("== FECHO DE CAIXAS ==\n");
  printf("\n");
  int t = n_ciclos + 1;

  while(caixas_cheias(caixas,n_caixas)==TRUE){
    printf("== CICLO %d ==\n", t);
    trata_clientes(t, caixas,n_caixas);
    mostra_caixas(caixas,n_caixas);
    t = t + 1;
  }

  processa_resultados(caixas,n_caixas);
}
