#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#include "../include/common.h"
#include "../include/dobra.h"
#include "../include/div.h"
#include "../include/mult.h"
#include "../include/analise.h"

/**
 * @brief   Função que será testada, cria a tabela hash e insere dependendo da função que será passada;
 * @param   tam         Tamanho.
 * @param   hash_func   Função que será usada para calcular o hash do valor.
 * @param   col         Ponteiro para contar colisões.
 */
void f_test(int tam, ULL (*hash_func)(ULL, int), int *col) 
{  
  Hash *tabela = criar_tabela();
  srand(time(NULL));
  ULL valor;
  for (int i = 0; i < tam; i++) {
    valor = rand() % TEST_MAX_CHAVES;
    inserir_no(tabela, valor, tam, hash_func, col);  // Passa o ponteiro de colisões
  }
}

/**
 * @brief   Calcula o tempo de execução de determinada função.
 * @param   tam       Tamanho do teste.
 * @param   func      Função que será executada para realização da tarefa.
 * @param   hash_func Função que será utilizada para a inserção na tabela de disperção.
 * @param   col       Ponteiro para contar colisões.
*/
void teste(int tam, void (*func)(int, ULL (*)(ULL, int), int *), ULL (*hash_func)(ULL, int), int *col) 
{
  clock_t inicio, fim;
  double tempo;

  inicio = clock();

  func(tam, hash_func, col);

  fim = clock();

  tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  printf("Tempo de execução: %.6f segundos.\n", tempo);
  printf("Números de colisões: %d\n", *col);
}

int main()
{ 
  int col = 0;
  printf("=-=-=-=-=-=-= Método da divisão =-=-=-=-=-=-=\n");
  int n = 50000;
  for (int i = 0; i < 5; i++) {
    col = 0;
    printf("n = %d\n", n);
    teste(n, f_test, hash_div, &col);
    n += 50000;
  }
  
  printf("=-=-=-=-=-=-=- Método da dobra (decimal) -=-=\n");
  n = 50000;
  for (int i = 0; i < 5; i++) {
    col = 0;
    printf("n = %d\n", n);
    teste(n, f_test, hash_dobra, &col);
    n += 50000;
  }

  printf("=-=-=-=-=-=-= Método da multiplicação =-=-=\n");
  n = 50000;
  for (int i = 0; i < 5; i++) {
    col = 0;
    printf("n = %d\n", n);
    teste(n, f_test, hash_multiplicacao, &col);
    n += 50000;
  }

  
  printf("=-=-=-=-=-=-= Método da analise1 =-=-=-=-=\n");
  n = 50000;
  for (int i = 0; i < 5; i++) {
    col = 0;
    printf("n = %d\n", n);
    teste(n, f_test, hash_analise_digitos_1, &col);
    n += 50000;
  }

  
  printf("=-=-=-=-=-=-= Método da analise2 =-=-=-=-=\n");
  n = 50000;
  for (int i = 0; i < 5; i++) {
    col = 0;
    printf("n = %d\n", n);
    teste(n, f_test, hash_analise_digitos_2, &col);
    n += 50000;
  }

  return EXIT_SUCCESS;
}
