#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED


typedef struct resultados_ordenacion {
  double coste_teorico_mejor;
  double coste_teorico_peor;
  double comparaciones_practicas;
  double intercambios_practicos;
  double rendimiento;
} resultados_ordenacion;

void cls(void);
void pause(void);

void intercambia(int *a, int *b);

void imprime_resultados(char titulo[], resultados_ordenacion resultado);

void lee_fichero(char nombre[], int enteros[]);
void escribe_fichero(char nombre[], int enteros[], int n);

#endif // UTILS_H_INCLUDED
