#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
  int data;
  struct Node *next;
};

bool hasCycle(struct Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return false;
  }

  struct Node *slowPtr = head;
  struct Node *fastPtr = head;

  while (fastPtr != NULL && fastPtr->next != NULL)
  {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;

    if (slowPtr == fastPtr)
    {
      return true; // Cycle detected
    }
  }

  return false; // No cycle found
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

// Helper function to create a cycle in the linked list for testing
void createCycle(struct Node *head, int pos)
{
  if (pos == -1)
  {
    return; // No cycle needed
  }

  struct Node *tail = head;
  while (tail->next != NULL)
  {
    tail = tail->next;
  }

  struct Node *cycleNode = head;
  for (int i = 0; i < pos; i++)
  {
    cycleNode = cycleNode->next;
  }

  tail->next = cycleNode;
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

  // Uncomment the line below to create a cycle (e.g., linking the last node back to the second node)
  createCycle(head, 1);

  // Check if the linked list has a cycle
  if (hasCycle(head))
  {
    printf("Linked list has a cycle.\n");
  }
  else
  {
    printf("Linked list does not have a cycle.\n");
  }

  return 0;
}
