// Marcelo Nogueira Neves
//
// Implementa fila utilizando lista ligada


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef _WIN32
#include <conio.h>   // Para getch() no Windows
#else
#include <termios.h> // Para Linux/macOS
#include <unistd.h>
#endif


typedef struct no {
    int numero;
    struct no *proximo;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
} Fila;


void inicializaFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int filavazia(Fila *f) {
    return (f->inicio == NULL);
}

void enfileirar(Fila *f, int valor) {
    NoFila *novoNo = malloc(sizeof(NoFila));
    if (!novoNo) {
        printf("\nERRO de alocação de memória\n");
        exit(-1);
    }
    novoNo->numero = valor;
    novoNo->proximo = NULL;

    if (f->fim == NULL) {
        f->inicio = novoNo;
    } else {
        f->fim->proximo = novoNo;
    }
    f->fim = novoNo;
}

int desenfileirar(Fila *f, int *valor) {
    if (filavazia(f))
        return 0;

    NoFila *temp = f->inicio;
    *valor = temp->numero;
    f->inicio = temp->proximo;

    if (f->inicio == NULL)
        f->fim = NULL;

    free(temp);
    return 1;
}

int frente(Fila *f, int *valor) {
    if (filavazia(f))
        return 0;

    *valor = f->inicio->numero;
    return 1;
}


// Função compatível com Windows e Linux
int pegacara() {
#ifdef _WIN32
    return toupper(getch());  // Windows: lê sem Enter
#else
    struct termios old_tio, new_tio;
    char ch;
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    return toupper(ch);
#endif
}

void clear_stdin_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main() {
    Fila f;
    inicializaFila(&f);
    int valor;
    char op = ' ';

    while (op != 'X') {
        printf("\nQual operacao o Enfileirar(E), Desenfileirar(D), Frente(F), FilaVazia(V) ou Sair(X): ");
        op = pegacara();
        printf("Entrou com: %c\n", op);

        switch (op) {
            case 'E':
                printf("Entre com valor: ");
                scanf("%d", &valor);
                clear_stdin_buffer();
                enfileirar(&f, valor);
                break;

            case 'D':
                if (desenfileirar(&f, &valor))
                    printf("Valor removido: %d\n", valor);
                else
                    printf("Fila vazia\n");
                break;

            case 'F':
                if (frente(&f, &valor))
                    printf("Valor na frente da fila: %d\n", valor);
                else
                    printf("Fila vazia\n");
                break;

            case 'V':
                if (filavazia(&f))
                    printf("A fila esta vazia.\n");
                else
                    printf("A fila contem elementos.\n");
                break;

            case 'X':
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida: %c\n", op);
                break;
        }
    }

    return 0;
}