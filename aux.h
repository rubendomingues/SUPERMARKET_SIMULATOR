#ifndef _AUX
#define _AUX
#include <stdio.h>
#include <stdlib.h>
#include "caixa.h"
#include "queue.h"

void trata_clientes(int passo, CAIXA *lista_caixas[], int n_caixas);
void trata_primeiroP(int passo, CAIXA *caixa_atual);
void trata_primeiro(int passo, CAIXA *caixa_atual);
BOOL caixas_cheias(CAIXA *lista_caixas[], int n_caixas);
void mostra_caixas(CAIXA *lista_caixas[], int n_caixas);
void processa_resultados(CAIXA *lista_caixas[],int n_caixas);
void simulador(int afluencia, int apetencia, int n_caixas, int n_ciclos);
int bestChoice(CAIXA *lista_caixas[], int n_caixas, CLIENTE cliente);
int bestChoiceP(CAIXA *lista_caixas[], int n_caixas, CLIENTE cliente);
#endif
