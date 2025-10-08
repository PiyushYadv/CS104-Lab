#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *createNode(int data)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

int isEmpty(Node *head)
{
  if (head == NULL)
    return 0;
  return 1;
}

void enQueue(Node **head, int data)
{
  Node *temp = createNode(data);
  Node *last = *head;
  while ((last)->next != NULL)
  {
    last = last->next;
  }
  last->next = temp;
}

void deQueue(Node **head)
{
  if (*head == NULL)
  {
    printf("Queue is empty\n");
    return;
  }
  Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void display(Node *head)
{
  Node *temp = head;
  while (temp->next != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("%d", temp->data);
}

void freeNode(Node *head)
{
  if (head == NULL)
  {
    printf("No Linked List Present");
    return;
  }
  Node *temp;
  while (head != NULL)
  {
    temp = head;
    head = temp->next;
    free(temp);
  }
}

int main()
{
  Node *head = createNode(1);
  Node *second = createNode(2);
  head->next = second;
  enQueue(&head, 3);
  enQueue(&head, 4);
  deQueue(&head);
  display(head);
  freeNode(head);
  return 0;
}