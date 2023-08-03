#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Retorna true si ambos strings son iguales */
bool string_equals(char *string1, char *string2) {
  return !strcmp(string1, string2);
}

/* Revisa que los parametros del programa sean válidos */
bool check_arguments(int argc, char **argv) {
  if (argc != 3) {
    printf("Modo de uso: %s INPUT OUTPUT\n", argv[0]);
    printf("Donde:\n");
    printf("\tINPUT es la ruta del archivo de input\n");
    printf("\tOUTPUT es la ruta del archivo de output\n");
    return false;
  }

  return true;
}

int *merge(int *A, int *B, int l1, int l2) {
  int *ord = calloc(l1 + l2, sizeof(int));
  int i, j, k;
  i = 0;
  j = 0;
  k = 0;
  while ((i < l1) && (j < l2)) {
    if (A[i] <= B[j]) {
      ord[k] = A[i];
      i++;
      k++;
    } else {
      ord[k] = B[j];
      j++;
      k++;
    }
  }
  while (i < l1) {
    ord[k] = A[i];
    i++;
    k++;
  }
  while (j < l2) {
    ord[k] = B[j];
    j++;
    k++;
  }
  return ord;
}

void mergeSort(int *arr, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);

    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

int main(int argc, char **argv) {
  if (!check_arguments(argc, argv)) {
    /* Salimos del programa indicando que no terminó correctamente */
    return 1;
  }

  /* Abrimos el archivo de input */
  FILE *input_file = fopen(argv[1], "r");

  /* Abrimos el archivo de output */
  FILE *output_file = fopen(argv[2], "w");

  int N;
  fscanf(input_file, "%d", &N);
  int num[N];
  int temp;
  for (int i = 0; i < N; i++) {
    fscanf(input_file, "%d", &temp);
    num[i] = temp;
  }

  int *temp_a = merge(&num[0], &num[5], 5, 5);
  for (int i = 0; i < N; i++) {
    num[i] = temp_a[i];
  }

  for (int i = 0; i < N; i++) {
    fprintf(output_file, "%d\n", num[i]);
  }

  fclose(input_file);
  fclose(output_file);
  return 0;
}
