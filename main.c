#include <stdio.h>
#include <stdlib.h>
#include "aux.h"

int main(int argc, char const *argv[]){
  int afluencia=0;
  int apetencia=0;
  int n_caixas=0;
  int n_ciclos=0;
  printf("Afluencia:");
  scanf("%d",&afluencia);
  printf("Apetencia:");
  scanf("%d",&apetencia);
  printf("NºCaixas:");
  scanf("%d",&n_caixas);
  printf("NºCiclos:");
  scanf("%d",&n_ciclos);
  simulador(afluencia,apetencia,n_caixas,n_ciclos);
  return 0;
}
