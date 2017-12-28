#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "bubble_sort.h"

void bubble_normal(int arr[], int n, double* comparaciones, double* intercambios) {
  int i, j;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      *comparaciones += 1;
      if (arr[j] > arr[j+1]) {
        *intercambios += 1;
        intercambia(&arr[j], &arr[j+1]);
      }
    }
  }
}

void bubble_mejorado(int arr[], int n, double* comparaciones, double* intercambios) {
  int i, j;
  int intercambiado;
  for (i = 0; i < n-1; i++) {
    intercambiado = 0;
    for (j = 0; j < n-i-1; j++) {
      *comparaciones += 1;
      if (arr[j] > arr[j+1]) {
        *intercambios += 1;
        intercambiado = 1;
        intercambia(&arr[j], &arr[j+1]);
      }
    }

    // Si no se ha intercambiado nada, está ordenado. Terminamos.
    if (intercambiado == 0)
      break;
  }
}
