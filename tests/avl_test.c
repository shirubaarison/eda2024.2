#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/avl.h"

#define MAX_VALUE 100000
#define QTD_NOS 10000
#define QTD_AVLS 1000
#define QTD_REMOCOES 1000

int main()
{  
  srand(time(NULL));
  printf("criando %d árvores...\n", QTD_AVLS);

  No *avls[QTD_AVLS];
  int h = F;

  // iniciar 
  for (int i = 0; i < QTD_AVLS; i++) {
    avls[i] = NULL;
  }

  unsigned long chave;
  bool flag = false;
  for (int i = 0; i < QTD_AVLS; i++) {
    printf("Árvore [%d]\nInserindo %d nós...\n", i + 1, QTD_NOS);
    
    for (int j = 0; j < QTD_NOS; j++) {
      chave = rand() % MAX_VALUE;
      ins_AVL(chave, &avls[i], &h);
    }

    // inserir até fechar a quantidade
    while (qtd_nos(avls[i]) < QTD_NOS) {
      chave = rand() % MAX_VALUE;
      ins_AVL(chave, &avls[i], &h);
    }
    
    printf("A %d° árvore possui %d nós\n", i + 1, qtd_nos(avls[i]));


    if (eh_avl(avls[i]))
      printf("a árvore [%d] é avl\n", i + 1);
    else {
      printf("a árvore [%d] não é avl\n", i + 1);
      flag = true;
    }
      
  } 

  if (flag) {
    printf("uma ou mais árvores não são avl\n");
  } else {
    printf("\ntodas as árvores são avl!\n");
  }

  flag = false;
  for (int i = 0; i < QTD_AVLS; i++) {
    printf("Removendo %d nós na %d° árvore...\n", QTD_REMOCOES, i + 1);

    for (int j = 0; j < QTD_REMOCOES; j++) {
      chave = rand() % MAX_VALUE;
      remover_avl(chave, &avls[i], &h);
    }

    // remover até fechar a quantidade
    while (qtd_nos(avls[i]) > (QTD_NOS - QTD_REMOCOES)) {
      chave = rand() % MAX_VALUE;
      remover_avl(chave, &avls[i], &h);
    }

    printf("A %d° árvore possui %d nós\n", i + 1, qtd_nos(avls[i]));

    if (eh_avl(avls[i]))
      printf("a árvore [%d] é avl\n", i + 1);
    else {
      printf("a árvore [%d] não é avl\n", i + 1);
      flag = true;
    }
      
  }

  if (flag) {
    printf("uma ou mais árvores não são avl\n");
  } else {
    printf("\ntodas as árvores são avl!\n");
  }

  return 0;
}