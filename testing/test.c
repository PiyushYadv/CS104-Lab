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
  while (temp->next != NULL)
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
  while (temp->next != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
    if (temp->next == NULL)
    {
      printf("%d", temp->data);
    }
  }
}

void freeList(Node *head)
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
    head = head->next;
    free(temp);
  }
}

Node *insertAtBegin(Node *head, int data)
{
  Node *newNode = createNode(data);
  if (head == NULL)
  {
    head = newNode;
    return head;
  }
  newNode->next = head;
  head = newNode;
  return head;
}

void insertAtEnd(Node **head, int data)
{
  Node *newNode = createNode(data);

  if (*head == NULL)
  {
    *head = newNode;
    return;
  }

  Node *last = *head;
  while (last->next != NULL)
  {
    last = last->next;
  }

  last->next = newNode;
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
  Node *newNode = createNode(data);
  if (*head == NULL)
  {
    *head = newNode;
    return;
  }
  Node *fastPtr = *head, *slowPtr = *head;
  while (fastPtr->next != NULL)
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
  if ((*head)->next == NULL)
  {
    deleteFirstNode(*head);
    return;
  }
  Node *last = *head;
  Node *secondLast = *head;
  while (last->next != NULL)
  {
    secondLast = last;
    last = last->next;
  }
  secondLast->next = NULL;
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
    deleteFirstNode(*head);
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
  Node *prev = NULL, *current = *head, *next = *head;
  while (next != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}

int main()
{
  Node *head = createNode(1);
  head = insertAtBegin(head, 2);
  head = insertAtBegin(head, 3);
  insertAtEnd(&head, 5);
  insertAtPosition(&head, 6, 2);
  insertAtMiddle(&head, 7);
  // deleteFirstNode(&head);
  // deleteLastNode(&head);
  // deleteFromPosition(&head, 2);
  printf("%d\n", nodeLength(head));
  display(head);
  printf("\n");
  reverseLinkedList(&head);
  display(head);
  freeList(head);
  return 0;
}