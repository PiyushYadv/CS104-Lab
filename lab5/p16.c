#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct TwoStacks
{
  int top1;
  int top2;
  int array[MAX_SIZE];
};

struct TwoStacks *createTwoStacks()
{
  struct TwoStacks *ts = (struct TwoStacks *)malloc(sizeof(struct TwoStacks));
  ts->top1 = -1;
  ts->top2 = MAX_SIZE;
  return ts;
}

void push1(struct TwoStacks *ts, int data)
{
  if (ts->top1 < ts->top2 - 1)
  {
    ts->array[++ts->top1] = data;
  }
  else
  {
    printf("Stack Overflow\n");
  }
}

void push2(struct TwoStacks *ts, int data)
{
  if (ts->top1 < ts->top2 - 1)
  {
    ts->array[--ts->top2] = data;
  }
  else
  {
    printf("Stack Overflow\n");
  }
}

int pop1(struct TwoStacks *ts)
{
  if (ts->top1 >= 0)
  {
    return ts->array[ts->top1--];
  }
  else
  {
    printf("Stack 1 Underflow\n");
    return -1;
  }
}

int pop2(struct TwoStacks *ts)
{
  if (ts->top2 < MAX_SIZE)
  {
    return ts->array[ts->top2++];
  }
  else
  {
    printf("Stack 2 Underflow\n");
    return -1;
  }
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");

  struct TwoStacks *ts = createTwoStacks();

  push1(ts, 10);
  push2(ts, 20);
  push1(ts, 30);
  push2(ts, 40);

  printf("Popped element from stack 1: %d\n", pop1(ts));
  printf("Popped element from stack 2: %d\n", pop2(ts));

  free(ts);

  return 0;
}
