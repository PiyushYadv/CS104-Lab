#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Queue
{
  struct Node *front, *rear;
};

struct Node *newNode(int data)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

struct Queue *createQueue()
{
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->front = queue->rear = NULL;
  return queue;
}

void enqueue(struct Queue *queue, int data)
{
  struct Node *temp = newNode(data);

  if (queue->rear == NULL)
  {
    queue->front = queue->rear = temp;
    return;
  }

  queue->rear->next = temp;
  queue->rear = temp;
}

void dequeue(struct Queue *queue)
{
  if (queue->front == NULL)
    return;

  struct Node *temp = queue->front;

  queue->front = queue->front->next;

  if (queue->front == NULL)
    queue->rear = NULL;

  free(temp);
}

int front(struct Queue *queue)
{
  if (queue->front == NULL)
    return -1;
  return queue->front->data;
}

int rear(struct Queue *queue)
{
  if (queue->rear == NULL)
    return -1;
  return queue->rear->data;
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");
  struct Queue *queue = createQueue();

  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);

  printf("Front element is: %d\n", front(queue));
  printf("Rear element is: %d\n", rear(queue));

  dequeue(queue);

  printf("Front element after dequeue is: %d\n", front(queue));

  return 0;
}
