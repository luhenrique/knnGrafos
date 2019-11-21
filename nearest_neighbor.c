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
    printf("%i\n", visited[i]);
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

    printf("\nDe %i para %i com custo %i",current_i,next_i, shorter);

  }
  printf("\nTamanho do caminho: %li\n", size_of_path);
}

void twoOptHeurist(){
  
}


int main()
{
  construct();
  return 0;
}
