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

ULL hash_analise_digitos_1(ULL chave, int tam) {
    int soma = soma_digitos(chave);
    double media = (double)soma / 10.0;
    double resultado = 0;

    for (int i = 0; i < 10; i++) {
        resultado += soma - media;
    }

    return (ULL)fabs(resultado) % tam;
}

ULL hash_analise_digitos_2(ULL chave, int tam) {
    int soma = soma_digitos(chave);
    double media = (double)soma / 10.0;
    double resultado = 0;

    for (int i = 0; i < 10; i++) {
        resultado += (soma - media);
    }

    resultado = pow(resultado, 2);
    return (ULL)fabs(resultado) % tam;
}