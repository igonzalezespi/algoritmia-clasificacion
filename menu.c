#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "menu.h"
#include "utils.h"

int menu() {
  char seleccion;
  int int_seleccion;
  cls();
  printf("=========== CLASIFICACION ===========\n\n");
  printf("== Bubble sort ==\n");
  printf("1. Normal.\n");
  printf("2. Mejorado.\n");
  printf("== Selection sort ==\n");
  printf("3. Normal.\n");
  printf("4. Mejorado.\n");
  printf("== Shell sort ==\n");
  printf("5. Normal.\n");
  printf("== Quicksort ==\n");
  printf("6. Pivote: medio.\n");
  printf("7. Pivote: aleatorio.\n");
  printf("8. Pivote: mediana.\n");
  printf("\n");
  printf("S. Salir\n");
  scanf(" %c", &seleccion);

  if (seleccion == 'S') {
    return -1;
  }
  int_seleccion = seleccion - '0';
  return int_seleccion;
}
