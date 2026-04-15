#include <stdio.h>

// Função recursiva para calcular o n-ésimo termo de Fibonacci
// Sequência: F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)
int fibonacci(int n){
    if(n <= 1){
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    int n = 10;
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
    return 0;
}
