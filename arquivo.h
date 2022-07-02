#ifndef __ARQUIVO_H__
#define __ARQUIVO_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int chave;
    struct No *prox, *ant;
} No;

/*
Funcao: CriaNo
Descricao: Aloca dinamicamente uma estrutura No e inicializa os campos com os dados passados como parâmetro.
Entrada:
    int ch: número a ser inserido no nó.
Saida: ponteiro para a estrutura No alocada dinâmicamente.
*/
No *criaNo(int ch);

/*
Funcao: insere
Descricao: Insere um nó em uma lista desordenada.
Entrada:
    No *L: Lista para ser inserida
    int ch: elemento a ser inserido na lista.
Saida: ponteiro para a Lista.
*/
No *insere(No *L, int ch);

/*
Funcao: removeChave
Descricao: Remove um nó em uma lista desordenada.
Entrada:
    No *L: Lista que será alterada.
    int ch: elemento chave que será removido da lista.
Saida: ponteiro para a Lista.
*/
No *removeChave(No *L, int ch);

/*
Funcao: imprime
Descricao: Imprime todos os elementos da lista.
Entrada:
    No *L: Lista que será impressa.
    int ch: elemento chave que será removido da lista.
Saida: void.
*/
void imprime(No *L);

/*
Funcao: esvazia
Descricao: Esvazia todos os elementos de um conjunto.
Entrada:
    No *L: Lista que será esvaziada.
Saida: Lista nula.
*/
No *esvazia(No *L);

/*
Funcao: vazia
Descricao: Verifica se a lista esta vazia.
Entrada:
    No *L: Lista que será verificada.
Saida:
    0 - lista não nula.
    1 - lista nula.
*/
int vazia(No *L);

/*
Funcao: buscaElemento
Descricao: Verifica se uma chave existe na lista.
Entrada:
    No *L: Lista que será verificada.
    int ch: chave a ser buscada.
Saida:
    0 - se a chave não existe na lista.
    1 - se a chave existe na lista.
*/
int buscaElemento(No *L, int ch);

/*
Funcao: Subconjunto
Descricao: Verifica se um conjunto está contido em outro.
Entrada:
    No *L: Conjunto que será verificado.
    No *J: Conjunto que será verificado.
Saida:
    0 - se um conjunto não está contido em outro.
    1 - se um conjunto está contido em outro.
*/
int subconjunto(No *L, No *J);

/*
Funcao: iguais
Descricao: Verifica se um conjunto é identico ao outro.
Entrada:
    No *L: Conjunto que será verificado.
    No *J: Conjunto que será verificado.
Saida:
    0 - se os conjuntos não são identicos.
    1 - se os conjuntos são iguas.
*/
int iguais(No *L, No *J);

/*
Funcao: uniao
Descricao: Faz a União de dois conjuntos.
Entrada:
    No *L: Conjunto que será verificado.
    No *J: Conjunto que será verificado.
    No *K: Resultado da união dos conjuntos.
Saida:
    ponteiro para a Lista resultante da união.
*/
No *uniao(No *L, No *J, No *K);

/*
Funcao: intersecao
Descricao: Faz a Intersecção de dois conjuntos.
Entrada:
    No *L: Conjunto que será verificado.
    No *J: Conjunto que será verificado.
    No *K: Resultado da intersecção dos conjuntos.
Saida:
    ponteiro para a Lista resultante da intersecção.
*/
No *intersecao(No *L, No *J, No *K);

/*
Funcao: relativo
Descricao: Faz a subtração de dois conjuntos.
Entrada:
    No *L: Conjunto que será verificado.
    No *J: Conjunto que será verificado.
    No *K: Resultado da subtração dos conjuntos.
Saida:
    ponteiro para a Lista resultante da subtração.
*/
No *relativo(No *L, No *J, No *K);

/*
Funcao: busca
Descricao: Verifica se uma chave existe na lista.
Entrada:
    No *L: Lista que será verificada.
    int ch: chave a ser buscada.
Saida:
    ponteiro para o nó que possui a chave.
*/
No *busca(No *L, int ch);

/*
Funcao: tamanho
Descricao: Faz a contagem de nós de uma lista.
Entrada:
    No *L: Lista que será verificada.
Saida:
    inteiro com o tamanho da lista.
*/
int tamanho(No *L);

/*
Funcao: menu1
Descricao: Imprime no terminal o menu das inserções de conjuntos.
Saida:
    void.
*/
void menu1();

/*
Funcao: menu2
Descricao: Imprime no terminal o menu das operações entre conjuntos.
Saida:
    void.
*/
void menu2();

/*
Funcao: lerConjunto
Descricao: Faz a leitura dos elementos do conjunto pelo terminal.
Entrada:
    No *L: Lista onde será inserido os elementos no conjunto.
Saida:
    ponteiro para a Lista resultante da leitura.
*/
No *lerConjunto(No *L);

/*
Funcao: insercaoConjunto
Descricao: Faz as operações de inserção de um conjunto.
Entrada:
    No *L: Lista onde será alterado ou não os elementos de um conjunto.
Saida:
    ponteiro para a Lista resultante da leitura.
*/
No *insercaoConjunto(No *L);

/*
Funcao: operacao
Descricao: Faz as operações entre os conjuntos.
Entrada:
    No *L: Conjunto A.
    No *J: Conjunto B.
Saida:
    void.
*/
void operacao(No *L, No *J);

#endif

