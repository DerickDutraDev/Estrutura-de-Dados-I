#include <stdio.h>
#include <string.h>

int main(){
    int vetor[5];
    int maior;
    int menor;

    for(int i = 0; i < 5; i++){
        printf("Informe valores ao vetor: 0 a 4: ");
        scanf("%d", &vetor[i]);
    }

    maior = vetor[0];
    menor = vetor[0];

    
    printf("Vetor completo: ");
    for(int j = 0; j < 5; j++){
        printf("%d ", vetor[j]);
        if(vetor[j] > maior){
            maior = vetor[j];
        }
        if(vetor[j] < menor){
            menor = vetor[j];
        }
    }
    printf("\nMaior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
}