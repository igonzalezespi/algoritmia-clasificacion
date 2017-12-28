#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "selection_sort.h"

void selection_sort(int arr[], int n, double* comparaciones, double* intercambios) {
  int i, j, min_idx;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < n-1; i++) {
    // Find the minimum element in unsorted array
    min_idx = i;
    for (j = i+1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }

    // Swap the found minimum element with the first element
    intercambia(&arr[min_idx], &arr[i]);
  }
}

void selection_sort(int arr[], int n, double* comparaciones, double* intercambios) {
}
