#include <stdio.h>
#include <math.h>
#include "trabalho.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main()
{
    int decimal, vezes, caracteres, b, i, j;
    char hexa[101];

    printf("Quantas mensagens voce vai decodificar? ");
    scanf("%d", &vezes);

    for(i = 0; i < vezes; i++){

        printf("Qual o valor de b? ");
        scanf("%d", &b);
        fflush(stdin);

        printf("Codigo para decodificacao: ");
        fgets(hexa,102,stdin);

        caracteres = strlen(hexa);

        for(j = 0; j < caracteres; j += 2){
            char vetores[3] = {0};
            vetores[0] = hexa[j];
            vetores[1] = hexa[j + 1];
            vetores[2]= '\0';


            decimal = strtol(vetores, NULL, 16);

            //O j/2 divide o vetor em pares de 2 e o +1 tem a finalidade de garantir que o array seja dividido em pares igual no for com o vetor recebendo  j +1. O b e o j/2+1 são levado para a função e realiza um cálculo. O decimal é composto pelos elementos do vetor então quando cada par do vetor é analizado eles são levados para o decimal.
            if(funcaoCalculo(j / 2 + 1, b) != 0){
                printf(" %c", decimal);
            } 
        }

        printf("\n\n");

        printf("Mensagem decodificada");
        break;
    }

    return 0;
}