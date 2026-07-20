#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  size_t position;
  size_t capacity;
} Array;

Array *init_array(int capacity) {
  Array *arr = (Array *)malloc(sizeof(Array));

  if (arr == NULL) {
    printf("failed to allocated memory\n");
    exit(1);
  }

  arr->data = (int *)malloc(capacity * sizeof(int));
  if (arr->data == NULL) {
    printf("failed to allocated memory\n");
    exit(1);
  }

  arr->capacity = capacity;
  arr->position = 0;

  return arr;
}

void insert_array(Array *arr, int *value) {
  if (arr == NULL)
    return;

  if (arr->position >= arr->capacity) {
    printf("array is full!\n");
  }

  for (int i = 0; i < arr->capacity; i++) {
    arr->data[arr->position] = value[i];
    arr->position++;
  }
}

void remove_element(Array *arr, int index) {
  if (arr == NULL)
    return;

  for (int i = 0; i < arr->capacity; i++) {
    if (i >= index) {
      arr->data[i] = arr->data[i + 1];
    }
  }

  arr->capacity--;
}

// int main() {
//   int capacity = 50;
//   Array *arr = init_array(capacity);
//
//   for (int i = 0; i < capacity; i++) {
//     arr->data[i] = i + 1;
//   }
//
//   printf("ukuran array %zu\n \n", (arr->capacity * sizeof(int)));
//
//   for (int i = 0; i < arr->capacity; i++) {
//     printf("index: {%d}, values: {%d} \n", i, arr->data[i]);
//   }
//
//   remove_element(arr, 49);
//
//   printf("\n");
//
//   for (int i = 0; i < arr->capacity; i++) {
//     printf("index: {%d}, values: {%d} \n", i, arr->data[i]);
//   }
//   free(arr);
//
//   return 0;
// }
