#include <stdio.h>
#include <stdlib.h	>

void ordenarLinhaPorInsercao(int arr[], int tamanho) {
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {
        chave = arr[i];
        j = i - 1;

     
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}


void ordenarMatrizPorInsercao(int matriz[][3], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        ordenarLinhaPorInsercao(matriz[i], colunas);
    }
}

int main() {
    int matriz[][3] = {{3, 2, 1}, {6, 5, 4}, {9, 8, 7}};
    int linhas = sizeof(matriz) / sizeof(matriz[0]);
    int colunas = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    printf("Matriz original:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    ordenarMatrizPorInsercao(matriz, linhas, colunas);

    printf("\nMatriz ordenada por insercao:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

