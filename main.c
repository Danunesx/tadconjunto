#include "arquivo.h"

int main(){
    No *A = NULL, *B = NULL;

    // Inser��o do conjunto A
    printf("Insira o conjunto A (cada elemento separado por virgula): ");
    A = lerConjunto(A);
    printf("A: ");
    imprime(A);
    A = insercaoConjunto(A);

    system("cls");
    getchar();

    // Inser��o do conjunto B
    printf("Insira o conjunto B (cada elemento separado por virgula): ");
    B = lerConjunto(B);
    printf("B: ");
    imprime(B);
    B = insercaoConjunto(B);

    // Opera��o entre os conjuntos
    operacao(A, B);

    return 0;
}

