#include <stdio.h>
#include <stdlib.h>

void buscaSequencialMatriz(int matriz[][3], int linhas, int colunas, int valor, int *linhaEncontrada, int *colunaEncontrada) {
    *linhaEncontrada = -1; 
    *colunaEncontrada = -1; 

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == valor) {
                
                *linhaEncontrada = i;
                *colunaEncontrada = j;
                return; 
            }
        }
    }
}

int main() {
    int matriz[][3] = {{3, 2, 1}, {6, 5, 4}, {9, 8, 7}};
    int linhas = sizeof(matriz) / sizeof(matriz[0]);
    int colunas = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    int valorProcurado;
    printf("Digite o valor a ser procurado na matriz: ");
    scanf("%d", &valorProcurado);

    int linhaEncontrada, colunaEncontrada;
    buscaSequencialMatriz(matriz, linhas, colunas, valorProcurado, &linhaEncontrada, &colunaEncontrada);

    if (linhaEncontrada != -1) {
        printf("Valor encontrado na posição (%d, %d)\n", linhaEncontrada, colunaEncontrada);
    } else {
        printf("Valor não encontrado na matriz.\n");
    }

    return 0;
}

