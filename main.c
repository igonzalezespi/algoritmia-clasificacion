#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

#include "utils.h"
#include "perf.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "shell_sort.h"
#include "quick_sort.h"

int main() {
  int tam = 50000;
  int array[tam];
  char fichero[27] = "numeros50000_sort_desc.txt";
  resultados_ordenacion resultados;

  srand(time(NULL)); // Semilla para los valores aleatorios. Solo se llama una vez.


  // Bubble normal
  resultados.comparaciones_practicas = 0;
  resultados.intercambios_practicos = 0;

  lee_fichero(fichero, array);

  empieza_rendimiento();
  bubble_normal(array, tam, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

  resultados.rendimiento = termina_rendimiento();
  resultados.comparaciones_teoricas_mejor = (double)((pow(tam, 2) - tam) / 2);
  resultados.comparaciones_teoricas_peor = (double)((pow(tam, 2) - tam) / 2);
  resultados.intercambios_teoricos_mejor = (double)(0);
  resultados.intercambios_teoricos_peor = (double)((pow(tam, 2) - tam) / 2);

  imprime_resultados("Bubble normal", resultados);

  escribe_fichero("numeros50000_bubble_normal.txt", array, tam);


  // Bubble mejorado
  resultados.comparaciones_practicas = 0;
  resultados.intercambios_practicos = 0;

  lee_fichero(fichero, array);

  empieza_rendimiento();
  bubble_mejorado(array, tam, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

  resultados.rendimiento = termina_rendimiento();
  resultados.comparaciones_teoricas_mejor = (double)(tam - 1);
  resultados.comparaciones_teoricas_peor = (double)((pow(tam, 2) - tam) / 2);
  resultados.intercambios_teoricos_mejor = 0;
  resultados.intercambios_teoricos_peor = (double)((pow(tam, 2) - tam) / 2);

  imprime_resultados("Bubble mejorado", resultados);

  escribe_fichero("numeros50000_bubble_mejorado.txt", array, tam);



  // Selección directa normal
  resultados.comparaciones_practicas = 0;
  resultados.intercambios_practicos = 0;

  lee_fichero(fichero, array);

  empieza_rendimiento();
  selection_normal(array, tam, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

  resultados.rendimiento = termina_rendimiento();
  resultados.comparaciones_teoricas_mejor = (double)((pow(tam, 2) - tam) / 2);
  resultados.comparaciones_teoricas_peor = (double)((pow(tam, 2) - tam) / 2);
  resultados.intercambios_teoricos_mejor = (double)((pow(tam, 2) - tam) / 2);
  resultados.intercambios_teoricos_peor = (double)(tam - 1);

  imprime_resultados("Seleccion directa normal", resultados);

  escribe_fichero("numeros50000_selection_normal.txt", array, tam);



  // Selección directa mejorado
  resultados.comparaciones_practicas = 0;
  resultados.intercambios_practicos = 0;

  lee_fichero(fichero, array);

  empieza_rendimiento();
  selection_mejorado(array, tam, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

  resultados.rendimiento = termina_rendimiento();
  resultados.comparaciones_teoricas_mejor = (double)((pow(tam, 2) - tam) / 2);
  resultados.comparaciones_teoricas_peor = (double)(((pow(tam, 2) - tam) / 2) + tam - 1);
  resultados.intercambios_teoricos_mejor = (double)((pow(tam, 2) - tam) / 2);
  resultados.intercambios_teoricos_peor = (double)(tam - 1);

  imprime_resultados("Seleccion directa mejorado", resultados);

  escribe_fichero("numeros50000_selection_mejorado.txt", array, tam);



  // Shell
  resultados.comparaciones_practicas = 0;
  resultados.intercambios_practicos = 0;

  lee_fichero(fichero, array);

  empieza_rendimiento();
  shell_sort(array, tam, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

  resultados.rendimiento = termina_rendimiento();
  resultados.comparaciones_teoricas_mejor = (double)(pow(tam, 2));
  resultados.comparaciones_teoricas_peor = (double)(pow(tam, 2));
  resultados.intercambios_teoricos_mejor = (double)(pow(tam, 2));
  resultados.intercambios_teoricos_peor = (double)(pow(tam, 2));

  imprime_resultados("Shell", resultados);

  escribe_fichero("numeros50000_shell_sort.txt", array, tam);



  // Quicksort - medio
  resultados.comparaciones_practicas = 0;
  resultados.intercambios_practicos = 0;

  lee_fichero(fichero, array);

  empieza_rendimiento();
  quick_sort_medio(array, 0, tam - 1, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

  resultados.rendimiento = termina_rendimiento();
  resultados.comparaciones_teoricas_mejor = (double)(pow(tam, 2));
  resultados.comparaciones_teoricas_peor = (double)(pow(tam, 2));
  resultados.intercambios_teoricos_mejor = (double)(pow(tam, 2));
  resultados.intercambios_teoricos_peor = (double)(pow(tam, 2));

  imprime_resultados("Quicksort - medio", resultados);

  escribe_fichero("numeros50000_quick_sort_medio.txt", array, tam);



  // Quicksort - random
  resultados.comparaciones_practicas = 0;
  resultados.intercambios_practicos = 0;

  lee_fichero(fichero, array);

  empieza_rendimiento();
  quick_sort_random(array, 0, tam - 1, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

  resultados.rendimiento = termina_rendimiento();
  resultados.comparaciones_teoricas_mejor = (double)(pow(tam, 2));
  resultados.comparaciones_teoricas_peor = (double)(pow(tam, 2));
  resultados.intercambios_teoricos_mejor = (double)(pow(tam, 2));
  resultados.intercambios_teoricos_peor = (double)(pow(tam, 2));

  imprime_resultados("Quicksort - random", resultados);

  escribe_fichero("numeros50000_quick_sort_random.txt", array, tam);



  // Quicksort - mediana
  resultados.comparaciones_practicas = 0;
  resultados.intercambios_practicos = 0;

  lee_fichero(fichero, array);

  empieza_rendimiento();
  quick_sort_mediana(array, 0, tam - 1, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

  resultados.rendimiento = termina_rendimiento();
  resultados.comparaciones_teoricas_mejor = (double)(pow(tam, 2));
  resultados.comparaciones_teoricas_peor = (double)(pow(tam, 2));
  resultados.intercambios_teoricos_mejor = (double)(pow(tam, 2));
  resultados.intercambios_teoricos_peor = (double)(pow(tam, 2));

  imprime_resultados("Quicksort - mediana", resultados);

  escribe_fichero("numeros50000_quick_sort_mediana.txt", array, tam);

  return 0;
}
