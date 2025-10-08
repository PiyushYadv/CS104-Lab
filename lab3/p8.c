#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void insertAtEnd(struct Node **headRef, int x)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = x;
  newNode->next = NULL;

  if (*headRef == NULL)
  {
    *headRef = newNode;
    return;
  }

  struct Node *last = *headRef;
  while (last->next != NULL)
  {
    last = last->next;
  }

  last->next = newNode;
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

  insertAtEnd(&head, 5);
  insertAtEnd(&head, 10);
  insertAtEnd(&head, 15);

  printf("Linked List after insertion: ");
  printList(head);

  freeList(head);

  return 0;
}
