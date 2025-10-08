#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void deleteFirstNode(struct Node **headRef)
{
  if (*headRef == NULL)
  {
    printf("Linked list is empty. No node to delete.\n");
    return;
  }

  struct Node *temp = *headRef;
  *headRef = (*headRef)->next;
  free(temp);
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

  head = (struct Node *)malloc(sizeof(struct Node));
  head->data = 5;
  head->next = NULL;

  // Deleting the only node in the list

  struct Node *second = (struct Node *)malloc(sizeof(struct Node));
  second->data = 10;
  second->next = NULL;
  head->next = second;

  struct Node *third = (struct Node *)malloc(sizeof(struct Node));
  third->data = 15;
  third->next = NULL;
  second->next = third;

  printf("Linked List before deletion: ");
  printList(head);

  deleteFirstNode(&head); // Deleting the first node

  printf("Linked List after deletion: ");
  printList(head);

  freeList(head);

  return 0;
}
