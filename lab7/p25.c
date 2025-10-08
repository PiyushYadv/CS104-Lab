#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *prev;
  struct Node *next;
};

struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void insertEnd(struct Node **head, int data)
{
  struct Node *newNode = createNode(data);
  if (*head == NULL)
  {
    *head = newNode;
    return;
  }
  struct Node *temp = *head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
}

void findPairs(struct Node *head, int targetSum)
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  struct Node *first = head, *last = head;
  while (last->next != NULL)
  {
    last = last->next;
  }

  while (first != NULL && last != NULL && first != last && last->next != first)
  {
    int sum = first->data + last->data;
    if (sum == targetSum)
    {
      printf("(%d, %d)\n", first->data, last->data);
      first = first->next;
      last = last->prev;
    }
    else if (sum < targetSum)
    {
      first = first->next;
    }
    else
    {
      last = last->prev;
    }
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

  insertEnd(&head, 1);
  insertEnd(&head, 2);
  insertEnd(&head, 3);
  insertEnd(&head, 4);
  insertEnd(&head, 5);

  printf("Original list: ");
  printList(head);

  int targetSum = 6;
  printf("Pairs with sum %d:\n", targetSum);
  findPairs(head, targetSum);

  freeList(head);

  return 0;
}
