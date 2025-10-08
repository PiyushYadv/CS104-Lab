#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
  int data[MAX_SIZE];
  int top1; // Top index of first stack
  int top2; // Top index of second stack
} Queue;

// Function to initialize the queue
Queue *initializeQueue()
{
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->top1 = -1;
  queue->top2 = -1;
  return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue)
{
  return (queue->top1 == -1 && queue->top2 == -1);
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int x)
{
  if (queue->top1 == MAX_SIZE - 1)
  {
    printf("Queue is full. Enqueue operation failed.\n");
    return;
  }

  // Move all elements from stack 2 to stack 1
  while (queue->top2 != -1)
  {
    queue->data[++queue->top1] = queue->data[queue->top2--];
  }

  // Add the new element to the top of stack 1
  queue->data[++queue->top1] = x;
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty. Dequeue operation failed.\n");
    return -1;
  }

  // If stack 2 is empty, move all elements from stack 1 to stack 2
  if (queue->top2 == -1)
  {
    while (queue->top1 != -1)
    {
      queue->data[++queue->top2] = queue->data[queue->top1--];
    }
  }

  // Return the top element of stack 2
  return queue->data[queue->top2--];
}

int main()
{
  printf("Piyush Yadav\n 23/CS/301\n");
  Queue *queue = initializeQueue();

  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);

  printf("Dequeued element: %d\n", dequeue(queue));
  printf("Dequeued element: %d\n", dequeue(queue));

  enqueue(queue, 40);
  enqueue(queue, 50);

  printf("Dequeued element: %d\n", dequeue(queue));
  printf("Dequeued element: %d\n", dequeue(queue));

  free(queue);

  return 0;
}
