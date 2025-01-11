#include<stdlib.h>
#include<stdio.h>

unsigned int inverter(int valor) { return ((valor % 10) * 10 + valor / 10); }

unsigned int somar_algarismos(int val1, int val2) { 
  val2 = inverter(val2);
  
  return (((val1 / 10) + (val2 / 10)) % 10 * 10) + (((val1 % 10) + (val2 % 10)) % 10); 
}

unsigned int hash_dobra(int valor, int tam, int acc) 
{
  if (valor < 100) {
    return (somar_algarismos(valor, acc)) % tam;
  }
  
  acc = somar_algarismos(valor % 100, acc);
  valor /= 100;
  
  return hash_dobra(valor, tam, acc);
}