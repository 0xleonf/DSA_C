#include "array.c"
#include <stdio.h>
#include <stdlib.h>

int sum(Array *arr) {
  int len = arr->capacity;
  int total = 0;

  for (int i = 0; i < len; i++) {
    total += arr->data[i];
  }

  return total;
}

int equilibrium(Array *arr) {
  int total_sum = sum(arr);
  int left_sum = 0;

  for (int i = 0; i < arr->capacity; i++) {
    total_sum -= arr->data[i];

    if (left_sum == total_sum) {
      return i;
    }

    left_sum += arr->data[i];
  }
  return -1;
}

int main() {

  Array *arr = init_array(4);

  int input_arr[] = {1, 2, 0, 3};
  insert_array(arr, input_arr);

  int equil = equilibrium(arr);

  printf("equilibrum index %d", equil);

  free(arr);

  return 0;
}
