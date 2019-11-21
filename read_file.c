#include <stdio.h>

#include <ctype.h>

#include <math.h>


int get_dimention(char name[50]) {
  FILE * file;
  file = fopen(name, "r");
  char ch;
  int reached_dimention = 0;
  char last_char;
  int p = 0;
  int value;
  int preview_is_digit = 0;
  int dimention;
  long count_itens = 0;

  while ((ch = fgetc(file)) != EOF) {

    if (ch == 'D' && reached_dimention == 0) {
      reached_dimention++;
      last_char = 'D';
    } else if (ch == 'I' && reached_dimention == 1 && last_char == 'D') {
      reached_dimention++;
      last_char = 'I';
    } else if (ch == 'M' && reached_dimention == 2 && last_char == 'I') {
      reached_dimention++;
      last_char = 'M';
    } else if (ch == 'E' && reached_dimention == 3 && last_char == 'M') {
      reached_dimention++;
      last_char = 'E';
    } else if (ch == 'N' && reached_dimention == 4 && last_char == 'E') {
      reached_dimention++;
      last_char = 'N';
    } else if (ch == 'S' && reached_dimention == 5 && last_char == 'N') {
      reached_dimention++;
      last_char = 'S';
    } else if (ch == 'I' && reached_dimention == 6 && last_char == 'S') {
      reached_dimention++;
      last_char = 'I';
    } else if (ch == 'O' && reached_dimention == 7 && last_char == 'I') {
      reached_dimention++;
      last_char = 'O';
    } else if (ch == 'N' && reached_dimention == 8 && last_char == 'O') {
      reached_dimention++;
      last_char = 'N';
    } else if (ch == ':' && reached_dimention == 9 && last_char == 'N') {
      reached_dimention++;
    }

    if (reached_dimention == 10) {
      if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9') {
        if (preview_is_digit) {
          p++;
          dimention = 10 * dimention + (ch - '0');
        } else {
          dimention = ch - '0';
          preview_is_digit = 1;
        }
      } else {
        if (preview_is_digit) {
          //printf("DIMENSAO: %d\n", dimention);
          return dimention;
        }
        preview_is_digit = 0;
        value = 0;
        p = 0;
      }
    }
  }

}


void file_to_matrix(char name[50], int dimention, int matrix[dimention][dimention]) {
  FILE * file;
  file = fopen(name, "r");
  char ch;
  int reached_dimention = 0;
  char last_char;
  int p = 0;
  int value;
  int preview_is_digit = 0;
  int list[1000000] = {};
  long count_itens = 0;
  int aux = 0;

  while ((ch = fgetc(file)) != EOF) {
    if (reached_dimention == 0) {
      if (ch == 'E' && aux == 0) {
        aux++;
        last_char = 'E';
      } else if (ch == 'D' && aux == 1 && last_char == 'E') {
        aux++;
        last_char = 'D';
      } else if (ch == 'G' && aux == 2 && last_char == 'D') {
        aux++;
        last_char = 'G';
      } else if (ch == 'E' && aux == 3 && last_char == 'G') {
        aux++;
        last_char = 'E';
      } else if (ch == '_' && aux == 4 && last_char == 'E') {
        aux++;
        last_char = '_';
      } else if (ch == 'W' && aux == 5 && last_char == '_') {
        aux++;
        last_char = 'W';
      } else if (ch == 'E' && aux == 6 && last_char == 'W') {
        aux++;
        last_char = 'E';
      } else if (ch == 'I' && aux == 7 && last_char == 'E') {
        aux++;
        last_char = 'I';
      } else if (ch == 'G' && aux == 8 && last_char == 'I') {
        aux++;
        last_char = 'G';
      } else if (ch == 'H' && aux == 9 && last_char == 'G') {
        aux++;
        last_char = 'H';
      } else if (ch == 'T' && aux == 10 && last_char == 'H') {
        aux++;
        last_char = 'T';
      } else if (ch == '_' && aux == 11 && last_char == 'T') {
        aux++;
        last_char = '_';
      } else if (ch == 'S' && aux == 12 && last_char == '_') {
        aux++;
        last_char = 'S';
      } else if (ch == 'E' && aux == 13 && last_char == 'S') {
        aux++;
        last_char = 'E';
      } else if (ch == 'C' && aux == 14 && last_char == 'E') {
        aux++;
        last_char = 'C';
      } else if (ch == 'T' && aux == 15 && last_char == 'C') {
        aux++;
        last_char = 'T';
      } else if (ch == 'I' && aux == 16 && last_char == 'T') {
        aux++;
        last_char = 'I';
      } else if (ch == 'O' && aux == 17 && last_char == 'I') {
        aux++;
        last_char = 'O';
      } else if (ch == 'N' && aux == 18 && last_char == 'O') {
        printf("EDGE_WEIGHT_SECTION\n");
        reached_dimention = 1;
      } else {
        aux = 0;
      }
    }

    if (reached_dimention == 1) {
      if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9') {
        if (preview_is_digit) {
          p++;
          value = 10 * value + (ch - '0');
          //printf("%d\n", value);
        } else {
          value = ch - '0';
          //printf("%d\n", value); 
          preview_is_digit = 1;
        }
      } else {
        if (preview_is_digit) {
          list[count_itens] = value;
          count_itens++;
        }
        preview_is_digit = 0;
        value = 0;
        p = 0;
      }
    }
  }

  for (long k = 0; k < dimention * dimention; k++) {
    int j = k % dimention;
    int i = (int)(k / dimention);
    matrix[i][j] = list[k];
  }

}
/*
int main() {

  char name_of_file[50] = "rbg403.atsp";
  int dimention = get_dimention(name_of_file);
  printf("DIMENTION: %d\n", dimention);
  int matrix[dimention][dimention];
  file_to_matrix(name_of_file, dimention, matrix);

  for (int i = 0; i < dimention; i++) {
    for (int j = 0; j < dimention; j++) {
      printf("%d --- ", matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}*/
