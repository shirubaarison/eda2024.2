#ifndef DOBRA_H
#define DOBRA_H

/**
 * @brief   Inverte um número.
 * @param   valor   valor.
 * @return  Valor invertido: Ex: 23, retorna 32.
 */
unsigned int inverter(int valor);

/**
 * @brief   Soma algarismos de dois números, sem considerar "sobe 1".
 * @param   valor1   valor1.
 * @param   valor2   valor2.
 * @return  Soma dos algarismos. Ex: 34 + 29 = 53.
 */
unsigned int somar_algarismos(int val1, int val2);

/**
 * @brief   Faz o método da dobra do Jayme.
 * @param   valor   valor que deseja fazer o hash.
 * @param   tam     tamanho da tabela hash.
 * @param   acc     acumulador.
 * @return  Posição que deve ser inserido o valor.
 * 
 * @note    Precisa do acumulador para calcular a soma de forma recursiva.
 */
unsigned int hash_dobra(int valor, int tam, int acc);

#endif