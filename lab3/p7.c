#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *insertAtBeginning(struct Node *head, int x)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = x;
  newNode->next = head;
  return newNode;
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

  head = insertAtBeginning(head, 15);
  head = insertAtBeginning(head, 10);
  head = insertAtBeginning(head, 5);

  printf("Linked List after insertion: ");
  printList(head);

  freeList(head);

  return 0;
}
