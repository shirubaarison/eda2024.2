#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/common.h"

// Método da divisão!
unsigned int hash_div(int valor, int tam, int mod)
{
  unsigned int hashed_value = valor % mod;
  return hashed_value % tam;
}

void inserir_no(Hash *hash, int valor, int tam, int mod) 
{
  unsigned int pos = hash_div(valor, tam, mod);
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

int main(int argc, char *argv[])
{  
  if (argc < 3) {
    printf("Uso: %s mod tam\n", argv[0]);
    return 2;
  }

  int mod = atoi(argv[1]);
  int tam = atoi(argv[2]);
  
  Hash *tabela = criar_tabela();
  
  srand(time(NULL));
  int i, valor;
  for (i = 0; i < 100; i++) {
    valor = rand() % 256;
    inserir_no(tabela, valor, tam, mod);
    // printf("%d foi inserido na tabela.\n", valor);
  }

  printar_tabela(tabela, tam);

  return 0;
}


