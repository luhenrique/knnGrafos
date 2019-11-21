#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    int m [5][5] = {{9999,2,3,4,5},{6,9999,8,9,9},{1,4,9999,7,8},{3,6,9,9999,3},{2,5,7,9,9999}};

int conflito(int *solu,int i,int j,int tam){
    if (i == j ){
        return 1;
    }
    else if ((i+1) == j){
        return 1;
    }else if (j== tam-1){
        return 1;
    }
    return 0;
}

int troca (int *solu,int i,int j,int tam){
    int aux;
    aux = solu[i + 1];
    solu[i + 1] = solu[j];
    solu[j] = aux;
    return *solu;
}

int CalcDist(int *solu,int tam){
    int total = 0;
    int j =0;
    for (int i = 0; i < (tam-1); i++){
        j++;
        total += m[solu[i]-1][solu[i+1]-1];
            printf(" %d %d \n", m[solu[i]-1][solu[i +1]-1], total);
    }
    //printf("%d\n %d\n",solu[j]-1,solu[0]-1);
    total += m[solu[j]-1][solu[0]-1];
    //printf("total: %d\n",total );
    printf(" %d %d \n", m[solu[j]-1][solu[0]-1], total);
    return total;

}

int twoOpt(int *solu, int tam){
    int novo[tam];
    int best[tam];
    int dist = CalcDist(solu, tam);
    int min = dist;
    int k = 0;
        for (int i =0; i <= (tam-3); i++ ){
            printf("for 1\n");
            for (int j = i+2; j <= (tam-1); j++ ){
                printf("for 2\n");
                if (conflito(solu,i,j, tam) == 0){
                    printf("if 1 antes da troca\n");
                    troca(solu,i,j,tam);
                    printf("if 1 depois da troca\n");
                    while (k < tam){
                        novo[k] = solu[k];
                        printf("dentro do  1 while\n");
                        k++;
                    }
                    dist = CalcDist(novo, tam);
                    if (dist <= min){
                        printf("if 2 antes do while\n");
                        min = dist;
                        while (k < tam){
                            printf("dentro do  2 while\n");
                            best[k] = novo[k];
                            k++;
                        }
                    }
            }
        }
    }
     while (k < tam){
        solu[k] = best[k];
        printf("dentro do  3 while\n");
        k++;
    }
}


int main(){
    int solu[5] =  {1,5,2,4,3};
    int tam = 5;
    CalcDist(solu,5);
    twoOpt(solu,5);
    int h=0;
    while (h < tam){
                        printf("%i\n",solu[h]);
                        h++;
                    }
                    printf("%d\n", CalcDist(solu,5));
}