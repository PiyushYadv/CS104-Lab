#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct
{
  int data[MAX_SIZE];
  int front, rear;
} CircularQueue;

// Function to initialize the circular queue
void initializeQueue(CircularQueue *queue)
{
  queue->front = -1;
  queue->rear = -1;
}

// Function to check if the circular queue is empty
int isEmpty(CircularQueue *queue)
{
  return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the circular queue is full
int isFull(CircularQueue *queue)
{
  return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue an element into the circular queue
void enqueue(CircularQueue *queue, int value)
{
  if (isFull(queue))
  {
    printf("Queue is full. Enqueue operation failed.\n");
    return;
  }

  if (isEmpty(queue))
    queue->front = queue->rear = 0;
  else
    queue->rear = (queue->rear + 1) % MAX_SIZE;

  queue->data[queue->rear] = value;
}

// Function to dequeue an element from the circular queue
int dequeue(CircularQueue *queue)
{
  int value;

  if (isEmpty(queue))
  {
    printf("Queue is empty. Dequeue operation failed.\n");
    return -1;
  }

  value = queue->data[queue->front];

  if (queue->front == queue->rear)
    queue->front = queue->rear = -1;
  else
    queue->front = (queue->front + 1) % MAX_SIZE;

  return value;
}

// Function to display the circular queue
void displayQueue(CircularQueue *queue)
{
  int i;

  if (isEmpty(queue))
  {
    printf("Queue is empty.\n");
    return;
  }

  printf("Circular Queue: ");
  for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE)
    printf("%d ", queue->data[i]);
  printf("%d\n", queue->data[i]);
}

int main()
{
  printf("Piyush Yadav\n 23/CS/301\n");
  CircularQueue queue;
  int choice, value;

  initializeQueue(&queue);

  do
  {
    printf("\nCircular Queue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value to enqueue: ");
      scanf("%d", &value);
      enqueue(&queue, value);
      break;
    case 2:
      value = dequeue(&queue);
      if (value != -1)
        printf("Dequeued element: %d\n", value);
      break;
    case 3:
      displayQueue(&queue);
      break;
    case 4:
      printf("Exiting the program.\n");
      break;
    default:
      printf("Invalid choice. Please enter a valid option.\n");
    }
  } while (choice != 4);

  return 0;
}
