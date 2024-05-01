#include <stdio.h>
#include <string.h>

#define MAX 100

int stk[MAX];
int top = -1;

char pop() {
    return (top == -1) ? '\0' : stk[top--];
}

void push(char c) {
    if (top < MAX - 1)
        stk[++top] = c;
    else
        printf("\nStack overflow");
}

int isValidExpression(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (strchr("({[", exp[i]) != NULL)
            push(exp[i]);
        else if (strchr(")}]", exp[i]) != NULL) {
            char temp = pop();
            if (temp == '\0' || (exp[i] - temp) > 2)
                return 0;
        }
    }
    return (top == -1) ? 1 : 0;
}

int main() {
    char exp[MAX];
    printf("\nEnter an expression: ");
    fgets(exp, MAX, stdin);

    if (isValidExpression(exp))
        printf("Valid expression\n");
    else
        printf("Invalid expression\n");

    return 0;
}
