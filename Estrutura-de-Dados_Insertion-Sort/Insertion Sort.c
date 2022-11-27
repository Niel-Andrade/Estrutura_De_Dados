#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *arr, int n) {
  int i, j, key;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d, ", arr[i]);
  printf("\n");
}

int main() {
  int n;
  printf("Digite o tamanho do vetor de elementos: ");
  scanf("%d", &n);
  int arr[n];
  int vAux;

  float time_spent = 0.0;
  clock_t begin = clock();

  printf("Vetor desordenado\n");
  for (vAux = 0; vAux < n; vAux++) {
    arr[vAux] = rand() % (4 * n);
    printf("%d, ", arr[vAux]);
  }

  insertionSort(arr, n);

  clock_t end = clock();

  printf("\n\n\nVetor ordenado:\n");
  printArray(arr, n);

  time_spent += (float)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo para a execução do código é de: %f segundos.", time_spent);

  return 0;
}
