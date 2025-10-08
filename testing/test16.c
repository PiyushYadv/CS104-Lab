#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

// Function to create a new node
struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node **head, int data)
{
  struct Node *newNode = createNode(data);
  if (*head == NULL)
  {
    *head = newNode;
    (*head)->next = *head;
    (*head)->prev = *head;
  }
  else
  {
    struct Node *last = (*head)->prev;
    last->next = newNode;
    newNode->prev = last;
    newNode->next = *head;
    (*head)->prev = newNode;
  }
}

// Function to reverse a circular doubly linked list
void reverse(struct Node **head)
{
  if (*head == NULL)
    return;

  struct Node *current = *head;
  struct Node *temp = NULL;

  do
  {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  } while (current != *head);

  *head = temp->prev; // Move head to the last node
}

// Function to print a circular doubly linked list
void display(struct Node *head)
{
  if (head == NULL)
    return;

  struct Node *temp = head;

  do
  {
    printf("%d ", temp->data);
    temp = temp->next;
  } while (temp != head);
  printf("\n");
}

// Main function
int main()
{
  struct Node *head = NULL;

  // Inserting elements into the circular doubly linked list
  insertAtEnd(&head, 1);
  insertAtEnd(&head, 2);
  insertAtEnd(&head, 3);
  insertAtEnd(&head, 4);
  insertAtEnd(&head, 5);

  printf("Original list: ");
  display(head);

  // Reversing the circular doubly linked list
  reverse(&head);

  printf("Reversed list: ");
  display(head);

  return 0;
}
