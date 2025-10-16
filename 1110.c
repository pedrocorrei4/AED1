#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        int deck[100];
        for (int i = 0; i < n; i++) deck[i] = i + 1;
        int top = 0, bottom = n - 1;
        printf("Discarded cards:");
        int first = 1;
        while (bottom - top >= 1) {
            if (first) {
                printf(" %d", deck[top]);
                first = 0;
            } else {
                printf(", %d", deck[top]);
            }
            top++;
            deck[++bottom] = deck[top++];
        }
        printf("\nRemaining card: %d\n", deck[top]);
    }
    return 0;
}
