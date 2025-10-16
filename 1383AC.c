#include <stdio.h>
#include <stdlib.h>

int valido(int *vetor) {
    int seen[10] = {0};
    for (int i = 0; i < 9; i++) {
        int num = vetor[i];
        if (num < 1 || num > 9) return 0;
        if (seen[num]) return 0;
        seen[num] = 1;
    }
    return 1;
}

int matriz_valida(int **matriz) {
    int vetor[9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            vetor[j] = matriz[i][j];
        if (!valido(vetor)) return 0;
    }
    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 9; i++)
            vetor[i] = matriz[i][j];
        if (!valido(vetor)) return 0;
    }
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            int k = 0;
            for (int x = i; x < i + 3; x++)
                for (int y = j; y < j + 3; y++)
                    vetor[k++] = matriz[x][y];
            if (!valido(vetor)) return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int k = 1; k <= n; k++) {
        int **matriz = (int **) malloc(9 * sizeof(int *));
        for (int i = 0; i < 9; i++)
            matriz[i] = (int *) malloc(9 * sizeof(int));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                scanf("%d", &matriz[i][j]);
        printf("Instancia %d\n", k);
        if (matriz_valida(matriz))
            printf("SIM\n");
        else
            printf("NAO\n");
        printf("\n");
        for (int i = 0; i < 9; i++)
            free(matriz[i]);
        free(matriz);
    }
    return 0;
}
