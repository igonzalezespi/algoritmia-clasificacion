#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "selection_sort.h"

void selection_normal(int array[], int tam, double* comparaciones, double* intercambios) {
  int i, j, pos;

  for (i = 0; i < tam-1; i++) {
    // Buscamos el elemento más pequeño en el array desordenado
    pos = i;
    for (j = i+1; j < tam; j++) {
      *comparaciones += 1;
      if (array[j] < array[pos]) {
        pos = j;
      }
    }
    // Intercambiamos el elemento más pequeño con el primero, sean o no iguales
    *intercambios += 1;
    intercambia(&array[pos], &array[i]);
  }
}

void selection_mejorado(int array[], int tam, double* comparaciones, double* intercambios) {
  int i, j, pos;

  for (i = 0; i < tam-1; i++) {
    // Buscamos el elemento más pequeño en el array desordenado
    pos = i;
    for (j = i+1; j < tam; j++) {
      *comparaciones += 1;
      if (array[j] < array[pos]) {
        pos = j;
      }
    }
    *comparaciones += 1;
    if (pos != i) {
      // Intercambiamos el elemento más pequeño con el primero, sean o no iguales
      *intercambios += 1;
      intercambia(&array[pos], &array[i]);
    }
  }
}
