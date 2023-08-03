#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dog.h"

int main(){
  // Creamos un perro
  Dog* my_dog = dog_init("Frodo", "Jack Russel", 4);

  // Lo hacemos ladrar
  dog_bark(my_dog);

  // Cuando ya no lo necesitemos, liberamos la memoria con la que habiamos creado al perro
  free(my_dog);
  return 0;
}
