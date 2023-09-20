#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void gerarArrayAleatorio(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; 
    }
}


void copiarArray(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}


void ordenarPorBolha(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                trocar(&arr[j], &arr[j+1]);
            }
        }
    }
}


int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}


void quicksort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);
        quicksort(arr, baixo, pi - 1);
        quicksort(arr, pi + 1, alto);
    }
}


void mesclar(int arr[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    
    int L[n1], R[n2];

    
    for (i = 0; i < n1; i++) {
        L[i] = arr[esquerda + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[meio + 1 + j];
    }

    
    i = 0;
    j = 0;
    k = esquerda;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergesort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        mergesort(arr, esquerda, meio);
        mergesort(arr, meio + 1, direita);
        mesclar(arr, esquerda, meio, direita);
    }
}

int main() {
    srand(time(NULL)); 

    int tamanhos[] = {1000, 5000, 10000, 50000, 100000}; 

    for (int i = 0; i < sizeof(tamanhos) / sizeof(tamanhos[0]); i++) {
        int tamanho = tamanhos[i];
        int *arr1 = (int *)malloc(tamanho * sizeof(int));
        int *arr2 = (int *)malloc(tamanho * sizeof(int));
        int *arr3 = (int *)malloc(tamanho * sizeof(int));

        gerarArrayAleatorio(arr1, tamanho);
        copiarArray(arr1, arr2, tamanho);
        copiarArray(arr1, arr3, tamanho);

        
        clock_t inicio = clock();
        ordenarPorBolha(arr1, tamanho);
        clock_t fim = clock();
        double tempoBolha = (double)(fim - inicio) / CLOCKS_PER_SEC;

        
        inicio = clock();
        quicksort(arr2, 0, tamanho - 1);
        fim = clock();
        double tempoQuicksort = (double)(fim - inicio) / CLOCKS_PER_SEC;

     
        inicio = clock();
        mergesort(arr3, 0, tamanho - 1);
        fim = clock();
        double tempoMergesort = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("Tamanho do array: %d\n", tamanho);
        printf("Tempo (ordenação por bolha): %f segundos\n", tempoBolha);
        printf("Tempo (quicksort): %f segundos\n", tempoQuicksort);
        printf("Tempo (mergesort): %f segundos\n", tempoMergesort);
        printf("\n");

        free(arr1);
        free(arr2);
        free(arr3);
    }

    return 0;
}

