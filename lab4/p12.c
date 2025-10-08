#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *findMiddle(struct Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }

  struct Node *slowPtr = head;
  struct Node *fastPtr = head;

  while (fastPtr != NULL && fastPtr->next != NULL)
  {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }

  return slowPtr;
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

  // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
  head = (struct Node *)malloc(sizeof(struct Node));
  head->data = 1;
  head->next = NULL;

  struct Node *current = head;
  for (int i = 2; i <= 5; i++)
  {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = i;
    newNode->next = NULL;
    current->next = newNode;
    current = newNode;
  }

  printf("Linked List: ");
  printList(head);

  struct Node *middleNode = findMiddle(head);
  printf("Middle Node: %d\n", middleNode->data);

  freeList(head);

  return 0;
}
