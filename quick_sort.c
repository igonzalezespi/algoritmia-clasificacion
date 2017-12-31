#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "bubble_sort.h"
#include "quick_sort.h"

int medio(int ini, int fin) {
  return (ini + fin) / 2; // Al convertirlo en un INT lo redondea hacia abajo automáticamente
}

int mediana(int array[], int ini, int fin, double* comparaciones, double* intercambios) {
  int temp[3];
  int med = medio(ini, fin);
  temp[0] = array[ini];
  temp[1] = array[med];
  temp[2] = array[fin];
  bubble_mejorado(temp, 3, comparaciones, intercambios);
  comparaciones += 1; // Vamos a comparar, así que aumentamos la variable
  if (temp[1] == array[ini]) {
    return ini;
  } else if (temp[1] == array[med]) {
    return med;
  } else {
    return fin;
  }
}

void quick_sort(int array[], int ini, int fin, int tipo, double* comparaciones, double* intercambios) {
  int i, j, pivote, pos;

  // Caso vector con 1 solo número --> No hacer nada
  *comparaciones += 1;
  if(ini >= fin) return;

  // Caso vector con 2 números --> Comprobar si es necesario ordenarlos
  *comparaciones += 1;
  if(ini+1 == fin) {
    *comparaciones += 1;
    if(array[ini] > array[fin]) {  // No están ordenados los dos números, intercambiar
      *intercambios += 1;
      intercambia(&array[ini], &array[fin]);
    }
    return;
  }

  // Resto de casos --> vector con 3 números o más

  // Esta comparación no la contamos, ya que lo utilizamos para no repetir código. Esto no es del algoritmo de ordenación
  if (tipo == 0) {
    // Pivote --> La posición de mitad del vector
    pos = (ini+fin)/2;
  } else if (tipo == 1) {
    // Pivote --> Posición pseudo-aleatoria entre ini y fin
    pos = (rand() % (fin - ini)) + ini;
  } else { // tipo == 2
    // Pivote --> La posición mediana
    pos = mediana(array, ini, fin, comparaciones, intercambios); // Este método puede hacer comparaciones e intercambios adicionales
  }

  // Intercambiar pivote por el último elemento
  *intercambios += 1;
  intercambia(&array[pos], &array[fin]);
  pivote=array[fin];

  // empezamos la particion
  for(i=ini,j=fin-1;;) {
    while((i <= fin-1) && (array[i]<pivote)) {
      *comparaciones += 2;
      i++;
    }
    while((j >= ini) && (pivote <array[j])) {
      *comparaciones += 2;
      j--;
    }

    *comparaciones += 1;
    if(i<j) { // Todavía no se han intercambiado los índices, intercambiar números
      *intercambios += 1;
      intercambia(&array[i], &array[j]);
      i++;
      j--;
    } else  {// Se han intercambiando los índices, fin de la particion
      break;
    }
  }

  //colocación del pivote en su sitio
  *intercambios += 1;
  intercambia(&array[i], &array[fin]);
  //termina particion; //llamadas recursivas
  quick_sort(array, ini, i-1, tipo, comparaciones, intercambios);  // Vector de la izquierda del pivote
  quick_sort(array, i+1, fin, tipo, comparaciones, intercambios);  // Vector de la derecha del pivote
}

/////////////

void quick_sort_medio(int array[], int ini, int fin, double* comparaciones, double* intercambios) {
  quick_sort(array, ini, fin, 0, comparaciones, intercambios);
}

void quick_sort_random(int array[], int ini, int fin, double* comparaciones, double* intercambios) {
  quick_sort(array, ini, fin, 1, comparaciones, intercambios);
}

void quick_sort_mediana(int array[], int ini, int fin, double* comparaciones, double* intercambios) {
  quick_sort(array, ini, fin, 2, comparaciones, intercambios);
}
