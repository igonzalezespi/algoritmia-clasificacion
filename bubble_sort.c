#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "bubble_sort.h"

void bubble_normal(int array[], int tam, double* comparaciones, double* intercambios) {
  int i, j;
  for (i = 0; i < tam-1; i++) {
    for (j = 0; j < tam-i-1; j++) {
      *comparaciones += 1;
      if (array[j] > array[j+1]) {
        *intercambios += 1;
        intercambia(&array[j], &array[j+1]);
      }
    }
  }
}

void bubble_mejorado(int array[], int tam, double* comparaciones, double* intercambios) {
  int i, j;
  int intercambiado = 0;
  for (i = 0; i < tam-1; i++) {
    for (j = 0; j < tam-i-1; j++) {
      *comparaciones += 1;
      if (array[j] > array[j+1]) {
        *intercambios += 1;
        intercambia(&array[j], &array[j+1]);
        intercambiado = 1;
      }
    }
    if (intercambiado == 0) {
      break;
    }
  }
}
