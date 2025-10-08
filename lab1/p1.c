#include <stdio.h>

int linearSearch(int arr[], int key, int size)
{
  if (size == 0)
    return -1;

  if (arr[size - 1] == key)
    return size - 1;

  return linearSearch(arr, key, size - 1);
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");
  int arr[] = {2, 4, 6, 8, 10, 12};
  int key = 8;
  int size = sizeof(arr) / sizeof(arr[0]);
  int result = linearSearch(arr, key, size);
  if (result != -1)
    printf("Element %d found at index %d.\n", key, result);
  else
    printf("Element %d not found in the array.\n", key);
  return 0;
}
