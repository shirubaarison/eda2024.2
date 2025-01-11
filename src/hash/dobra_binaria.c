#include<stdlib.h>
#include<stdio.h>
#include <time.h>

#include "../../include/common.h"

enum Tipo {ou, e, ouEx};

// Método da dobra
unsigned int hash_dobra(ULL valor, int tam, int acc) 
{
 unsigned int res = 0;
 
}

void inserir_no(Hash *hash, ULL valor, int tam) 
{
  unsigned int pos = hash_dobra(valor, tam, 0);
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
  if (argc < 2) {
    printf("Uso: %s tam\n", argv[0]);
    return 2;
  }

  int tam = atoi(argv[1]);
  
  Hash *tabela = criar_tabela();
  
  srand(time(NULL));
  ULL valor;
  for (int i = 0; i < tam * 2; i++) {
    valor = rand() % 2000000000;
    inserir_no(tabela, valor, tam);
    printf("%lld foi inserido na tabela.\n", valor);
  }

  printar_tabela(tabela, tam);

  return 0;
}