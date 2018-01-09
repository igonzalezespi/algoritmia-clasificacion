#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

// Limpia la pantalla
void cls() {
  system("cls");
}

// Pause la aplicación
void pause() {
  system("pause");
}

void intercambia(int* a, int* b) {
  if (a != b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
  }
}

void imprime_resultados(char titulo[], resultados_ordenacion resultados) {
  printf("####### %s ####### \n", titulo);
  printf(" -- Resultados teoricos \n");
  printf("    Comparaciones (mejor/peor): %.0lf / %.0lf \n", resultados.comparaciones_teoricas_mejor, resultados.comparaciones_teoricas_peor);
  printf("    Intercambios (mejor/peor):  %.0lf / %.0lf \n", resultados.intercambios_teoricos_mejor, resultados.intercambios_teoricos_peor);
  printf("\n");
  printf(" -- Resultados practicos \n");
  printf("    Comparaciones: %.0lf \n", resultados.comparaciones_practicas);
  printf("    Intercambios:  %.0lf \n", resultados.intercambios_practicos);
  printf("\n");
  printf(" -- Rendimiento \n");
  printf("    %d s y %d ms\n", (int)resultados.rendimiento/1000, (int)resultados.rendimiento%1000);
  printf("\n\n");
}

void lee_fichero(char nombre[], int enteros[]) {
  char _nombre[100];
  strcpy(_nombre, nombre);
  strcat(_nombre, ".txt");

  FILE *archivo = fopen(_nombre, "r");

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
  char _nombre[100];
  strcpy(_nombre, nombre);
  strcat(_nombre, ".txt");

  FILE *archivo = fopen(_nombre, "w");

  for (i = 0; i<n; i++) {
    fprintf(archivo, "%d", enteros[i]);
    fprintf(archivo, "\n");
  }
  fclose(archivo);
}
