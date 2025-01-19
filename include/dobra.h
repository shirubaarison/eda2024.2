#ifndef DOBRA_H
#define DOBRA_H

#include "common.h"

/**
 * @brief   Inverte um número.
 * @param   valor   valor.
 * @return  Valor invertido: Ex: 23, retorna 32.
 */
ULL inverter(ULL valor);

/**
 * @brief   Soma algarismos de dois números, sem considerar "sobe 1".
 * @param   valor1   valor1.
 * @param   valor2   valor2.
 * @return  Soma dos algarismos. Ex: 34 + 29 = 53.
 */
ULL somar_algarismos(ULL val1, ULL val2);

/**
 * @brief   Faz o método da dobra do Jayme.
 * @param   valor   valor que deseja fazer o hash.
 * @param   tam     tamanho da tabela hash.
 * @param   acc     acumulador.
 * @return  Posição que deve ser inserido o valor.
 * 
 * @note    Precisa do acumulador para calcular a soma de forma recursiva.
 */
ULL hash_aux(ULL valor, int tam, int acc);

/**
 * @brief   wrapper pra chamar a função de dobra
 * @param   valor   valor que deseja fazer o hash.
 * @param   tam     tamanho da tabela hash.
 * @return  Posição que deve ser inserido o valor.
 */
ULL hash_dobra(ULL valor, int tam);

ULL hash_dobra_binaria(int chave, int tamanho);

#endif