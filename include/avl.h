#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

#define F 0
#define V 1

typedef struct no {
  int chave;
  struct no *esq, *dir;
  int bal;
} No;

void caso1(No **pt, int *h);
void caso2(No **pt, int *h);
void iniciarNo(No **pt, int chave);
void ins_AVL(int chave, No **pt, int *h);
int qtd_nos(No *pt);
int eh_avl(No *pt);
void balancear(No **pt, char R, int *h);
void trocar(No **pt, No **pt2);
void remover_avl(int chave, No **pt, int *h);
void Caso1R(No **pt, int *h);
void CasoR2(No **pt, int *h);

#endif