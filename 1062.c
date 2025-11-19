#include <stdio.h>

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {
        while (1) {
            int desired[1001];
            scanf("%d", &desired[0]);

            if (desired[0] == 0) {
                printf("\n");
                break;
            }

            for (int i = 1; i < N; i++)
                scanf("%d", &desired[i]);

            int stack[1001], top = 0;
            int next_push = 1;
            int possible = 1;

            for (int i = 0; i < N; i++) {
                int target = desired[i];

                while (next_push <= N && (top == 0 || stack[top - 1] != target)) {
                    stack[top++] = next_push++;
                }

                if (stack[top - 1] == target) {
                    top--;
                } else {
                    possible = 0;
                    break;
                }
            }

            if (possible) printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}
