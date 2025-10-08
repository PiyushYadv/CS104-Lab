#include <stdio.h>

int DSUM(int matrix[][100], int N, int M)
{
  int sum = 0;
  int row, col;

  for (row = 0; row < N; row++)
  {
    for (col = 0; col < M; col++)
    {
      if (row == col || row + col == N - 1)
      {
        sum += matrix[row][col];
      }
    }
  }

  return sum;
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");
  int N, M;
  printf("Enter the number of rows (N) and columns (M) of the matrix: ");
  scanf("%d %d", &N, &M);

  if (N % 2 == 0 || N != M)
  {
    printf("The number of rows must be odd and equal to the number of columns.\n");
    return 1;
  }

  int matrix[100][100];
  printf("Enter the elements of the matrix:\n");
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }

  int diagonalSum = DSUM(matrix, N, M);
  printf("The sum of diagonal elements is: %d\n", diagonalSum);

  return 0;
}
