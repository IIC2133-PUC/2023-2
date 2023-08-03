// Importa el módulo standard de Input / Output
#include <stdio.h>

// Funcion que se llama al ejecutar el programa
int main()
{
  // Imprime en consola
  printf("What is your name?\n>");

  // Un arreglo de caracteres para guardar un string de largo máximo 31
  char name[32];

  // Lee un string desde la consola, y lo guarda en name
  scanf("%s", name);

  // Imprime en la consola el valor de una variable
  printf("Hello, %s!\n", name);

  // Todo salió bien
  return 0;
}
