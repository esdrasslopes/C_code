#include <stdio.h>

float media(float n1, float n2, float ppd){
    return (n1 + n2 + ppd);
}

int main() {
    float n1, n2, n3, ppd, exameUnificado;
    int fezExam, fezN3;

    printf("Qual a sua nota da N1?");
    scanf("%f", &n1);

    if(n1 < 0 || n1 > 4.5){
        return 3;
    }

    printf("Qual a sua nota da N2?");
    scanf("%f", &n2);
    
    if(n2 < 0 || n2 > 4.5){
        return 3;
    }

    printf("Qual a sua nota do PPD?");
    scanf("%f", &ppd);
    
    if(ppd < 0 || ppd > 1.0){
        return 3;
    }

    float medias = media(n1,n2,ppd);

    printf("Voce fez o exame unificado? [0 para nao e 1 para sim]");
    scanf("%d", &fezExam);

    if(fezExam == 1){
        printf("Qual a nota do exame unificado?");
        scanf("%f", &exameUnificado);
        if(exameUnificado < 0 || exameUnificado > 1.0){
            do{
                printf("Nota invalida! Qual a nota do exame?");
                scanf("%f", &exameUnificado);
            }while(exameUnificado <0 || exameUnificado >1);
        }

        medias += exameUnificado;

        if( medias > 10){
            medias = 10;
        }
    }

    if(medias < 7){
        printf("Voce vai ter que fazer a N3\n");

        printf("Voce fez a N3? 0 para nao e 1 para sim\n");
        scanf("%d", &fezN3);


        if(fezN3 == 1){
            printf("Qual a sua nota da N3?");
            scanf("%f", &n3);

            while(n3 < 0 || n3 > 4.5){
                printf("Nota inválida! Qual a nota da N3? ");
                scanf("%f", &n3);
            }

            if(n1 < n2){
                n1 = n3;

            }else{
                n2 = n3;
                
            }


            medias = media(n1,n2,ppd) + exameUnificado;
        
        }
    }

    if(medias >= 7){
        printf("Voce foi aprovado com media %.2f", medias);
    }else{
        printf("Voce reprovou com media %.2f", medias);
    }


    return 0;
}