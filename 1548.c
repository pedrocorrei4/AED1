#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int N;
    scanf("%d", &N);

    for (int t = 0; t < N; t++) {
        int M;
        scanf("%d", &M);

        int notas[M];
        for (int i = 0; i < M; i++) {
            scanf("%d", &notas[i]);
        }

        int notas_ordenadas[M];
        for (int i = 0; i < M; i++) {
            notas_ordenadas[i] = notas[i];
        }

        qsort(notas_ordenadas, M, sizeof(int), comparar);

        int count = 0;
        for (int i = 0; i < M; i++) {
            if (notas[i] == notas_ordenadas[i]) {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
