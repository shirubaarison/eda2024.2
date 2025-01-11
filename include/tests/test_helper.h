#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include "../common.h"

#define ERRO true

// TODO: Documentar

typedef struct {
  bool erro;
  ULL esperado;
  ULL retornado;
} Resposta;

Resposta *criar_mensagem(bool erro, ULL esperado, ULL retornado);
Resposta *sucesso();
void mostrar_erro(Resposta *erro);

#endif