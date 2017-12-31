#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"
#include "shell_sort.h"

int total_intervalos(int tam) {
  return log(tam) / log(2) - 1;
}

int siguiente_intervalo(int i) {
  return i*2+1;
}

void genera_intervalos(int secuencia[], int total) {
  int i, intervalo;
  for (intervalo = 1, i = total-1; i >= 0; intervalo = siguiente_intervalo(intervalo), i--) {
    secuencia[i] = intervalo;
  }
}

void shell_sort(int array[], int tam, double* comparaciones, double* intercambios) {
  int i, j, intervalo, pivote, count;
  int num_intervalos = total_intervalos(tam);
  int intervalos[num_intervalos];

  genera_intervalos(intervalos, num_intervalos);
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
