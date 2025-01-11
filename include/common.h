#ifndef COMMON_H
#define COMMON_H

#define MOD 283                    // Divisor primo escolhido para a o método da divisão
#define MAX_TAM 9999999            // Tamanho máximo da tabela (criação)

#define TEST_MAX_TAM 200000        // Tamanho máximo de testes
#define TEST_MAX_CHAVES 2000000000 // chaves entre 0 e 2000000000

/**
 * @brief Representa um nó.
 *
 * Essa struct têm o valor do nó e o ponteiro para o próximo
*/
typedef struct no {
  int valor;
  struct no *prox;
} No;

/**
 * @brief Representa uma tabela de dispersão.
 *
 * Essa struct possuí apenas um array da tabela alocada com seu tamanho máximo
*/
typedef struct {
  No *tabela[MAX_TAM];
} Hash;

/**
 * @brief   Cria a tabela de dispersão.
 * @return  Tabela criada.
*/
Hash *criar_tabela();

/**
 * @brief   Cria um nó.
 * @param valor   Valor que será inserido no nó.
 * 
 * @return Endereço de memória pro nó criado.
*/
No *criar_no(int valor);

/**
 * @brief   Insere o nó na tabela hash.
 * @param hash        Tabela em que se deseja inserir.
 * @param valor       Valor que será inserido.
 * @param tam         Tamanho da tabela hash.
 * @param funcao_hash Função que será aplicada para calcular a posição dentro da tabela hash.
*/
void inserir_no(Hash *hash, int valor, int tam, unsigned int (*funcao_hash)(int val, int tam, int acc));

/**
 * @brief   Imprime a tabela na tela.
 * @param hash   Tabela que será imprimida.
 * @param tam    Tamanho dessa tabela.
*/
void printar_tabela(Hash *hash, int tam);

#endif