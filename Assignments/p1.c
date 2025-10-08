#include <stdio.h>
#define MAX_SIZE 100 // Maximum size of the array A

int A[MAX_SIZE];     // Array to store the elements of the stacks
int top1 = -1;       // Top index of stack 1
int top2 = MAX_SIZE; // Top index of stack 2 (starts from the end of the array)

// Function to add an element X to stack i
void ADD(int i, int X)
{
  if (top1 + 1 == top2)
  {
    printf("No space left in the array to add elements.\n");
    return;
  }

  if (i == 1)
  {
    A[++top1] = X; // Add X to stack 1
  }
  else if (i == 2)
  {
    A[--top2] = X; // Add X to stack 2
  }
  else
  {
    printf("Invalid stack index.\n");
  }
}

// Function to delete an element from stack i
void DELETE(int i)
{
  if (i == 1)
  {
    if (top1 == -1)
    {
      printf("Stack 1 is empty.\n");
      return;
    }
    printf("Deleted element from stack 1: %d\n", A[top1--]);
  }
  else if (i == 2)
  {
    if (top2 == MAX_SIZE)
    {
      printf("Stack 2 is empty.\n");
      return;
    }
    printf("Deleted element from stack 2: %d\n", A[top2++]);
  }
  else
  {
    printf("Invalid stack index.\n");
  }
}
int main()
{
  printf("Piyush Yadav\n 23/CS/301\n");
  // Example usage:
  ADD(1, 10); // Add 10 to stack 1
  ADD(1, 20); // Add 20 to stack 1
  ADD(2, 30); // Add 30 to stack 2
  DELETE(1);  // Delete from stack 1
  DELETE(2);  // Delete from stack 2
  return 0;
}
