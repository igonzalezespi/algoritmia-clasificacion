#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "bubble_sort.h"
#include "quick_sort.h"

int medio(int ini, int fin) {
  return (ini + fin) / 2; // Al convertirlo en un INT lo redondea hacia abajo automáticamente
}

int mediana(int a[], int ini, int fin, double* comparaciones, double* intercambios) {
  int temp[3];
  int med = medio(ini, fin);
  temp[0] = a[ini];
  temp[1] = a[med];
  temp[2] = a[fin];
  bubble_mejorado(temp, 3, comparaciones, intercambios);
  comparaciones += 1; // Vamos a comparar, así que aumentamos la variable
  if (temp[1] == a[ini]) {
    return ini;
  } else if (temp[1] == a[med]) {
    return med;
  } else {
    return fin;
  }
}

void quick_sort(int a[], int ini, int fin, int tipo, double* comparaciones, double* intercambios) {
  int i, j, pivote, pos;

  // Caso vector con 1 solo número --> No hacer nada
  *comparaciones += 1;
  if(ini >= fin) return;

  // Caso vector con 2 números --> Comprobar si es necesario ordenarlos
  *comparaciones += 1;
  if(ini+1 == fin) {
    *comparaciones += 1;
    if(a[ini] > a[fin]) {  // No están ordenados los dos números, intercambiar
      *intercambios += 1;
      intercambia(&a[ini], &a[fin]);
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
    pos = mediana(a, ini, fin, comparaciones, intercambios); // Este método puede hacer comparaciones e intercambios adicionales
  }

  // Intercambiar pivote por el último elemento
  *intercambios += 1;
  intercambia(&a[pos], &a[fin]);
  pivote=a[fin];

  // empezamos la particion
  for(i=ini,j=fin-1;;) {
    while((i <= fin-1) && (a[i]<pivote)) {
      *comparaciones += 1;
      i++;
    }
    while((j >= ini) && (pivote <a[j])) {
      *comparaciones += 1;
      j--;
    }

    *comparaciones += 1;
    if(i<j) { // Todavía no se han intercambiado los índices, intercambiar números
      *intercambios += 1;
      intercambia(&a[i], &a[j]);
      i++;
      j--;
    } else  {// Se han intercambiando los índices, fin de la particion
      break;
    }
  }

  //colocación del pivote en su sitio
  *intercambios += 1;
  intercambia(&a[i], &a[fin]);
  //termina particion; //llamadas recursivas
  quick_sort(a, ini, i-1, tipo, comparaciones, intercambios);  // Vector de la izquierda del pivote
  quick_sort(a, i+1, fin, tipo, comparaciones, intercambios);  // Vector de la derecha del pivote
}

/////////////

void quick_sort_medio(int a[], int ini, int fin, double* comparaciones, double* intercambios) {
  quick_sort(a, ini, fin, 0, comparaciones, intercambios);
}

void quick_sort_random(int a[], int ini, int fin, double* comparaciones, double* intercambios) {
  quick_sort(a, ini, fin, 1, comparaciones, intercambios);
}

void quick_sort_mediana(int a[], int ini, int fin, double* comparaciones, double* intercambios) {
  quick_sort(a, ini, fin, 2, comparaciones, intercambios);
}
