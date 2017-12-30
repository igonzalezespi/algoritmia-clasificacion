#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "selection_sort.h"

void selection_normal(int arr[], int n, double* comparaciones, double* intercambios) {
  int i, j, min_idx;

  for (i = 0; i < n-1; i++) {
    // Buscamos el elemento más pequeño en el array desordenado
    min_idx = i;
    for (j = i+1; j < n; j++) {
      *comparaciones += 1;
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }

    // Intercambiamos el elemento más pequeño con el primero, sean o no iguales
    *intercambios += 1;
    intercambia(&arr[min_idx], &arr[i]);
  }
}

void selection_mejorado(int arr[], int n, double* comparaciones, double* intercambios) {
  int i, j, min_idx;

  for (i = 0; i < n-1; i++) {
    // Buscamos el elemento más pequeño en el array desordenado
    min_idx = i;
    for (j = i+1; j < n; j++) {
      *comparaciones += 1;
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      // Intercambiamos el elemento más pequeño con el primero, sean o no iguales
      *intercambios += 1;
      intercambia(&arr[min_idx], &arr[i]);
    }
  }
}
