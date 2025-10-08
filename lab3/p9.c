#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void insertBefore(struct Node **headRef, int x, int y)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = x;

  if (*headRef == NULL)
  {
    newNode->next = NULL;
    *headRef = newNode;
    return;
  }

  struct Node *prev = NULL;
  struct Node *current = *headRef;

  while (current != NULL && current->data != y)
  {
    prev = current;
    current = current->next;
  }

  if (current == NULL)
  {
    printf("Node with data %d not found.\n", y);
    free(newNode);
    return;
  }

  if (prev == NULL)
  {
    newNode->next = *headRef;
    *headRef = newNode;
  }
  else
  {
    newNode->next = current;
    prev->next = newNode;
  }
}

void printList(struct Node *head)
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void freeList(struct Node *head)
{
  struct Node *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");
  struct Node *head = NULL;

  insertBefore(&head, 5, 10);
  insertBefore(&head, 10, 5);
  insertBefore(&head, 15, 10);

  printf("Linked List after insertion: ");
  printList(head);

  freeList(head);

  return 0;
}
