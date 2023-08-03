#include <stdbool.h>

typedef struct dog {
  char* name;
  char* breed;
  bool good_boy;
  int age;
} Dog;

Dog* dog_init(char* name, char* breed, int age);
void dog_bark(Dog* dog);
