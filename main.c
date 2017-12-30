#include <time.h>
#include <windows.h>

#include "utils.h"
#include "perf.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "shell_sort.h"
#include "quick_sort.h"

int main() {
  int arr[50000];
  double comparaciones;
  double intercambios;
  double rendimiento;
  int n = sizeof(arr)/sizeof(arr[0]);

  srand(time(NULL)); // Semilla para los valores aleatorios. Solo se llama una vez.


  // Bubble normal
  comparaciones = 0;
  intercambios = 0;

  lee_fichero("numeros50000.txt", arr);

  empieza_rendimiento();
  bubble_normal(arr, n, &comparaciones, &intercambios);
  rendimiento = termina_rendimiento();

  imprime_resultados("Bubble normal", comparaciones, intercambios, rendimiento);

  escribe_fichero("numeros50000_bubble_normal.txt", arr, n);


  // Bubble mejorado
  comparaciones = 0;
  intercambios = 0;

  lee_fichero("numeros50000.txt", arr);

  empieza_rendimiento();
  bubble_mejorado(arr, n, &comparaciones, &intercambios);
  rendimiento = termina_rendimiento();

  imprime_resultados("Bubble mejorado", comparaciones, intercambios, rendimiento);

  escribe_fichero("numeros50000_bubble_mejorado.txt", arr, n);



  // Selección directa normal
  comparaciones = 0;
  intercambios = 0;

  lee_fichero("numeros50000.txt", arr);

  empieza_rendimiento();
  selection_normal(arr, n, &comparaciones, &intercambios);
  rendimiento = termina_rendimiento();

  imprime_resultados("Seleccion directa normal", comparaciones, intercambios, rendimiento);

  escribe_fichero("numeros50000_selection_normal.txt", arr, n);



  // Selección directa mejorado
  comparaciones = 0;
  intercambios = 0;

  lee_fichero("numeros50000.txt", arr);

  empieza_rendimiento();
  selection_mejorado(arr, n, &comparaciones, &intercambios);
  rendimiento = termina_rendimiento();

  imprime_resultados("Seleccion directa mejorado", comparaciones, intercambios, rendimiento);

  escribe_fichero("numeros50000_selection_mejorado.txt", arr, n);



  // Shell
  comparaciones = 0;
  intercambios = 0;

  lee_fichero("numeros50000.txt", arr);

  empieza_rendimiento();
  shell_sort(arr, n, &comparaciones, &intercambios);
  rendimiento = termina_rendimiento();

  imprime_resultados("Shell", comparaciones, intercambios, rendimiento);

  escribe_fichero("numeros50000_shell_sort.txt", arr, n);



  // Quicksort - medio
  comparaciones = 0;
  intercambios = 0;

  lee_fichero("numeros50000.txt", arr);

  empieza_rendimiento();
  quick_sort_medio(arr, 0, n - 1, &comparaciones, &intercambios);
  rendimiento = termina_rendimiento();

  imprime_resultados("Quicksort - medio", comparaciones, intercambios, rendimiento);

  escribe_fichero("numeros50000_quick_sort_medio.txt", arr, n);



  // Quicksort - random
  comparaciones = 0;
  intercambios = 0;

  lee_fichero("numeros50000.txt", arr);

  empieza_rendimiento();
  quick_sort_random(arr, 0, n - 1, &comparaciones, &intercambios);
  rendimiento = termina_rendimiento();

  imprime_resultados("Quicksort - random", comparaciones, intercambios, rendimiento);

  escribe_fichero("numeros50000_quick_sort_random.txt", arr, n);



  // Quicksort - mediana
  comparaciones = 0;
  intercambios = 0;

  lee_fichero("numeros50000.txt", arr);

  empieza_rendimiento();
  quick_sort_mediana(arr, 0, n - 1, &comparaciones, &intercambios);
  rendimiento = termina_rendimiento();

  imprime_resultados("Quicksort - mediana", comparaciones, intercambios, rendimiento);

  escribe_fichero("numeros50000_quick_sort_mediana.txt", arr, n);

  return 0;
}
