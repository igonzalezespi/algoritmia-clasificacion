#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void intercambia(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void imprime_resultados(char titulo[], double comparaciones, double intercambios, double performance) {
  printf("###### %s ######\n", titulo);
  printf("Comparaciones: %.0lf\n", comparaciones);
  printf("Intercambios:  %.0lf\n", intercambios);
  printf("Rendimiento: %d s y %d ms\n", (int)performance/1000, (int)performance%1000);
  printf("\n");
}

void lee_fichero(char nombre[], int enteros[]) {
  FILE *archivo = fopen(nombre, "r");

  int i=0;
  int num;
  while(fscanf(archivo, "%d", &num) > 0) {
    enteros[i] = num;
    i++;
  }
  fclose(archivo);
}

void escribe_fichero(char nombre[], int enteros[], int n) {
  int i;
  FILE *archivo = fopen(nombre, "w");

  for (i = 0; i<n; i++) {
    fprintf(archivo, "%d", enteros[i]);
    fprintf(archivo, "\n");
  }
  fclose(archivo);
}
