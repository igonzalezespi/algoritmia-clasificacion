#include "utils.h"
#include "bubble_sort.h"

int main() {
  int arr[50000];
  double comparaciones = 0;
  double intercambios = 0;
  int n = sizeof(arr)/sizeof(arr[0]);

  // BUBBLE normal

  lee_fichero("numeros50000.txt", arr);

  bubble_normal(arr, n, &comparaciones, &intercambios);

  imprime_resultados(comparaciones, intercambios);

  escribe_fichero("numeros50000_sort.txt", arr, n);

  // BUBBLE mejorado
  comparaciones = 0;
  intercambios = 0;

  lee_fichero("numeros50000_sort.txt", arr);

  bubble_mejorado(arr, n, &comparaciones, &intercambios);

  imprime_resultados(comparaciones, intercambios);
  return 0;
}
