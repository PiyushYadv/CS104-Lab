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
  while (temp->next != head)
  {
    temp = temp->next;
    count++;
  }
  return count;
}

void display(Node *head)
{
  Node *temp = head;
  while (temp->next != head)
  {
    printf("%d <=> ", temp->data);
    temp = temp->next;
  }
  printf("%d\n", temp->data);
}

void freeList(Node *head)
{
  if (head == NULL)
  {
    printf("No Linked List Present");
    return;
  }
  Node *temp;
  Node *first = head;
  do
  {
    temp = head;
    head = head->next;
    free(temp);
  } while (head != first);
}

void hasCycle(Node **head)
{
  Node *slowPtr = *head, *fastPtr = *head;
  while (fastPtr->next != NULL || fastPtr == NULL)
  {
    fastPtr = fastPtr->next->next;
    slowPtr = slowPtr->next;
    if (fastPtr == slowPtr)
    {
      printf("Cycle is present");
      return;
    }
  }
  printf("Cycle is not present");
}

void createCLL(Node **head)
{
  Node *last = *head;
  while (last->next != NULL)
  {
    last = last->next;
  }
  last->next = *head;
  (*head)->prev = last;
}

Node *insertAtBegin(Node *head, int data)
{
  if (head == NULL)
  {
    head = createNode(data);
    return head;
  }

  Node *newNode = createNode(data);
  Node *last = head;
  while (last->next != head)
  {
    last = last->next;
  }
  last->next = newNode;
  newNode->prev = last;
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
  return head;
}

void insertAtLast(Node **head, int data)
{
  if (*head == NULL)
  {
    *head = createNode(data);
    return;
  }
  Node *newNode = createNode(data);
  Node *temp = *head;
  while (temp->next != *head)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
  newNode->next = *head;
  (*head)->prev = newNode;
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
  while (fastPtr->next->next != *head)
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
    printf("No LinkedList to Delete");
    return;
  }
  Node *last = *head;
  while (last->next != *head)
  {
    last = last->next;
  }
  last->next = (*head)->next;
  (*head)->next->prev = last;
  Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void deleteLastNode(Node **head)
{
  if (*head == NULL)
  {
    printf("No LinkedList to Delete");
    return;
  }
  if ((*head)->next == *head)
  {
    deleteFirstNode(head);
    return;
  }
  Node *last = *head;
  Node *secondLast = *head;
  while (last->next != *head)
  {
    secondLast = last;
    last = last->next;
  }
  secondLast->next = *head;
  (*head)->prev = secondLast;
  free(last);
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

// void reverseLinkedList(Node **head)
// {
//   if (*head == NULL)
//   {
//     printf("No LinkedList to Reverse");
//     return;
//   }
//   Node *back = *head, *current = *head, *front = *head;
//   // Node *tail = *head;

//   // while (tail->next != *head)
//   // {
//   //   tail = tail->next;
//   // }
//   do
//   {
//     front = current->next;
//     current->next = back->prev;
//     current->prev = front;
//     back->prev = current;
//     back = current;
//     current = front;
//   } while (current != *head);

//   *head = back;
// }

int main()
{
  Node *head = createNode(1);
  Node *second = createNode(2);
  head->next = second;
  second->prev = head;
  Node *third = createNode(3);
  second->next = third;
  third->prev = second;
  createCLL(&head);
  head = insertAtBegin(head, 4);
  insertAtLast(&head, 5);
  insertAtPosition(&head, 6, 2);
  insertAtMiddle(&head, 7);
  display(head);
  // deleteFirstNode(&head);
  // deleteLastNode(&head);
  // deleteAtPosition(&head, 2);
  // reverseLinkedList(&head);
  display(head);
  hasCycle(&head);
  freeList(head);
  return 0;
}