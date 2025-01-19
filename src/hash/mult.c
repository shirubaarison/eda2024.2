#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../../include/common.h"
#include "../../include/mult.h"

ULL hash_multiplicacao(ULL chave, int tamanho) {
    double frac = fmod(chave * CONST, 1); // apenas parte fracionária
    return (ULL)(tamanho * frac);
}