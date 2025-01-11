#include<stdlib.h>
#include<stdio.h>
#include <time.h>

#include "../include/common.h"

unsigned int inverter(int valor) { return ((valor % 10) * 10 + valor / 10); }

unsigned int somar_algarismos(int val1, int val2) { 
  val2 = inverter(val2);
  
  return (((val1 / 10) + (val2 / 10)) % 10 * 10) + (((val1 % 10) + (val2 % 10)) % 10); 
}

// Método da dobra
unsigned int hash_dobra(int valor, int tam, int acc) 
{
  if (valor < 100) {
    return (somar_algarismos(valor, acc)) % tam;
  }
  
  acc = somar_algarismos(valor % 100, acc);
  valor /= 100;
  
  return hash_dobra(valor, tam, acc);
}

void inserir_no(Hash *hash, int valor, int tam) 
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
  unsigned long long valor;
  for (int i = 0; i < tam * 2; i++) {
    valor = rand() % 2000000000;
    inserir_no(tabela, valor, tam);
    printf("%lld foi inserido na tabela.\n", valor);
  }

  printar_tabela(tabela, tam);

  return 0;
}