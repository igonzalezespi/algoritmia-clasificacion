#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED


void intercambia(int *a, int *b);

void imprime_resultados(char titulo[], double comparaciones, double intercambios, double interval);

void lee_fichero(char nombre[], int enteros[]);
void escribe_fichero(char nombre[], int enteros[], int n);

#endif // UTILS_H_INCLUDED
