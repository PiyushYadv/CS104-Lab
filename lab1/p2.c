#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key)
{
  if (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
      return mid;

    if (arr[mid] > key)
      return binarySearch(arr, low, mid - 1, key);

    return binarySearch(arr, mid + 1, high, key);
  }
  return -1;
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");
  int arr[] = {2, 4, 6, 8, 10, 12};
  int key = 8;
  int size = sizeof(arr) / sizeof(arr[0]);
  int result = binarySearch(arr, 0, size - 1, key);
  if (result != -1)
    printf("Element %d found at index %d.\n", key, result);
  else
    printf("Element %d not found in the array.\n", key);
  return 0;
}
