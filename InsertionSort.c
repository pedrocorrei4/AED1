#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50000 
void gerarVetor(int v[]) {
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {

        v[i] = rand() % 100001;
    }
}


void InsertionSort(int v[])
{
    for (int i = 1; i < TAM; i++) {
        int aux = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = aux;
    }
}

int main() {
    clock_t t; 
    int v[TAM]; 

    gerarVetor(v);
    t = clock();
    InsertionSort(v);
    t = clock() - t; 
    printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000))); /* conversão para double */
}
