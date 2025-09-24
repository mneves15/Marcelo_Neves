#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

// Função de comparação usada pelo qsort
int compara_floats(const void *a, const void *b) {
    float fa = *(const float*)a;
    float fb = *(const float*)b;
    if (fa < fb) return -1;
    else if (fa > fb) return 1;
    else return 0;
}

int main() {
    int num;

    float soma=0;
    float *vetor;
    float min;
    float max;
    float media;
    float mediana;
    float desvio;

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

    // Calcula a média
    media = soma / num;

    // Ordena o vetor para calcular a mediana
    qsort(vetor, num, sizeof(float), compara_floats);

    if(num % 2 == 1) {
        // Se ímpar, a mediana é o valor do meio
        mediana = vetor[num / 2];
    } 
    else {
        // Se par, a mediana é a média dos dois do meio
        mediana = (vetor[(num / 2) - 1] + vetor[num / 2]) / 2.0;
    }

    // Calcula o desvio padrão
    float soma_quadrados = 0;
    for(int i = 0; i < num; i++) {
        soma_quadrados += (vetor[i] - media) * (vetor[i] - media);
    }
    desvio = sqrt(soma_quadrados / num);


    printf("Valor minimo: %.2f\n", min);
    printf("Valor maximo: %.2f\n", max);
    printf("Media: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Desvio padrao: %.13f\n", desvio);

    free(vetor); // libera a memória alocada

    return 0;

}