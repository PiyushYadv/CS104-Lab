#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Queue
{
  int items[MAX_SIZE];
  int front, rear;
};

struct Queue *createQueue()
{
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->front = -1;
  queue->rear = -1;
  return queue;
}

int isFull(struct Queue *queue)
{
  return (queue->rear == MAX_SIZE - 1);
}

int isEmpty(struct Queue *queue)
{
  return (queue->front == -1 && queue->rear == -1);
}

void enqueue(struct Queue *queue, int value)
{
  if (isFull(queue))
  {
    printf("Queue is full\n");
  }
  else
  {
    if (isEmpty(queue))
    {
      queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = value;
  }
}

int dequeue(struct Queue *queue)
{
  int value;
  if (isEmpty(queue))
  {
    printf("Queue is empty\n");
    value = -1;
  }
  else
  {
    value = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear)
    {
      queue->front = queue->rear = -1;
    }
  }
  return value;
}

void reverseFirstK(struct Queue *queue, int k)
{
  if (isEmpty(queue) || k <= 0)
  {
    return;
  }

  int stack[k];
  int i;

  for (i = 0; i < k; i++)
  {
    stack[i] = dequeue(queue);
  }

  for (i = k - 1; i >= 0; i--)
  {
    enqueue(queue, stack[i]);
  }

  // while (!isEmpty(queue))
  // {
  //   enqueue(queue, dequeue(queue));
  // }
}

void printQueue(struct Queue *queue)
{
  int i;
  if (isEmpty(queue))
  {
    printf("Queue is empty\n");
  }
  else
  {
    printf("Queue contains: ");
    for (i = queue->front; i < queue->rear + 1; i++)
    {
      printf("%d ", queue->items[i]);
    }
    printf("\n");
  }
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");
  struct Queue *queue = createQueue();

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);
  enqueue(queue, 6);
  enqueue(queue, 7);
  enqueue(queue, 8);
  enqueue(queue, 9);
  enqueue(queue, 10);

  printf("Original queue: ");
  printQueue(queue);

  int k = 5;
  reverseFirstK(queue, k);

  printf("Queue after reversing first %d elements: ", k);
  printQueue(queue);

  return 0;
}
