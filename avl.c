#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int valor;
  struct no *esq, *dir;
  int bal;
} No;


No *inicializar() 
{
  No *raiz = malloc(sizeof(No));

  if (raiz == NULL) {
    printf("Erro ao alocar árvore ;(");
  }
  raiz->dir = raiz->esq = NULL;
  
  return raiz;
}

int altura(No *arvore) 
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