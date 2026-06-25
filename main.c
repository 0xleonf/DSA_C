#include "search/binary_search.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *data = (int *)malloc(12 * sizeof(int));

  for (int i = 0; i < 12; i++) {
    data[i] = (i + 1) * 10;
  }

  int hasil = binary_search(data, 12, 120);

  printf("%d", hasil);

  free(data);
}
