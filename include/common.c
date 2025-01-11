#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "common.h"

Hash *criar_tabela() {
  Hash *hash_table = (Hash *) malloc(sizeof(Hash));
  if (hash_table == NULL) {
    printf("Erro ao alocar tabela hash.\n");
    exit(1);
  }

  return hash_table;
}

No *criar_no(int valor) 
{
  No *novo = (No*) malloc(sizeof(No));
  if (novo == NULL) {
    printf("Erro ao alocar nó.\n");
    exit(1);
  }

  novo->valor = valor;
  novo->prox = NULL;

  return novo;
}

void printar_tabela(Hash *hash, int tam) 
{
  No *aux = NULL;
  for (int i = 0; i < tam; i++) {
    aux = hash->tabela[i];

    printf("[%d] -> ", i);
    while (aux != NULL) {
      printf("%d -> ", aux->valor);
      aux = aux->prox;
    }
    printf("/\n");
  } 
}
