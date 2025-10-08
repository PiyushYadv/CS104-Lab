#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Deque
{
  char items[MAX_SIZE];
  int front, rear;
};

struct Deque *createDeque()
{
  struct Deque *deque = (struct Deque *)malloc(sizeof(struct Deque));
  deque->front = -1;
  deque->rear = -1;
  return deque;
}

int isFull(struct Deque *deque)
{
  return (deque->front == 0 && deque->rear == MAX_SIZE - 1) || (deque->front == deque->rear + 1);
}

int isEmpty(struct Deque *deque)
{
  return deque->front == -1;
}

void insertFront(struct Deque *deque, char value)
{
  if (isFull(deque))
  {
    printf("Deque is full\n");
  }
  else
  {
    if (deque->front == -1)
    {
      deque->front = 0;
      deque->rear = 0;
    }
    else if (deque->front == 0)
    {
      deque->front = MAX_SIZE - 1;
    }
    else
    {
      deque->front--;
    }
    deque->items[deque->front] = value;
  }
}

void insertRear(struct Deque *deque, char value)
{
  if (isFull(deque))
  {
    printf("Deque is full\n");
  }
  else
  {
    if (deque->front == -1)
    {
      deque->front = 0;
      deque->rear = 0;
    }
    else if (deque->rear == MAX_SIZE - 1)
    {
      deque->rear = 0;
    }
    else
    {
      deque->rear++;
    }
    deque->items[deque->rear] = value;
  }
}

char deleteFront(struct Deque *deque)
{
  char value;
  if (isEmpty(deque))
  {
    printf("Deque is empty\n");
    value = '\0';
  }
  else
  {
    value = deque->items[deque->front];
    if (deque->front == deque->rear)
    {
      deque->front = -1;
      deque->rear = -1;
    }
    else if (deque->front == MAX_SIZE - 1)
    {
      deque->front = 0;
    }
    else
    {
      deque->front++;
    }
  }
  return value;
}

char deleteRear(struct Deque *deque)
{
  char value;
  if (isEmpty(deque))
  {
    printf("Deque is empty\n");
    value = '\0';
  }
  else
  {
    value = deque->items[deque->rear];
    if (deque->front == deque->rear)
    {
      deque->front = -1;
      deque->rear = -1;
    }
    else if (deque->rear == 0)
    {
      deque->rear = MAX_SIZE - 1;
    }
    else
    {
      deque->rear--;
    }
  }
  return value;
}

int isPalindrome(char *str)
{
  struct Deque *deque = createDeque();
  int length = strlen(str);
  int i;

  for (i = 0; i < length; i++)
  {
    char ch = tolower(str[i]);
    if (isalpha(ch))
    {
      insertRear(deque, ch);
    }
  }

  while (!isEmpty(deque) && deque->front != deque->rear)
  {
    char frontChar = deleteFront(deque);
    char rearChar = deleteRear(deque);
    if (frontChar != rearChar)
    {
      return 0;
    }
  }

  return 1;
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");
  char str[MAX_SIZE];
  printf("Enter a string: ");
  fgets(str, MAX_SIZE, stdin);
  str[strcspn(str, "\n")] = '\0';

  if (isPalindrome(str))
  {
    printf("The string \"%s\" is a palindrome.\n", str);
  }
  else
  {
    printf("The string \"%s\" is not a palindrome.\n", str);
  }

  return 0;
}
