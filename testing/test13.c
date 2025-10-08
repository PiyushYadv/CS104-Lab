#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(int *A, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

void bubbleSort(int *A, int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (A[j] > A[j + 1])
      {
        swap(A + j, A + j + 1);
      }
    }
  }
}

void insertionSort(int *A, int n)
{
  int key, j;
  for (int i = 1; i <= n - 1; i++)
  {
    key = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > key)
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;
  }
}

void selectionSort(int *A, int n)
{
  int indexOfMin;
  for (int i = 0; i < n - 1; i++)
  {
    indexOfMin = i;
    for (int j = i + 1; j < n; j++)
    {
      if (A[j] < A[indexOfMin])
      {
        indexOfMin = j;
      }
    }
    swap(A + i, A + indexOfMin);
  }
}

int partition(int *A, int low, int high)
{
  int pivot = A[low];
  int i = low + 1;
  int j = high;
  do
  {
    while (A[i] <= pivot)
    {
      i++;
    }
    while (A[j] > pivot)
    {
      j--;
    }

    if (i < j)
    {
      swap(&A[i], &A[j]);
    }
  } while (i < j);

  swap(&A[low], &A[j]);

  return j;
}

void quickSort(int *A, int low, int high)
{
  int partitionIndex;

  if (low < high)
  {
    partitionIndex = partition(A, low, high);
    quickSort(A, low, partitionIndex - 1);
    quickSort(A, partitionIndex + 1, high);
  }
}

void merge(int *A, int mid, int low, int high)
{
  int i, j, k;
  i = low;
  j = mid + 1;
  k = low;
  // int *B = (int *)malloc(sizeof(int) * (high - low + 1));
  int B[100];

  while (i <= mid && j <= high)
  {
    if (A[i] < A[j])
    {
      B[k] = A[i];
      i++;
    }
    else
    {
      B[k] = A[j];
      j++;
    }
    k++;
  }

  while (i <= mid)
  {
    B[k] = A[i];
    i++;
    k++;
  }
  while (j <= high)
  {
    B[k] = A[j];
    j++;
    k++;
  }

  for (int i = 0; i <= high; i++)
  {
    A[i] = B[i];
  }
}

void mergeSort(int *A, int low, int high)
{
  int mid;
  if (low < high)
  {
    mid = low + (high - low) / 2;

    mergeSort(A, low, mid);
    mergeSort(A, mid + 1, high);
    merge(A, mid, low, high);
  }
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{
  // Find largest among root,
  // left child and right child

  // Initialize largest as root
  int largest = i;

  // left = 2*i + 1
  int left = 2 * i + 1;

  // right = 2*i + 2
  int right = 2 * i + 2;

  // If left child is larger than root
  if (left < N && arr[left] > arr[largest])

    largest = left;

  // If right child is larger than largest
  // so far
  if (right < N && arr[right] > arr[largest])

    largest = right;

  // Swap and continue heapifying
  // if root is not largest
  // If largest is not root
  if (largest != i)
  {

    swap(&arr[i], &arr[largest]);

    // Recursively heapify the affected
    // sub-tree
    heapify(arr, N, largest);
  }
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

  // Build max heap
  for (int i = N / 2 - 1; i >= 0; i--)

    heapify(arr, N, i);

  // Heap sort
  for (int i = N - 1; i >= 0; i--)
  {

    swap(&arr[0], &arr[i]);

    // Heapify root element
    // to get highest element at
    // root again
    heapify(arr, i, 0);
  }
}

int main()
{
  int A[] = {12, 54, 65, 7, 23, 9};
  int n = 6;
  printArray(A, n);
  // bubbleSort(A, n);
  // insertionSort(A, n);
  selectionSort(A, n);
  // quickSort(A, 0, n - 1);
  // mergeSort(A, 0, n - 1);
  // heapSort(A, n);
  printArray(A, n);
  return 0;
}