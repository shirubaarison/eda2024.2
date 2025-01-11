#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../include/common.h"
#include "../include/dobra.h"
#include "../include/tests/test_helper.h"

Resposta *criar_mensagem(bool erro, ULL esperado, ULL retornado) 
{
  Resposta *novo = (Resposta*) malloc(sizeof(Resposta));
  if (novo == NULL) {
    printf("Erro ao criar resposta do teste.\n");
    exit(EXIT_FAILURE);
  }

  novo->erro = erro;
  novo->esperado = esperado;
  novo->retornado = retornado;

  return novo;
}

Resposta *sucesso() 
{
  return criar_mensagem(false, 0, 0);
}

void mostrar_erro(Resposta *erro) 
{
  printf("Tivemos erros!\n");
  printf("Esperado: %lld\n", erro->esperado);
  printf("Retornado: %lld\n", erro->retornado);

  exit(EXIT_FAILURE);
}