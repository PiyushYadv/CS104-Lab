#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void deleteSecondLastNode(struct Node **headRef)
{
  if (*headRef == NULL || (*headRef)->next == NULL)
  {
    printf("Linked list is empty or contains only one node. No second last node to delete.\n");
    return;
  }

  struct Node *prev = NULL;
  struct Node *current = *headRef;

  while (current->next->next != NULL)
  {
    prev = current;
    current = current->next;
  }

  struct Node *temp = prev->next;
  prev->next = temp->next;
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

  struct Node *second = (struct Node *)malloc(sizeof(struct Node));
  second->data = 10;
  head->next = second;

  struct Node *third = (struct Node *)malloc(sizeof(struct Node));
  third->data = 15;
  third->next = NULL;
  head->next->next = third;

  printf("Linked List before deletion: ");
  printList(head);

  deleteSecondLastNode(&head); // Deleting the second last node

  printf("Linked List after deletion: ");
  printList(head);

  freeList(head);

  return 0;
}
