#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
  int data;
  struct Node *next;
};

// Function to insert a node at the beginning of a linked list
void insert(struct Node **head_ref, int new_data)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

// Function to print a linked list
void printList(struct Node *node)
{
  while (node != NULL)
  {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("NULL\n");
}

// Function to reverse a linked list
void reverse(struct Node **head_ref)
{
  struct Node *prev = NULL;
  struct Node *current = (*head_ref);
  struct Node *next = NULL;

  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  (*head_ref) = prev;
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");
  // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
  struct Node *head = NULL;
  insert(&head, 5);
  insert(&head, 4);
  insert(&head, 3);
  insert(&head, 2);
  insert(&head, 1);

  printf("Original linked list: ");
  printList(head);

  // Reverse the linked list
  reverse(&head);

  printf("Reversed linked list: ");
  printList(head);

  return 0;
}
