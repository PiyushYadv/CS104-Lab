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

// Function to detect a cycle in a linked list
int detectCycle(struct Node *head)
{
  struct Node *slow_ptr = head;
  struct Node *fast_ptr = head;

  while (slow_ptr && fast_ptr && fast_ptr->next)
  {
    slow_ptr = slow_ptr->next;
    fast_ptr = fast_ptr->next->next;

    if (slow_ptr == fast_ptr)
    {
      // Cycle detected
      return 1;
    }
  }
  // No cycle detected
  return 0;
}

int main()
{
  // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (creating a cycle)
  printf("Piyush Yadav - 23/CS/301\n");

  struct Node *head = NULL;
  insert(&head, 5);
  insert(&head, 4);
  insert(&head, 3);
  insert(&head, 2);
  insert(&head, 1);

  // Create a cycle
  head->next->next->next->next->next = head->next->next;

  // Detect cycle
  if (detectCycle(head))
    printf("Cycle found in the linked list.\n");
  else
    printf("No cycle found in the linked list.\n");

  return 0;
}
