#include <stdio.h>
#include <stdlib.h>

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

int troca(int *solu,int i,int j,int tam){
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
    }
    total += m[solu[j]-1][solu[0]-1];
    return total;

}

void cloneVector(int *copia, int *copiado, int tam){
    for(int i=0; i < tam; i++){
        copia[i] = copiado[i];
    }
    return;
}

void printVector(int *copia, int tam){
    for(int i=0; i < tam; i++){
        printf("%d\n", copia[i]);
    }
}



void twoOpt(int *solu, int tam){
    int novo[tam];
    int best[tam];
    int dist = CalcDist(solu, tam);
    printf("%d\n", dist);
    int min = dist;
    int k = 0;
    int l = 0;
        for (int i =0; i <= (tam-3); i++ ){
            for (int j = i+2; j <= (tam-1); j++ ){
                if (conflito(solu,i,j, tam) == 0){
                    cloneVector(novo,solu,tam);
                    troca(novo,i,j,tam);
                    dist = CalcDist(novo, tam);
                    if (dist <= min){
                        min = dist;
                        cloneVector(best,novo,tam);
                    }
                }   
            }
        }
        cloneVector(solu,best,tam);
        return;
}


int main(){
    int solu[5] =  {1,5,2,4,3};
    int tam = 5;
    for (int i = 0; i < 2; i++){
        twoOpt(solu,tam);
        printf("distancia: %d \n",CalcDist(solu,5) );
    }



}
