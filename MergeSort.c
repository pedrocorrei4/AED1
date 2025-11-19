#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50000 /* constante para definir tamanho do vetor */

void gerarVetor(int v[]) {
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % 100001;
    }
}


void intercalar(int v[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;


    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = v[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[meio + 1 + j];

  
    int i = 0, j = 0, k = inicio;

  
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;


        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);

        intercalar(v, inicio, meio, fim);
    }
}

int main() {
    clock_t t; 
    int v[TAM]; 

    gerarVetor(v);
    t = clock(); 
    mergeSort(v, 0, TAM - 1);
    t = clock() - t;
    printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000))); /* conversão para double */
}
