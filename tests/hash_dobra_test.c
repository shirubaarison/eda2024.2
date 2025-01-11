#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../include/common.h"
#include "../include/dobra.h"
#include "../include/tests/test_helper.h"

Resposta *teste_inverter()
{
  ULL resposta, esperado;

  resposta = inverter(2);
  esperado = 2;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  resposta = inverter(23);
  esperado = 32;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  resposta = inverter(323);
  esperado = 323;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  resposta = inverter(1004);
  esperado = 4001;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  return sucesso();
}

Resposta *teste_somar_algarismos()
{
  ULL resposta, esperado;

  resposta = somar_algarismos(2, 3);
  esperado = 5;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  resposta = somar_algarismos(12, 34);
  esperado = 55;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  resposta = somar_algarismos(99, 11);
  esperado = 0;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  resposta = somar_algarismos(204, 108);
  esperado = 5;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  resposta = somar_algarismos(3, 22);
  esperado = 25;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  return sucesso();
}

Resposta *teste_hash_dobra()
{
  ULL resposta, esperado;

  resposta = hash_dobra(813459, 100, 0);
  esperado = 73;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  resposta = hash_dobra(2135637962, 100, 0);
  esperado = 86;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  resposta = hash_dobra(1912752614, 100, 0);
  esperado = 71;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  resposta = hash_dobra(1912752614, 1000, 0);
  esperado = 378;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  resposta = hash_dobra(130919414012, 10000, 0);
  esperado = 6702;
  if (resposta != esperado)
    return criar_mensagem(ERRO, esperado, resposta);

  return sucesso();
}

int main() 
{
  Resposta *resultado = NULL;

  printf("inverter: ");
  
  resultado = teste_inverter();
  if (resultado->erro == ERRO)
    mostrar_erro(resultado);
  
  printf("OK\n");

  printf("somar_algarismos: ");
  
  resultado = teste_somar_algarismos();
  if (resultado->erro == ERRO)
    mostrar_erro(resultado);

  printf("OK\n");

  printf("hash_dobra: ");
  
  resultado = teste_hash_dobra();
  if (resultado->erro == ERRO)
    mostrar_erro(resultado);

  printf("OK\n");
  printf("Parabéns, passou em todos os teste!\n");
  return EXIT_SUCCESS;
}