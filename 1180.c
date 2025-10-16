#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);  
    
    int X[1000];  
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &X[i]);  
    }
    
    int menor = X[0]; 
    int posicao = 0;     
    
    for(int i = 1; i < N; i++) {
        if(X[i] < smallest) {
            smallest = X[i];  
            position = i;    
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);
    
    return 0;
}
