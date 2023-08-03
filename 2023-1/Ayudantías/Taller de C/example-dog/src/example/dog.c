#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dog.h"

Dog* dog_init(char* name, char* breed, int age) {
  // Creamos un perro, pidiendo memoria para él
  Dog* dog = calloc(1, sizeof(Dog));
  *dog = (Dog) {
    .name = name,
    .breed = breed,
    .good_boy = true,
    .age = age,
  };
  
  return dog;
}

void dog_bark(Dog* dog) {
  printf("My name is %s\n", dog->name);
}
