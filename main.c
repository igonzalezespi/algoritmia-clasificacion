#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort(int arr[], int n, double* comparaciones, double* intercambios) {
  int i, j;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      *comparaciones += 1;
      if (arr[j] > arr[j+1]) {
        *intercambios += 1;
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}

void readFile(char filename[], int integers[]) {
  FILE *file = fopen(filename, "r");

  int i=0;
  int num;
  while(fscanf(file, "%d", &num) > 0) {
    integers[i] = num;
    i++;
  }
  fclose(file);
}

void writeFile(char filename[], int integers[], int n) {
  int i;
  FILE *file = fopen(filename, "w");

  for (i = 0; i<n; i++) {
    fprintf(file, "%d", integers[i]);
    fprintf(file, "\n");
  }
  fclose(file);
}


int main() {
  int arr[50000];
  readFile("numeros50000.txt", arr);
  int n = sizeof(arr)/sizeof(arr[0]);
  double comparaciones = 0;
  double intercambios = 0;

  LARGE_INTEGER frequency;
  LARGE_INTEGER start;
  LARGE_INTEGER end;
  double interval;

  QueryPerformanceFrequency(&frequency);
  QueryPerformanceCounter(&start);

  bubbleSort(arr, n, &comparaciones, &intercambios);

  QueryPerformanceCounter(&end);

  interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;

  printf("Tiempo tardado: %f\n", interval);
  printf("Comparaciones: %f\n", comparaciones);
  printf("Intercambios: %f\n", intercambios);

  writeFile("numeros50000_sort.txt", arr, n);
  return 0;
}
