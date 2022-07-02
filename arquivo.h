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
Descricao: Aloca dinamicamente uma estrutura No e inicializa os campos com os dados passados como par�metro.
Entrada:
    int ch: n�mero a ser inserido no n�.
Saida: ponteiro para a estrutura No alocada din�micamente.
*/
No *criaNo(int ch);

/*
Funcao: insere
Descricao: Insere um n� em uma lista desordenada.
Entrada:
    No *L: Lista para ser inserida
    int ch: elemento a ser inserido na lista.
Saida: ponteiro para a Lista.
*/
No *insere(No *L, int ch);

/*
Funcao: removeChave
Descricao: Remove um n� em uma lista desordenada.
Entrada:
    No *L: Lista que ser� alterada.
    int ch: elemento chave que ser� removido da lista.
Saida: ponteiro para a Lista.
*/
No *removeChave(No *L, int ch);

/*
Funcao: imprime
Descricao: Imprime todos os elementos da lista.
Entrada:
    No *L: Lista que ser� impressa.
    int ch: elemento chave que ser� removido da lista.
Saida: void.
*/
void imprime(No *L);

/*
Funcao: esvazia
Descricao: Esvazia todos os elementos de um conjunto.
Entrada:
    No *L: Lista que ser� esvaziada.
Saida: Lista nula.
*/
No *esvazia(No *L);

/*
Funcao: vazia
Descricao: Verifica se a lista esta vazia.
Entrada:
    No *L: Lista que ser� verificada.
Saida:
    0 - lista n�o nula.
    1 - lista nula.
*/
int vazia(No *L);

/*
Funcao: buscaElemento
Descricao: Verifica se uma chave existe na lista.
Entrada:
    No *L: Lista que ser� verificada.
    int ch: chave a ser buscada.
Saida:
    0 - se a chave n�o existe na lista.
    1 - se a chave existe na lista.
*/
int buscaElemento(No *L, int ch);

/*
Funcao: Subconjunto
Descricao: Verifica se um conjunto est� contido em outro.
Entrada:
    No *L: Conjunto que ser� verificado.
    No *J: Conjunto que ser� verificado.
Saida:
    0 - se um conjunto n�o est� contido em outro.
    1 - se um conjunto est� contido em outro.
*/
int subconjunto(No *L, No *J);

/*
Funcao: iguais
Descricao: Verifica se um conjunto � identico ao outro.
Entrada:
    No *L: Conjunto que ser� verificado.
    No *J: Conjunto que ser� verificado.
Saida:
    0 - se os conjuntos n�o s�o identicos.
    1 - se os conjuntos s�o iguas.
*/
int iguais(No *L, No *J);

/*
Funcao: uniao
Descricao: Faz a Uni�o de dois conjuntos.
Entrada:
    No *L: Conjunto que ser� verificado.
    No *J: Conjunto que ser� verificado.
    No *K: Resultado da uni�o dos conjuntos.
Saida:
    ponteiro para a Lista resultante da uni�o.
*/
No *uniao(No *L, No *J, No *K);

/*
Funcao: intersecao
Descricao: Faz a Intersec��o de dois conjuntos.
Entrada:
    No *L: Conjunto que ser� verificado.
    No *J: Conjunto que ser� verificado.
    No *K: Resultado da intersec��o dos conjuntos.
Saida:
    ponteiro para a Lista resultante da intersec��o.
*/
No *intersecao(No *L, No *J, No *K);

/*
Funcao: relativo
Descricao: Faz a subtra��o de dois conjuntos.
Entrada:
    No *L: Conjunto que ser� verificado.
    No *J: Conjunto que ser� verificado.
    No *K: Resultado da subtra��o dos conjuntos.
Saida:
    ponteiro para a Lista resultante da subtra��o.
*/
No *relativo(No *L, No *J, No *K);

/*
Funcao: busca
Descricao: Verifica se uma chave existe na lista.
Entrada:
    No *L: Lista que ser� verificada.
    int ch: chave a ser buscada.
Saida:
    ponteiro para o n� que possui a chave.
*/
No *busca(No *L, int ch);

/*
Funcao: tamanho
Descricao: Faz a contagem de n�s de uma lista.
Entrada:
    No *L: Lista que ser� verificada.
Saida:
    inteiro com o tamanho da lista.
*/
int tamanho(No *L);

/*
Funcao: menu1
Descricao: Imprime no terminal o menu das inser��es de conjuntos.
Saida:
    void.
*/
void menu1();

/*
Funcao: menu2
Descricao: Imprime no terminal o menu das opera��es entre conjuntos.
Saida:
    void.
*/
void menu2();

/*
Funcao: lerConjunto
Descricao: Faz a leitura dos elementos do conjunto pelo terminal.
Entrada:
    No *L: Lista onde ser� inserido os elementos no conjunto.
Saida:
    ponteiro para a Lista resultante da leitura.
*/
No *lerConjunto(No *L);

/*
Funcao: insercaoConjunto
Descricao: Faz as opera��es de inser��o de um conjunto.
Entrada:
    No *L: Lista onde ser� alterado ou n�o os elementos de um conjunto.
Saida:
    ponteiro para a Lista resultante da leitura.
*/
No *insercaoConjunto(No *L);

/*
Funcao: operacao
Descricao: Faz as opera��es entre os conjuntos.
Entrada:
    No *L: Conjunto A.
    No *J: Conjunto B.
Saida:
    void.
*/
void operacao(No *L, No *J);

#endif

