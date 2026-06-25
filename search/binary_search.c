int binary_search(int *data, int size, int target) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (data[mid] == target) {
      return mid;
    } else if (data[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}
