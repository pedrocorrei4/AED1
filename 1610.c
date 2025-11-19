#include <stdio.h>
#include <string.h>

#define MAXN 10005
#define MAXM 30005

int head[MAXN], to[MAXM], next[MAXM], edge_count;
int color[MAXN]; 
int hasCycle;

void init(int n) {
    memset(head, -1, sizeof(int) * (n + 1));
    memset(color, 0, sizeof(int) * (n + 1));
    edge_count = 0;
    hasCycle = 0;
}

void addEdge(int a, int b) {
    to[edge_count] = b;
    next[edge_count] = head[a];
    head[a] = edge_count++;
}

void dfs(int v) {
    if (hasCycle) return;

    color[v] = 1;

    for (int e = head[v]; e != -1; e = next[e]) {
        int u = to[e];

        if (color[u] == 1) {
            hasCycle = 1;
            return;
        }
        if (color[u] == 0)
            dfs(u);
    }

    color[v] = 2;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        init(N);

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            addEdge(A, B);
        }

        for (int i = 1; i <= N && !hasCycle; i++) {
            if (color[i] == 0)
                dfs(i);
        }

        if (hasCycle)
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}
