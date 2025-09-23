#include <stdio.h>
#include <stdlib.h>


int main() {
    int num;

    float soma=0;
    float *vetor;
    float min;
    float max;

    printf("\nQuantos numeros na sua serie (N):");
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

        if(i == 0) { 
            // inicializa min e max com o primeiro valor
            min = max = vetor[i];
        } 
        else {
            if(vetor[i] < min) min = vetor[i];
            if(vetor[i] > max) max = vetor[i];
        }
    }

    printf("Media: %.2f\n", soma/num);
    printf("Valor minimo: %.2f\n", min);
    printf("Valor maximo: %.2f\n", max);

    free(vetor); // libera a memória alocada

    return 0;

}