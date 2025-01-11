#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#include "../include/common.h"
#include "../include/dobra.h"
#include "../include/div.h"

/**
 * @brief   Função que será testada, cria a tabela hash e insere dependendo da função que será passada;
 * @param   tam         Tamanho.
 * @param   hash_func   Função que será usada para calcular o hash do valor.
 */
void f_test(int tam, unsigned int (*hash_func)(int, int, int)) 
{  
  Hash *tabela = criar_tabela();
  srand(time(NULL));
  unsigned long long valor;
  for (int i = 0; i < tam; i++) {
    valor = rand() % TEST_MAX_CHAVES;
    inserir_no(tabela, valor, tam, hash_func);
  }
}

/**
 * @brief   Calcula o tempo de execução de determinada função.
 * @param   tam       Tamanho do teste.
 * @param   func      Função que será executada para realização da tarefa.
 * @param   hash_func Função que será utilizada para a inserção na tabela de disperção
*/
void teste(int tam, void (*func)(int, unsigned int (*)(int, int, int)), unsigned int (*hash_func)(int, int, int)) 
{
  clock_t inicio, fim;
  double tempo;

  inicio = clock();

  func(tam, hash_func);

  fim = clock();

  tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  printf("Tempo de execução: %.6f segundos.\n", tempo);
}

int main()
{ 
  // TODO: Executar de forma paralela

  printf("=-=-=-=-=-=-= Método da divisão =-=-=-=-=-=-=\n");
  int n = 50000;
  for (int i = 0; i < 5; i++) {
    printf("n = %d\n", n);
    teste(n, f_test, hash_div);
    n += 50000;
  }

  printf("=-=-=-=-=-=-=- Método da dobra -=-=-=-=-=-=-=\n");
  n = 50000;
  for (int i = 0; i < 5; i++) {
    printf("n = %d\n", n);
    teste(n, f_test, hash_dobra);
    n += 50000;
  }

  return EXIT_SUCCESS;
}