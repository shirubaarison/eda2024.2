#ifndef DIV_H
#define DIV_H

/**
 * @brief   Faz o método da divisão.
 * @param   valor   valor que deseja fazer o hash.
 * @param   tam     tamanho da tabela hash.
 * @param   _       parâmetro inútil.
 * @return  Posição que deve ser inserido o valor.
 * 
 * @note    O _ é necessário pois da forma como o código foi organizado, é necessário passar o terceiro argumento obrigatóriamente.
 */
ULL hash_div(ULL valor, int tam, int _);

#endif
