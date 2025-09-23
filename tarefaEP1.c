#include <stdio.h>
#include <stdlib.h>


int main() {
    int num;

    float soma=0;
    float *vetor;

    printf("\nQuantos numeros na sua serie (N): ");
    scanf("%d", &num);
    
    vetor = malloc( num * sizeof(float));
    if(vetor==NULL) { //ERRO DE ALOCAÇÃO DE MEMÓRIA!
        printf("ERRO DE ALOCACAO DE MEMORIA!");
        exit(-1);
    }
    printf("Entre com os numeros:\n");
    for(int i=0; i<num; i++) {
        printf("> ");
        scanf("%f", &vetor[i]);
        soma+=vetor[i];
    }
    printf("Media: %.2f\n", soma/num);

}