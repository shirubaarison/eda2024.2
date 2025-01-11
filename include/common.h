#ifndef COMMON_H
#define COMMON_H

#define MAX_TAM 9999999

typedef struct no {
  int valor;
  struct no *prox;
} No;

typedef struct {
  No *tabela[MAX_TAM];
} Hash;

Hash *criar_tabela();
No *criar_no(int valor);

void printar_tabela(Hash *hash, int tam);

#endif