#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#include "../include/common.h"
#include "../include/div.h"

int main(int argc, char *argv[])
{  
  if (argc < 2) {
    printf("Uso: %s tam\n", argv[0]);
    return EXIT_FAILURE;
  }

  int tam = atoi(argv[1]);
  if (tam <= 0) {
    printf("Tamanho não pode ser igual ou menor que 0");
    return EXIT_FAILURE;
  }
  
  Hash *tabela = criar_tabela();
  
  srand(time(NULL));
  int i, valor;
  int col = 0;
  for (i = 0; i < tam; i++) {
    valor = rand() % TEST_MAX_CHAVES;
    inserir_no(tabela, valor, tam, hash_div, &col);
    // printf("%d foi inserido na tabela.\n", valor);
  }

  printar_tabela(tabela, tam);
  printf("%d colisões\n", col);

  return EXIT_SUCCESS;
}