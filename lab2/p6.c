#include <stdio.h>

void prepareColumnMajor(int A[][100], int n, int B[])
{
  int index = 0;
  for (int col = 0; col < n; col++)
  {
    for (int row = 0; row < n; row++)
    {
      B[index++] = A[row][col];
    }
  }
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");
  int n;
  printf("Enter the size of the square matrix: ");
  scanf("%d", &n);

  int A[100][100];
  printf("Enter the elements of the matrix:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &A[i][j]);
    }
  }

  int B[n * n];
  prepareColumnMajor(A, n, B);

  printf("Resultant array (in column-major form):\n");
  for (int i = 0; i < n * n; i++)
  {
    printf("%d ", B[i]);
  }
  printf("\n");

  return 0;
}