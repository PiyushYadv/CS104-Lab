#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *reverseLinkedList(struct Node *head)
{
  struct Node *prev = NULL;
  struct Node *current = head;
  struct Node *next = NULL;

  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  return prev; // 'prev' will be the new head of the reversed linked list
}

// Helper function to create a new node
struct Node *newNode(int data)
{
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// Helper function to print the linked list
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

// Helper function to free the allocated memory for the linked list
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
  // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
  printf("Piyush Yadav - 23/CS/301\n");
  struct Node *head = newNode(1);
  head->next = newNode(2);
  head->next->next = newNode(3);
  head->next->next->next = newNode(4);
  head->next->next->next->next = newNode(5);

  printf("Original linked list: ");
  printList(head);

  // Reverse the linked list
  head = reverseLinkedList(head);

  printf("Reversed linked list: ");
  printList(head);

  // Free allocated memory for the linked list
  freeList(head);

  return 0;
}
