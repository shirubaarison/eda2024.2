#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../include/common.h"
#include "../include/div.h"
#include "../include/tests/test_helper.h"

Resposta *teste_hash_div()
{
  ULL resposta, esperado;

  resposta = hash_div(813459, 100, 0);
  esperado = 17;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  resposta = hash_div(1349149, 100, 0);
  esperado = 88;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  resposta = hash_div(1, 100, 0);
  esperado = 1;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  resposta = hash_div(1139481481, 300, 0);
  esperado = 93;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  return sucesso();
}

int main() 
{
  Resposta *resultado = NULL;

  printf("hash_div: ");
  
  resultado = teste_hash_div();
  if (resultado->erro == ERRO)
    mostrar_erro(resultado);
  
  printf("OK\n");

  printf("Parabéns, passou em todos os teste!\n");
  return EXIT_SUCCESS;
}