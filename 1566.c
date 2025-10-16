#include <stdio.h>
#include <string.h>

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC--) {
        int N;
        scanf("%d", &N);

        int count[231] = {0};
        int h;

        for (int i = 0; i < N; i++) {
            scanf("%d", &h);
            count[h]++;
        }

        int first = 1;
        for (int i = 20; i <= 230; i++) {
            while (count[i]--) {
                if (first) {
                    printf("%d", i);
                    first = 0;
                } else {
                    printf(" %d", i);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
