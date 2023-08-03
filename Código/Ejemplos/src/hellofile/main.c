// Importa el módulo standard de Input / Output
#include <stdio.h>

// Función que se llama al ejecutar el programa, esta vez recibe parámetros
// argc = Argument Count
// argv = Argument Value
int main(int argc, char* argv[])
{
  // El primer argumento siempre es el nombre del programa
  if(argc == 1)
  {
    // No recibió argumentos, lo cual es un error
    fprintf(stderr, "Modo de uso:\n");
    fprintf(stderr, "%s <filename>\n", argv[0]);

    // El programa terminó con un error, al que se le asignará el código 1
    return 1;
  }

  // Abre el archivo en modo lectura
  FILE* fr = fopen(argv[1], "r");

  // Hubo un error al abrir el archivo
  if(fr == NULL)
  {
    // El programa terminó con un error, al que se le asignará el código 2
    return 2;
  }

  // Un arreglo de caracteres para guardar un string de largo máximo 31
  char buffer[32];

  // Lee la primera palabra del archivo y la guarda en "buffer"
  fscanf(fr, "%s", buffer);

  // Imprime en la consola
  printf("La primera palabra es \"%s\"\n", buffer);

  // Cierra el archivo
  fclose(fr);

  // Todo salió bien
  return 0;
}
