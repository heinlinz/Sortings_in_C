#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int ln = m - l + 1;
  int rn = r - m;

  int L[ln], R[rn];

  for (i = 0; i < ln; i++) 
    L[i] = arr[l + i];
  for (j = 0; j < rn; j++) 
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;

  while (i < ln && j < rn) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < ln) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < rn) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = (r + l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

int main() {

  int arr[] = {90, 80, 100, 120, 60, 40, 70};
  int n = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) 
    printf("%d->", arr[i]);

  return 0;
}
