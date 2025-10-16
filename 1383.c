#include <stdio.h>

int valido(int vetor[9]) {
    int i, seen[10] = {0};
    for (i = 0; i < 9; i++) {
        int num = vetor[i];
        if (num < 1 || num > 9) return 0;  
        if (seen[num]) return 0;          
        seen[num] = 1;
    }
    return 1;
}

int matriz_valida(int matriz[9][9]) {
    int i, j, x, y;
    int vetor[9];
    
    // Verifica linhas
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) vetor[j] = matriz[i][j];
        if (!valido(vetor)) return 0;
    }

    // Verifica colunas
    for (j = 0; j < 9; j++) {
        for (i = 0; i < 9; i++) vetor[i] = matriz[i][j];
        if (!valido(vetor)) return 0;
    }

    // Verifica submatrizes 3x3
    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            int k = 0;
            for (x = i; x < i + 3; x++) {
                for (y = j; y < j + 3; y++) {
                    vetor[k++] = matriz[x][y];
                }
            }
            if (!valido(vetor)) return 0;
        }
    }

    return 1;
}

int main() {
    int n, k, i, j;
    int matriz[9][9];

    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        for (i = 0; i < 9; i++)
            for (j = 0; j < 9; j++)
                scanf("%d", &matriz[i][j]);

        printf("Instancia %d\n", k);
        if (matriz_valida(matriz))
            printf("SIM\n");
        else
            printf("NAO\n");
        printf("\n");
    }

    return 0;
}
