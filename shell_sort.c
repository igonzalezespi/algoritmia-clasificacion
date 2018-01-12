#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"
#include "shell_sort.h"

// Calcula el total de veces que se ejecutará Shell
int total_intervalos(int tam) {
  return log(tam) / log(2) - 1;
}

// Calcula el siguiente intervalo a ejecutar en Shell
int siguiente_intervalo(int i) {
  return i*2+1;
}

// Genera, en el array dado, un número total dado de intervalos a ejecutar por Shell
void genera_intervalos(int secuencia[], int total) {
  int i, intervalo;
  for (intervalo = 1, i = total-1; i >= 0; intervalo = siguiente_intervalo(intervalo), i--) {
    secuencia[i] = intervalo;
  }
}

// Algoritmo Shell Sort
void shell_sort(int array[], int tam, double* comparaciones, double* intercambios) {
  int i, j, intervalo, pivote, count;
  int num_intervalos = total_intervalos(tam); // Calculamos los intervalos que vamos a hacer dependiendo del tamaño del array
  int intervalos[num_intervalos];

  genera_intervalos(intervalos, num_intervalos); // Generamos los intervalos/saltos que va a hacer el algoritmo
  count = 0;
  while (count < num_intervalos) {
    intervalo = intervalos[count];
    for (i=intervalo; i < tam; i++) {
      j = i;
      pivote = array[i];
      *comparaciones += 1;
      while (j >= intervalo && array[j - intervalo] > pivote) {
        *intercambios += 1;
        array[j] = array[j - intervalo];
        j = j - intervalo;
      }
      *intercambios += 1;
      array[j] = pivote;
    }
    count += 1;
  }
}
