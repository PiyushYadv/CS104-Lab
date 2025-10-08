#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *newNode(int val)
{
  struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
  node->val = val;
  node->next = NULL;
  return node;
}

void splitList(struct ListNode *head, struct ListNode **frontRef, struct ListNode **backRef)
{
  if (head == NULL || head->next == NULL)
  {
    *frontRef = head;
    *backRef = NULL;
    return;
  }

  struct ListNode *slow = head;
  struct ListNode *fast = head->next;

  while (fast != NULL)
  {
    fast = fast->next;
    if (fast != NULL)
    {
      slow = slow->next;
      fast = fast->next;
    }
  }

  *frontRef = head;
  *backRef = slow->next;
  slow->next = NULL;
}

void printList(struct ListNode *head)
{
  struct ListNode *current = head;
  while (current != NULL)
  {
    printf("%d ", current->val);
    current = current->next;
  }
  printf("\n");
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");

  struct ListNode *head = newNode(1);
  head->next = newNode(2);
  head->next->next = newNode(3);
  head->next->next->next = newNode(4);
  head->next->next->next->next = newNode(5);

  printf("Original list: ");
  printList(head);

  struct ListNode *front = NULL;
  struct ListNode *back = NULL;

  splitList(head, &front, &back);

  printf("Front sub-list: ");
  printList(front);

  printf("Back sub-list: ");
  printList(back);

  return 0;
}
