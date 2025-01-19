#include<stdlib.h>
#include<stdio.h>

#include "../../include/common.h"

ULL inverter(ULL valor) 
{ 
  ULL reverso = 0;

  while (valor > 0) {
    reverso = reverso * 10 + valor % 10;
    valor = valor / 10;
  }

  return reverso;
}

ULL somar_algarismos(ULL val1, ULL val2) { 
  val2 = inverter(val2); // para o método da dobra é necessário inverter

  // somar digito a digito
  int d1, d2, soma = 0, resultado = 0, contador = 1;
  while (val1 > 0 || val2 > 0) {
    d1 = val1 % 10;
    d2 = val2 % 10;

    soma = (d1 + d2) % 10; // sem "sobe um"

    resultado += soma * contador;
    contador *= 10;

    val1 /= 10;
    val2 /= 10;
  }
  
  return resultado;
}

// considera apenas tamanhos multiplos de 10.
ULL hash_aux(ULL valor, int tam, int acc) 
{
  if (valor < tam) {
    return (somar_algarismos(valor, acc)) % tam;
  }
  
  acc = somar_algarismos(valor % tam, acc);
  
  valor /= tam;
  
  return hash_aux(valor, tam, acc);
}

ULL hash_dobra_binaria(int chave, int tamanho) {
    ULL hash = 0;
    while (chave > 0) {
        hash ^= (chave & 0xF);
        chave >>= tamanho;
    }
    return hash % tamanho;
}

ULL hash_dobra(ULL valor, int tam) { return hash_aux(valor, tam, 0); }