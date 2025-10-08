#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10

typedef struct Stack
{
  char *exp;
  int top;
} Stack;

Stack *createStack()
{
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->exp = (char *)malloc(sizeof(char) * SIZE);
  stack->top = -1;
  return stack;
}

int isEmpty(Stack *s)
{
  if (s->top == -1)
    return 1;
  return 0;
}

int isFull(Stack *s)
{
  if (s->top == SIZE)
    return 1;
  return 0;
}

void display(Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack empty\n");
    return;
  }
  for (int i = 0; i <= s->top; i++)
  {
    printf("%c ", s->exp[i]);
  }
  printf("\n");
}

char peek(Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack empty\n");
    return -1;
  }
  return s->exp[s->top];
}

void push(Stack *s, char ch)
{
  if (isFull(s))
  {
    printf("Stack full\n");
    return;
  }
  s->exp[++s->top] = ch;
}

char pop(Stack *s)
{
  return s->exp[s->top--];
}

int prec(char c)
{
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

void infixToPostfix(char *infix)
{
  Stack *op = createStack();
  char *postfix = (char *)malloc(sizeof(char) * SIZE);
  int len = strlen(infix);
  int opIndex = 0;
  for (int i = 0; i < len; i++)
  {
    char c = infix[i];
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
      postfix[opIndex++] = c;
    }
    else
    {
      while (op->top >= 0 && (prec(c) <= prec(peek(op))))
      {
        postfix[opIndex++] = pop(op);
      }
      push(op, c);
    }
  }
  while (op->top >= 0)
  {
    postfix[opIndex++] = pop(op);
  }
  postfix[opIndex] = '\0';
  printf("%s\n", postfix);
}

void postfixEvaluation(char *postfix)
{
  Stack *op = createStack();
  for (int i = 0; postfix[i]; ++i)
  {
    if (isdigit(postfix[i]))
    {
      push(op, postfix[i] - '0');
    }
    else
    {
      int val1 = pop(op);
      int val2 = pop(op);
      switch (postfix[i])
      {
      case '+':
        push(op, val2 + val1);
        break;
      case '-':
        push(op, val2 - val1);
        break;
      case '*':
        push(op, val2 * val1);
        break;
      case '/':
        push(op, val2 / val1);
        break;
      }
    }
  }
  printf("%d", pop(op));
}

int isMatchingPair(char character1, char character2)
{
  if (character1 == '(' && character2 == ')')
    return 1;
  else if (character1 == '{' && character2 == '}')
    return 1;
  else if (character1 == '[' && character2 == ']')
    return 1;
  else
    return 0;
}

int areBalanced(char *exp)
{
  Stack *op = createStack();
  for (int i = 0; exp[i]; ++i)
  {
    if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
      push(op, exp[i]);

    if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
    {
      if (op->top == -1)
        return 0;

      else if (!isMatchingPair(pop(op), exp[i]))
        return 0;
    }
  }
  if (op->top == -1)
    return 1; // balanced
  else
    return 0;
}

int main()
{
  infixToPostfix("a+b*c+d");
  postfixEvaluation("231*+9-");
  printf("\n%d", areBalanced("{()}[]"));
  return 0;
}

// unordered_map<char,int> symbols = {{'[',-1},{'{',-2},{'(',-3},{')',3},{'}',2},{']',1},};
// string isBalanced(string s){
// 	stack<char> st;
// 	for(char bracket:s){
// 		if(symbols[bracket] < 0){
// 			st.push(bracket);
// 		}else{
// 			if(st.empty()){
// 				return "NO";
// 			}
// 			char top = st.top();
// 			st.pop();
// 			if(symbols[bracket] + symbols[top] != 0){
// 				return "NO";
// 			}
// 		}
// 	}
// 	if(!st.empty()){
// 		return "NO";
// 	}
// 	return "YES";
// }