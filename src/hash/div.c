#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../include/common.h"

ULL hash_div(ULL valor, int tam, int _)
{
  unsigned int hashed_value = valor % MOD;
  return hashed_value % tam;
}