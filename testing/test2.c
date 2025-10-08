#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *prev;
  struct Node *next;
} Node;

Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}

int nodeLength(Node *head)
{
  int count;
  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
    count++;
  }
  return count;
}

void display(Node *head)
{
  Node *temp = head;
  while (temp->next != NULL)
  {
    printf("%d <=> ", temp->data);
    temp = temp->next;
    if (temp->next == NULL)
    {
      printf("%d", temp->data);
    }
  }
  printf("\n");
}

void freeList(Node *head)
{
  Node *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}

Node *insertAtBegin(Node *head, int data)
{
  Node *newNode = createNode(data);
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
  return newNode;
}

void insertAtLast(Node **head, int data)
{
  Node *newNode = createNode(data);
  Node *temp = *head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
}

void insertAtPosition(Node **head, int data, int pos)
{
  int count = nodeLength(*head);
  int i = 1;
  Node *newNode = createNode(data);
  if (pos <= 0 || pos > count)
  {
    printf("Invalid pos");
    return;
  }
  else if (pos == 1)
  {
    printf("Use insert at begin\n");
    *head = insertAtBegin(*head, data);
    return;
  }
  else if (pos == count)
  {
    printf("Use insert at end\n");
    insertAtLast(head, data);
    return;
  }
  Node *temp = *head;
  Node *prev = NULL;
  while (i < pos)
  {
    prev = temp;
    temp = temp->next;
    i++;
  }
  prev->next = newNode;
  newNode->prev = prev;
  newNode->next = temp;
  temp->prev = newNode;
}

void insertAtMiddle(Node **head, int data)
{
  if (*head == NULL)
  {
    *head = createNode(data);
    return;
  }
  Node *newNode = createNode(data);
  Node *slowPtr = *head, *fastPtr = *head;
  Node *next = NULL;
  while (fastPtr->next->next != NULL)
  {
    slowPtr = slowPtr->next;
    next = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  next->prev = newNode;
  newNode->next = next;
  slowPtr->next = newNode;
  newNode->prev = slowPtr;
}

void deleteFirstNode(Node **head)
{
  if (*head == NULL)
  {
    printf("No Linked List to delete");
    return;
  }
  Node *temp = *head;
  *head = (*head)->next;
  (*head)->prev = NULL;
  free(temp);
}

void deleteLastNode(Node **head)
{
  if (*head == NULL)
  {
    printf("No Linked List to delete");
    return;
  }
  if ((*head)->next == NULL)
  {
    deleteFirstNode(head);
    return;
  }
  Node *current = *head;
  Node *tail = NULL;
  while (current->next != NULL)
  {
    tail = current;
    current = current->next;
  }
  current->prev = NULL;
  tail->next = NULL;
  free(current);
}

void deleteAtPosition(Node **head, int pos)
{
  if (*head == NULL)
  {
    printf("No Linked List to delete");
    return;
  }
  int count = nodeLength(*head);
  int i = 1;
  if (pos <= 0 || pos > count)
  {
    printf("Invalid pos");
    return;
  }
  else if (pos == 1)
  {
    printf("Use delete at begin\n");
    deleteFirstNode(head);
    return;
  }
  else if (pos == count)
  {
    printf("Use delete at end\n");
    deleteLastNode(head);
    return;
  }
  Node *current = *head, *front = NULL, *tail = NULL;
  while (i < pos)
  {
    front = current;
    current = current->next;
    tail = current->next;
    i++;
  }
  front->next = tail;
  tail->prev = front;
  free(current);
}

void reverseLinkedList(Node **head)
{
  if (*head == NULL)
  {
    printf("No Linked List to reverse");
    return;
  }
  Node *current = *head, *temp = NULL;
  while (current != NULL)
  {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  *head = temp->prev;
}

int main()
{
  Node *head = createNode(1);
  Node *second = createNode(2);
  head->next = second;
  second->prev = head;
  Node *third = createNode(3);
  second->next = third;
  third->prev = second;
  display(head);
  head = insertAtBegin(head, 0);
  display(head);
  insertAtLast(&head, 4);
  display(head);
  insertAtPosition(&head, 5, 3);
  display(head);
  insertAtMiddle(&head, 6);
  display(head);
  deleteFirstNode(&head);
  display(head);
  deleteLastNode(&head);
  display(head);
  deleteAtPosition(&head, 2);
  display(head);
  reverseLinkedList(&head);
  display(head);

  freeList(head);

  return 0;
}