#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int stk[10];
int top =-1;
int pop();
void push(int);

int pop();
void push(int val);

int main(){
    char prefix[10];
    int len, val, i, opr1, opr2, res;
    printf("\n Enter the prefix expression : ");
    gets(prefix);
    len = strlen(prefix);
    for (i = len-1; i >= 0; i--){
        if(isdigit(prefix[i])){
            val = prefix[i] - '0';
            push(val);
        
        }
        else{
            opr1 = pop();
            printf("%c",opr1);
            opr2 = pop();
            printf("%c",opr1);
            switch (prefix[i])
            {
            case '+':
                res = opr1 + opr2;
                break;
            case '-':
                res = opr1 - opr2;
                break;
            case '*':
                res = opr1 * opr2;
                break;
            case '/':
                res = opr1 / opr2;
                break;
            }
            push(res);
        }
    }
    printf("\n RESULT = %d", stk[0]);
    return 0;
}


void push(int val){
    stk[++top] = val;
}

int pop(){
return (stk[top--]);
}
