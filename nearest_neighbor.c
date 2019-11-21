#include <stdio.h>
#include <string.h>
#include <math.h>
#include "read_file.c"
#define INF 0x7F800000
#define atsp 19


void printMatrix();
void printVisited();
void insertVisited();
int wasVisited();
void constructMatrix();

int n_visited = 0;			
long size_of_path = 0;
char name_of_file[50];
int dimention;




int main()
{

  constructMatrix();

  return 0;
  
}

void constructMatrix(){
   char *names [19] = {"br17.atsp", "ftv33.atsp", "ftv35.atsp", "ftv38.atsp", "p43.atsp", "ftv44.atsp", "ftv47.atsp", "ry48p.atsp", "ft53.atsp", "ftv55.atsp", "ftv64.atsp", "ft70.atsp", "ftv70.atsp", "kro124p.atsp", "ftv170.atsp", "rbg323.atsp", "rbg358.atsp", "rbg403.atsp", "rbg443.atsp"};
  int dimention[19] = {17, 33, 35, 38, 43, 44, 47, 48, 53, 55, 64, 70, 70, 124, 170, 323, 358, 403, 443};

  int dimentionMatrix = dimention[0];

  

   int m[dimentionMatrix][dimentionMatrix];
   fileMatrix(names[0], dimentionMatrix, m);
   int visited[dimentionMatrix];



  //Inicializa o vetor de visitados com um valor que nunca será usado
  for(int k = 0; k<= dimentionMatrix; k++){
    visited[k] = INF;
  }

  int shorter = INF;
  int first_i = 0;
  int next_i = first_i;
  int *current_v = m[next_i];

  //Esse FOR realiza um número de iterações igual ao número de nós totais.
  for(int k = 0; k< dimentionMatrix; k++){
    int shorter = 0x7F800000;
    int current_i = next_i;

    //Se for a ultima iteração, volte ao nó inicial
    if(k==dimentionMatrix-1){
      shorter = m[current_i][first_i];
      next_i = first_i;
      size_of_path += shorter;
    }
    //Se não for a ultima iteração, continue
    else{
      //Esse for checa qual é o caminho mais barato para um nó não visitado
      for(int i = 0; i < dimentionMatrix; i++){
        if(current_v[i] < shorter && current_i!=i && !wasVisited(i, dimentionMatrix, visited)){
          shorter = current_v[i];
          next_i = i;
        }
      }
      size_of_path += shorter;
      current_v = m[next_i];
    }
    insertVisited(current_i, dimentionMatrix, visited);
    n_visited++;
    //printf("%lu\n", (unsigned long) randomMT());
    printf("\nDe %i para %i com custo %i",current_i,next_i, shorter);
    //printVisited();
    //printf("\n");
  }
  printf("\nTamanho do caminho: %li\n", size_of_path);
  
    for(int i = 0; i < dimentionMatrix; i++){
    for(int j = 0; j < dimentionMatrix; j++){
      printf("-- %i", m[i][j]);
    }
    printf("\n");
  }
  
}

//A função printMatrix printa matrix carregada no problema
void printMatrix(int s, int dim, int m[dim][dim]){
  for(int i = 0; i < s; i++){
    for(int j = 0; j < s; j++){
      printf("-- %i", m[i][j]);
    }
    printf("\n");
  }
}


//A função printVisited printa os nós que ja foram visitados.
void printVisited(int dim, int visited[dim]){
  for(int i =0; i<=n_visited; i++){
    printf("%i\n", visited[i]);
  }
}


//A função insertVisited insere um nós no vetor de visitados
void insertVisited(int elem, int dim, int visited[dim]){
  if(!wasVisited(elem)){
    visited[n_visited] = elem;
  }
}



//Essa função checa se determinado nó já foi visitado
int wasVisited(int elem, int dim, int visited[dim]){
  for(int i =0; i<=n_visited; i++){
    if (elem == visited[i])
	return 1;
  }
}

