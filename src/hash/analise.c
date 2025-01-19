#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../../include/common.h"

int soma_digitos(ULL num) {
    int soma = 0;
    while (num > 0) {
        soma += num % 10;
        num /= 10;
    }
    return soma;
}

ULL hash_analise_digitos_1(ULL chave, int tabela_size) {
    int soma = soma_digitos(chave);
    return (ULL)(soma / MOD) % tabela_size;
}

ULL hash_analise_digitos_2(ULL chave, int tabela_size) {
    int soma = soma_digitos(chave);
    return soma % tabela_size;
}