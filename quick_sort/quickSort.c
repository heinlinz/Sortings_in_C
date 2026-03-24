#include <stdio.h>

void swap(int *a, int *b);

int partition(int arr[], int low, int high) {

  int boss = arr[high];
  
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < boss) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

void quicksort(int arr[], int low, int high) {
  
  if (low < high) {
    int boss = partition(arr, low, high);

    quicksort(arr, low, boss - 1);
    quicksort(arr, boss + 1, high);
  }
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int arr[] = {10, 5, 33, 6, 8};
  int n = sizeof(arr) / sizeof(arr[0]);

  quicksort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d--", arr[i]);
  }

  return 0;
}
