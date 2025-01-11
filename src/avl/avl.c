#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int chave;
  struct no *esq, *dir;
  int bal;
} No;

No *criar_no(int chave) 
{
  No *no = (No*)malloc(sizeof(No));

  if (no == NULL) {
    printf("Erro ao alocar árvore ;(");
  }
  no->chave = no->bal = 0;
  no->dir = no->esq = NULL;
  
  return no;
}

int bal(No *arvore) 
{
  if (arvore == NULL)
    return 0;

  return arvore->bal;
}

int main()
{
  No *raiz = inicializar();

  

  return 0;
}