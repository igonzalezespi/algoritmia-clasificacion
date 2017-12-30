#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"
#include "shell_sort.h"

int total_intervalos(int n) {
  return log(n) / log(2) - 1;
}

int siguiente_intervalo(int i) {
  return i*2+1;
}

void genera_intervalos(int secuencia[], int total) {
  int i, interv;
  for (interv = 1, i = total-1; i >= 0; interv = siguiente_intervalo(interv), i--) {
    secuencia[i] = interv;
  }
}

void shell_sort(int arr[], int n, double* comparaciones, double* intercambios) {
  int i, j, count, interv, pivote;
  int num_intervalos = total_intervalos(n);
  int intervalos[num_intervalos];

  genera_intervalos(intervalos, num_intervalos);

  count = 0;
  for (interv = intervalos[count]; count < num_intervalos; count += 1, interv = intervalos[count]) {
    for (i = interv; i < n; i += 1) {
      pivote = arr[i];
      for (j = i; j >= interv && arr[j - interv] > pivote; j -= interv) {
        *comparaciones += 1;
        *intercambios += 1;
        arr[j] = arr[j - interv];
      }
      *intercambios += 1;
      arr[j] = pivote;
    }
  }
}
