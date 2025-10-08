#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} Node;

Node *createNode(int data)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

int nodeLength(Node *head)
{
  if (head == NULL)
  {
    printf("No Linked List Present");
    return 0;
  }
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
  if (head == NULL)
  {
    printf("No Linked List Present");
    return;
  }
  Node *temp = head;
  while (temp->next != head)
  {
    printf("%d -> ", temp->data);
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
  newNode->next = head;
  head = newNode;
  return head;
}

void insertAtEnd(Node **head, int data)
{
  if (*head == NULL)
  {
    *head = createNode(data);
    return;
  }
  Node *newNode = createNode(data);

  Node *last = *head;
  while (last->next != *head)
  {
    last = last->next;
  }

  last->next = newNode;
  newNode->next = *head;
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
    insertAtEnd(head, data);
    return;
  }
  Node *temp = *head;
  while (i < pos)
  {
    temp = temp->next;
    i++;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

void insertAtMiddle(Node **head, int data)
{
  if (*head == NULL)
  {
    *head = createNode(data);
    return;
  }
  Node *newNode = createNode(data);

  Node *fastPtr = *head, *slowPtr = *head;
  while (fastPtr->next->next != *head)
  {
    fastPtr = fastPtr->next->next;
    slowPtr = slowPtr->next;
  }
  newNode->next = slowPtr->next;
  slowPtr->next = newNode;
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
  free(last);
}

void deleteFromPosition(Node **head, int pos)
{
  if (*head == NULL)
  {
    printf("No LinkedList to Delete");
    return;
  }
  int i = 1;
  int count = nodeLength(*head);
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
  Node *prev = *head, *current = *head;
  while (i < pos)
  {
    prev = current;
    current = current->next;
    i++;
  }
  prev->next = current->next;
  free(current);
}

void reverseLinkedList(Node **head)
{
  if (*head == NULL)
  {
    printf("No LinkedList to Reverse");
    return;
  }
  Node *back = NULL, *current = *head, *front = *head;
  do
  {
    front = current->next;
    current->next = back;
    back = current;
    current = front;
  } while (current != *head);
  (*head)->next = back;
  *head = back;
}

int main()
{
  Node *head = createNode(1);
  head->next = createNode(2);
  head->next->next = createNode(3);
  createCLL(&head);
  head = insertAtBegin(head, 4);
  insertAtEnd(&head, 5);
  insertAtPosition(&head, 6, 2);
  insertAtMiddle(&head, 7);
  // deleteFirstNode(&head);
  // deleteLastNode(&head);
  // deleteFromPosition(&head, 2);
  display(head);
  reverseLinkedList(&head);
  display(head);
  hasCycle(&head);
  freeList(head);
  return 0;
}