#include "arquivo.h"

No *criaNo(int ch){
    No *novo = (No*)malloc(sizeof(No));

    if(!novo){
        printf("Erro de alocacao");
        exit(1);
    }
    novo->chave = ch;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

No *insere(No *L, int ch){
    No *novo = criaNo(ch);
    No *aux = busca(L, ch);

    if(vazia(L)) L = novo;
    else {
        if(aux->chave != ch){
            aux->prox = novo;
            novo->ant = aux;
        }
        else return L;
    }
    return L;
}

No *removeChave(No *L, int ch){
    No *aux = busca(L, ch);

    if(aux->chave == ch){
        if(aux->ant == NULL) L = aux->prox; // primeiro elemento
        else aux->ant->prox = aux->prox;  // final da lista
        if(aux->prox != NULL) aux->prox->ant = aux->ant; // meio da lista
        free(aux); // unico no da lista
    }
    return L;
}

void imprime(No *L){
    No *aux = L;

    while(aux != NULL){
        printf("|%d|->", aux->chave);
        aux = aux->prox;
    }
    printf("\n\n");
}

No *esvazia(No *L){
    No *aux = L, *aux2 = L;

    while(aux != NULL){
        L = L->prox;
        if(aux->prox != NULL) aux->prox->ant = aux->ant;
        aux2 = aux2->prox;
        free(aux);
        aux = aux2;
    }
    return L;
}

int vazia(No *L){
    if(!L) return 1;
    else return 0;
}

int buscaElemento(No *L, int ch){
    No *aux = L;

    while(aux->prox != NULL){
        if(aux->chave == ch) break;
        aux = aux->prox;
    }
    if(aux->chave == ch){
        return 1;
    } else return 0;
}

No *uniao(No *L, No* J, No* K){
    No *aux = L, *aux2 = J;

    while(aux != NULL){
        K = insere(K, aux->chave);
        aux = aux->prox;
    }
    while(aux2 != NULL){
        K = insere(K, aux2->chave);
        aux2 = aux2->prox;
    }
    return K;
}

No *intersecao(No *L, No *J, No *K){
    No *aux = L, *aux2 = J, *aux3 = J;

    while(aux != NULL){
        while(aux2 != NULL){
            if(aux->chave == aux2->chave)
                K = insere(K, aux->chave);
            aux2 = aux2->prox;
        }
        aux2 = aux3;
        aux = aux->prox;
    }
    return K;
}

int iguais(No *L, No *J){
    No *aux = L, *aux2 = J, *aux3 = J;
    int soma = 0, tamL = 0, tamJ = 0;

    while(aux != NULL){
        while(aux2 != NULL){
            if(aux->chave == aux2->chave)
                soma++;
            aux2 = aux2->prox;
        }
        aux2 = aux3;
        aux = aux->prox;
    }
    tamL = tamanho(L);
    tamJ = tamanho(J);

    if(soma == tamL && soma == tamJ) return 1;
    else return 0;
}

int subconjunto(No *L, No *J){
    No *aux = L, *aux2 = J, *aux3 = J;
    int soma = 0, tamL = 0, tamJ = 0;

    while(aux != NULL){
        while(aux2 != NULL){
            if(aux->chave == aux2->chave)
                soma++;
            aux2 = aux2->prox;
        }
        aux2 = aux3;
        aux = aux->prox;
    }
    tamL = tamanho(L);
    tamJ = tamanho(J);

    if(soma == tamL || soma == tamJ) return 1;
    else return 0;
}

No *relativo(No *L, No *J, No *K){
    No *aux = L, *aux2 = J, *aux3 = J;

    K = uniao(L, J, K);

    while(aux != NULL){
        while(aux2 != NULL){
            if(aux->chave == aux2->chave)
                K = removeChave(K, aux->chave);
            aux2 = aux2->prox;
        }
        aux2 = aux3;
        aux = aux->prox;
    }
    return K;
}

int tamanho(No* L){
    int tam = 0;
    No *aux = L;

    while(aux != NULL){
        tam++;
        aux = aux->prox;
    }
    return tam;
}

No *busca(No *L, int ch){
    No *aux = L;

    if(!vazia(L)){
        while(aux->prox != NULL){
            if(aux->chave == ch) break;
            aux = aux->prox;
        }
    }
    return aux;
}

void menu1(){
    printf("OPERACOES COM CONJUNTOS");
    printf("\n1 - Remover Chave");
    printf("\n2 - Esvazia Conjunto");
    printf("\n3 - Verificar Conjunto Vazio");
    printf("\n4 - Buscar Elemento");
    printf("\n5 - Sair");
    printf("\n\nOperacao: ");
}

void menu2(){
    printf("OPERACOES COM CONJUNTOS");
    printf("\n1 - Subconjunto");
    printf("\n2 - Conjuntos Iguais");
    printf("\n3 - Uniao");
    printf("\n4 - Intersecao");
    printf("\n5 - Relativo");
    printf("\n6 - Sair");
    printf("\n\nOperacao: ");
}

No *lerConjunto(No *L){
    char conjunto[100];
    char *sub;
    int ch;

    fgets(conjunto, 100, stdin);

    sub = strtok(conjunto, ",");
    while(sub != NULL){

        ch = strtol(sub, &sub, 10);
        L = insere(L, ch);
        sub = strtok(NULL, ",");
    }
    return L;
}

No *insercaoConjunto(No *L){
     int op, ch;

     while(op != 5){
        menu1();
        scanf(" %d", &op);
        switch(op){
        case 1:
            printf("Chave a ser removida: ");
            scanf(" %d", &ch);
            L = removeChave(L, ch);
            system("cls");
            printf("\nNOVO CONJUNTO: ");
            imprime(L);
            break;
        case 2:
            L = esvazia(L);
            printf("\n");
            break;
        case 3:
            if(vazia(L)) printf("\nConjunto vazio\n\n");
            else printf("\nConjunto NAO vazio\n\n");
            break;
        case 4:
            printf("Chave a ser buscada: ");
            scanf(" %d", &ch);
            if(buscaElemento(L, ch)) printf("Elemento existe\n\n");
            else printf("Elemento NAO existe!\n\n");
            break;
        case 5:
            break;
        default:
            printf("Numero invalido!");
            break;
        }
    }
    return L;
}

void operacao(No *L, No *J){
    No *C = NULL, *D = NULL, *E = NULL;
    int op;

    system("cls");
    printf("A: ");
    imprime(L);
    printf("B: ");
    imprime(J);
    while(op != 6){
        menu2();
        scanf(" %d", &op);
        switch(op){
        case 1:
            if(subconjunto(L, J)) printf("Subconjunto\n\n");
            else printf("NAO esta contido\n\n");
            break;
        case 2:
            if(iguais(L, J)) printf("Conjuntos iguais\n\n");
            else printf("Conjuntos diferentes\n\n");
            break;
        case 3:
            C = uniao(L, J, C);
            printf("A U B: ");
            imprime(C);
            break;
        case 4:
            D = intersecao(L, J, D);
            printf("A <-> B: ");
            imprime(D);
            break;
        case 5:
            E = relativo(L, J, E);
            printf("A - B: ");
            imprime(E);
            break;
        case 6:
            system("cls");
            printf("Suas operacoes: \n");
            printf("A: ");
            imprime(L);
            printf("B: ");
            imprime(J);
            if(!vazia(C)){
                printf("A U B: ");
                imprime(C);
            }
            if(!vazia(D)){
                printf("A <-> B: ");
                imprime(D);
            }
            if(!vazia(E)){
                printf("A - B: ");
                imprime(E);
            }
            break;
        default:
            printf("Numero invalido!");
            break;
        }
    }
}
