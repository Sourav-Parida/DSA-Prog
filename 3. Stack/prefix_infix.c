#include <stdio.h>
#include <stdlib.h>

struct node {
  char data;
  struct node *next;
};

struct stack {
  struct node *top;
};

void push(struct stack *s, char c) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = c;
  temp->next = s->top;
  s->top = temp;
}

char pop(struct stack *s) {
  if (s->top == NULL) {
    return -1;
  }
  char c = s->top->data;
  s->top = s->top->next;
  free(s->top);
  return c;
}

int isoperand(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isoperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void printInfix(struct stack *s) {
  char c;
  while ((c = pop(s)) != -1) {
    if (isoperand(c)) {
      printf("%c", c);
    } else {
      printf(" %c ", c);
    }
  }
  printf("\n");
}

void main() {
  struct stack s;
  s.top = NULL;
  char prefix[100];
  printf("Enter the prefix expression: ");
  scanf("%s", prefix);
  int i;
  for (i = 0; prefix[i] != '\0'; i++) {
    if (isoperand(prefix[i])) {
      push(&s, prefix[i]);
    } else {
      char operator = prefix[i];
      char operand1 = pop(&s);
      char operand2 = pop(&s);
      push(&s, operator);
      push(&s, operand1);
      push(&s, operand2);
    }
  }
  printInfix(&s);
}