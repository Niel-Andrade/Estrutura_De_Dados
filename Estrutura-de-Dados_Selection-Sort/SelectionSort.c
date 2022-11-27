#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int num[], int tam) { 
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++) 
  {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(num[j] < num[min]) 
         min = j;
     }
     if (i != min) {
       aux = num[i];
       num[i] = num[min];
       num[min] = aux;
     }
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
  
  srand(time(NULL));

  for (vAux = 0; vAux < n; vAux++) {
    arr[vAux] = rand() % (4 * n);
    printf("%d, ", arr[vAux]);
  }

  selection_sort(arr, n);

  clock_t end = clock();

  printf("\n\n\nVetor ordenado:\n");
  printArray(arr, n);

  time_spent += (float)(end - begin) / CLOCKS_PER_SEC;
  printf("\nO tempo levado para ordenar %d números foi de: %f segundos.", n, time_spent);

  return 0;
}
