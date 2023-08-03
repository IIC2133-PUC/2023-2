#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Entry {
  int key;
  int value;
  struct Entry* next;
} Entry;

Entry* newEntry(int key, int value) {
  Entry* new_entry = calloc(1, sizeof(Entry));
  new_entry->key = key;
  new_entry->value = value;
  new_entry->next = NULL;
  return new_entry;
}

int hash_function(int key) {
  return key % TABLE_SIZE;
}

void insert(Entry** table, int key, int value) {
  Entry* new_entry = newEntry(key, value);

  int index = hash_function(new_entry->key);

  Entry* current = table[index];
  if (current == NULL) {
    table[index] = new_entry;
  } else {
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_entry;
  }
}

Entry* search(Entry** table, int key, int value) {
  int index = hash_function(key);
  Entry* current = table[index];
  while (current != NULL) {
    if (current->key == key && current->value == value) {
      printf("Found a node in the table at index %i \n", index);
      return current;
    }
    current = current->next;
  }
  printf("Did not find a node in the table at index %i \n", index);
  return NULL;
}

void delete(Entry** table, int key, int value) {
  int index = hash_function(key);

  Entry* current = table[index];

  Entry* prev = NULL;

  while (current != NULL) {
    if (current->key == key && current->value == value) {
      if (prev == NULL) {
        // The element to delete is the first in the list
        table[index] = current->next;
      } else {
        // The element to delete is in the middle or end of the list
        prev->next = current->next;
      }
      free(current);
      return;
    }
    prev = current;
    current = current->next;
  }
}

void print_collisions_at_index(Entry** table, int index) {
  Entry* current = table[index];
  if (current == NULL) {
    printf("No collisions at index %d\n", index);
    return;
  }
  printf("Collisions at index %d:\n", index);
  while (current != NULL) {
    printf("Key: %d, Value: %d\n", current->key, current->value);
    current = current->next;
  }
}

void free_table(Entry** table) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    Entry* current = table[i];
    while (current != NULL) {
      Entry* temp = current;
      free(current);
      current = temp->next;
    }
  }
  free(table);
}

int main() {
  Entry** table = calloc(TABLE_SIZE, sizeof(Entry*));

  insert(table, 1, 10);
  insert(table, 2, 20);
  insert(table, 3, 30);
  insert(table, 4, 40);
  insert(table, 11, 110);
  insert(table, 12, 120);

  search(table, 1, 10);

  delete (table, 1, 10);

  search(table, 1, 10);

  print_collisions_at_index(table, 1);
  return 0;
}
