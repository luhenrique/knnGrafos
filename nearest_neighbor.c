#include <stdio.h>
#include <string.h>
#include <math.h>
#include "read_file.c"
#define INF 0x7F800000


int n_visited = 0;			
long size_of_path = 0;
char name_of_file[50];
int dimention;


void print_matrix(int s, int dim, int m[dim][dim]){
  for(int i = 0; i < s; i++){
    for(int j = 0; j < s; j++){
      printf("-- %i", m[i][j]);
    }
    printf("\n");
  }
}



void print_visited(int dim, int visited[dim]){
  for(int i =0; i<=n_visited; i++){
    printf("%i \n", visited[i]);
  }
}



void insert_into_visited(int elem, int dim, int visited[dim]){
  if(!was_element_visited(elem)){
    visited[n_visited] = elem;
  }
}




int was_element_visited(int elem, int dim, int visited[dim]){
  for(int i =0; i<=n_visited; i++){
    if (elem == visited[i])
	return 1;
  }
  return 0;
}

void construct (){
    printf("Digite o nome do arquivo\n");
   scanf("%s", name_of_file);
   dimention = get_dimention(name_of_file);
   int m[dimention][dimention];
   file_to_matrix(name_of_file, dimention, m);
   int visited[dimention];
   int solu[dimention];
   int tam = dimention;




  for(int k = 0; k<= dimention; k++){
    visited[k] = INF;
  }

  int shorter = INF;
  int first_i = 0;
  int next_i = first_i;
  int *current_v = m[next_i];


  for(int k = 0; k< dimention; k++){
    int shorter = 0x7F800000;
    int current_i = next_i;


    if(k==dimention-1){
      shorter = m[current_i][first_i];
      next_i = first_i;
      size_of_path += shorter;
    }

    else{

      for(int i = 0; i < dimention; i++){
        if(current_v[i] < shorter && current_i!=i && !was_element_visited(i, dimention, visited)){
          shorter = current_v[i];
          next_i = i;
        }
      }
      size_of_path += shorter;
      current_v = m[next_i];
    }
    insert_into_visited(current_i, dimention, visited);
    n_visited++;
    solu[k] = current_i;
    printf("\nDe %i para %i com custo %i",current_i,next_i, shorter);

  }
  printf("\nTamanho do caminho: %li\n", size_of_path);
  printf("noisSolu %d \n",CalcDist(solu,tam,dimention,m));
  twoOpt(solu,tam,dimention,m);
  printf("nois %d \n",CalcDist(solu,tam,dimention,m));

}


//2opt começa aqui ---------

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

int CalcDist(int *solu,int tam,int dim, int m[dim][dim]){
    int total = 0;
    for (int i = 0; i < (tam-1); i++){
    	total += m[solu[i]-1] [solu[i+1]-1];
    //	printf("de %d para %d eh %d\n",solu[i],solu[i+1], m[solu[i]-1] [solu[i+1]-1]);
    //	printf("total %d\n",total );
        
    }
    total += m[solu[tam-1]-1][((solu[0]))-1];
    //printf("de %d para %d eh: %d\n",(solu[tam-1]),((solu[0])), m[solu[tam-1]-1][((solu[0]))-1]);
   // printf("Soma: %d\n", total);
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

void twoOpt(int *solu, int tam, int dimention, int m[dimention][dimention]){
    int novo[tam];
    int best[tam];
    int dist = CalcDist(solu, tam, dimention, m);
    printf("%d\n", dist);
    int min = dist;
    int k = 0;
    int l = 0;
        for (int i =0; i <= (tam-3); i++ ){
            for (int j = i+2; j <= (tam-1); j++ ){
                if (conflito(solu,i,j, tam) == 0){
                    cloneVector(novo,solu,tam);
                    troca(novo,i,j,tam);
                    dist = CalcDist(novo, tam,dimention, m);
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



//-------------------


int main()
{
  construct();
  

  return 0;
}
