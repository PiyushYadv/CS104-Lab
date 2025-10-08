#include <stdio.h>

// Swap function to swap two elements
void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

// Partition function to partition the array
int partition(int arr[], int low, int high)
{
  int pivot = arr[high]; // pivot
  int i = (low - 1);     // Index of smaller element

  for (int j = low; j <= high - 1; j++)
  {
    // If current element is smaller than the pivot
    if (arr[j] < pivot)
    {
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    // Partitioning index
    int pi = partition(arr, low, high);

    // Separate elements before and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// Function to print an array
void printArray(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Test program
int main()
{
  printf("Piyush Yadav - 23/CS/301\n");
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Given array is \n");
  printArray(arr, n);

  quickSort(arr, 0, n - 1);

  printf("\nSorted array is \n");
  printArray(arr, n);
  return 0;
}
