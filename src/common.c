
/**
 * @file common.c
 * @brief Implementação das funções para a tabela de dispersão (hash table).
 *
 * Este arquivo contém a implementação das funções necessárias para criar,
 * manipular e testar uma tabela de dispersão.
 *
 * Funções Implementadas:
 * - criar_tabela: Cria uma nova tabela de dispersão.
 * - criar_no: Cria um novo nó com valor fornecido.
 * - inserir_no: Insere um valor na tabela de dispersão.
 * - printar_tabela: Imprime o conteúdo da tabela de dispersão.
 * - contar_digitos: Retorna a quantidade de dígitos de um valor.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../include/common.h"

Hash *criar_tabela() {
  Hash *hash_table = (Hash *) malloc(sizeof(Hash));
  if (hash_table == NULL) {
    printf("Erro ao alocar tabela hash.\n");
    exit(EXIT_FAILURE);
  }

  return hash_table;
}

No *criar_no(ULL valor) 
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

void inserir_no(Hash *hash, ULL valor, int tam, ULL (*funcao_hash)(ULL, int)) 
{
  ULL pos = funcao_hash(valor, tam);
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
      printf("%lld -> ", aux->valor);
      aux = aux->prox;
    }
    printf("/\n");
  } 
}

int contar_digitos(ULL valor) { return (int)log10(valor) + 1; }