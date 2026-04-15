#include <stdio.h>

int main(){
    int vetor[5];
    int posicao;

    for(int i = 0; i < 5; i++){
        printf("Informe valores ao vetor: 0 a 4: ");
        scanf("%d", &vetor[i]);
    }

    printf("Informe uma posição do vetor: ");
    scanf("%d", &posicao);

    if(posicao >= 0 && posicao < 5){
        printf("Valor na posição %d: %d\n", posicao, vetor[posicao]);
    } else {
        printf("Posição inválida. Por favor, informe um valor entre 0 e 4.\n");
    }
}
