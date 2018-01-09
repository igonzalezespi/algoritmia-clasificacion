#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

#include "utils.h"
#include "menu.h"
#include "perf.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "shell_sort.h"
#include "quick_sort.h"

int main() {
  srand(time(NULL)); // Semilla para los valores aleatorios. Solo se llama una vez.

  // Menú para elegir un algoritmo
  int algoritmo = menu();
  while (algoritmo != 0) {
    if (algoritmo >= 1 && algoritmo <= 8) {
      cls();
      int i;
      for (i = 0; i<3; i++) { // Por cada fichero (3)
        char titulo[50];
        char sufijo_fichero[50];
        int tam;
        char c_tam[50];
        if (i == 0) {
          tam = 50000;
          strcpy(c_tam, "50000");
        } else if (i == 1) {
          tam = 100000;
          strcpy(c_tam, "100000");
        } else {
          tam = 200000;
          strcpy(c_tam, "200000");
        }

        int array[tam];

        char fichero[100];
        strcpy(fichero, "numeros");
        strcat(fichero, c_tam);

        printf("Leyendo fichero %s.txt...\n", fichero);

        resultados_ordenacion resultados;
        resultados.comparaciones_practicas = 0;
        resultados.intercambios_practicos = 0;

        lee_fichero(fichero, array);

        printf("Ejecutando algoritmo...\n\n");
        empieza_rendimiento();

        switch(algoritmo) {
        case 1: // Burbuja normal
          strcpy(titulo, "Burbuja normal");
          strcpy(sufijo_fichero, "burbuja_normal");
          bubble_normal(array, tam, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

          resultados.comparaciones_teoricas_mejor = (double)((pow(tam, 2) - tam) / 2);
          resultados.comparaciones_teoricas_peor = (double)((pow(tam, 2) - tam) / 2);
          resultados.intercambios_teoricos_mejor = (double)(0);
          resultados.intercambios_teoricos_peor = (double)((pow(tam, 2) - tam) / 2);
          break;
        case 2: // Burbuja mejorado
          strcpy(titulo, "Burbuja mejorado");
          strcpy(sufijo_fichero, "burbuja_mejorado");
          bubble_mejorado(array, tam, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

          resultados.rendimiento = termina_rendimiento();
          resultados.comparaciones_teoricas_mejor = (double)(tam - 1);
          resultados.comparaciones_teoricas_peor = (double)((pow(tam, 2) - tam) / 2);
          resultados.intercambios_teoricos_mejor = (double)(0);
          resultados.intercambios_teoricos_peor = (double)((pow(tam, 2) - tam) / 2);
          break;
        case 3: // Selección directa normal
          strcpy(titulo, "Seleccion normal");
          strcpy(sufijo_fichero, "seleccion_normal");
          selection_normal(array, tam, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

          resultados.rendimiento = termina_rendimiento();
          resultados.comparaciones_teoricas_mejor = (double)((pow(tam, 2) - tam) / 2);
          resultados.comparaciones_teoricas_peor = (double)((pow(tam, 2) - tam) / 2);
          resultados.intercambios_teoricos_mejor = (double)((pow(tam, 2) - tam) / 2);
          resultados.intercambios_teoricos_peor = (double)(tam - 1);
          break;
        case 4: // Selección directa mejorado
          strcpy(titulo, "Seleccion mejorado");
          strcpy(sufijo_fichero, "seleccion_mejorado");
          selection_mejorado(array, tam, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

          resultados.rendimiento = termina_rendimiento();
          resultados.comparaciones_teoricas_mejor = (double)((pow(tam, 2) - tam) / 2);
          resultados.comparaciones_teoricas_peor = (double)((pow(tam, 2) - tam) / 2);
          resultados.intercambios_teoricos_mejor = (double)((pow(tam, 2) - tam) / 2);
          resultados.intercambios_teoricos_peor = (double)(tam - 1);
          break;
        case 5: // Shell
          strcpy(titulo, "Shell");
          strcpy(sufijo_fichero, "shell");
          shell_sort(array, tam, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

          resultados.rendimiento = termina_rendimiento();
          resultados.comparaciones_teoricas_mejor = (double)((pow(tam, 2) - tam) / 2);
          resultados.comparaciones_teoricas_peor = (double)((pow(tam, 2) - tam) / 2);
          resultados.intercambios_teoricos_mejor = (double)((pow(tam, 2) - tam) / 2);
          resultados.intercambios_teoricos_peor = (double)(tam - 1);
          break;
        case 6: // Quicksort (Medio)
          strcpy(titulo, "Quicksort (Medio)");
          strcpy(sufijo_fichero, "quicksort_medio");
          quick_sort_medio(array, 0, tam - 1, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

          resultados.rendimiento = termina_rendimiento();
          resultados.comparaciones_teoricas_mejor = (double)((pow(tam, 2) - tam) / 2);
          resultados.comparaciones_teoricas_peor = (double)((pow(tam, 2) - tam) / 2);
          resultados.intercambios_teoricos_mejor = (double)((pow(tam, 2) - tam) / 2);
          resultados.intercambios_teoricos_peor = (double)(tam - 1);
          break;
        case 7: // Quicksort (Aleatorio)
          strcpy(titulo, "Quicksort (Aleatorio)");
          strcpy(sufijo_fichero, "quicksort_aleatorio");
          quick_sort_random(array, 0, tam - 1, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

          resultados.rendimiento = termina_rendimiento();
          resultados.comparaciones_teoricas_mejor = (double)((pow(tam, 2) - tam) / 2);
          resultados.comparaciones_teoricas_peor = (double)((pow(tam, 2) - tam) / 2);
          resultados.intercambios_teoricos_mejor = (double)((pow(tam, 2) - tam) / 2);
          resultados.intercambios_teoricos_peor = (double)(tam - 1);
          break;
        case 8: // Quicksort (Mediana)
          strcpy(titulo, "Quicksort (Mediana)");
          strcpy(sufijo_fichero, "quicksort_mediana");
          quick_sort_mediana(array, 0, tam - 1, &resultados.comparaciones_practicas, &resultados.intercambios_practicos);

          resultados.rendimiento = termina_rendimiento();
          resultados.comparaciones_teoricas_mejor = (double)((pow(tam, 2) - tam) / 2);
          resultados.comparaciones_teoricas_peor = (double)((pow(tam, 2) - tam) / 2);
          resultados.intercambios_teoricos_mejor = (double)((pow(tam, 2) - tam) / 2);
          resultados.intercambios_teoricos_peor = (double)(tam - 1);
          break;
        }

        resultados.rendimiento = termina_rendimiento();

        imprime_resultados(titulo, resultados);

        strcat(fichero, "_");
        strcat(fichero, sufijo_fichero);
        escribe_fichero(fichero, array, tam);
      }
      system("PAUSE");
    }
    algoritmo = menu();
  }
  return 0;
}
