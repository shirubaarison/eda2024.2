#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/common.h"

Hash *criar_tabela() {
  Hash *hash_table = (Hash *) malloc(sizeof(Hash));
  if (hash_table == NULL) {
    printf("Erro ao alocar tabela hash.\n");
    exit(EXIT_FAILURE);
  }

  return hash_table;
}

No *criar_no(int valor) 
{
  No *novo = (No*) malloc(sizeof(No));
  if (novo == NULL) {
    printf("Erro ao alocar nó.\n");
    exit(EXIT_FAILURE);
  }

  novo->valor = valor;
  novo->prox = NULL;

  return novo;
}

void inserir_no(Hash *hash, int valor, int tam, unsigned int (*funcao_hash)(int val, int tam, int acc)) 
{
  unsigned int pos = funcao_hash(valor, tam, 0);
  No *no = hash->tabela[pos];

  if (no == NULL) {
    hash->tabela[pos] = criar_no(valor);
  } else {
    while (no) {
      if (no->prox == NULL) {
        no->prox = criar_no(valor);
        break;
      }
      no = no->prox;
    }
  }
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
