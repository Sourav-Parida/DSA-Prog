// Tower of Hanoi
#include<stdio.h>
int c=0; // counter added

void TOH(int n,char BEG,char AUX,char END){
    if(n>=1){
        TOH(n-1,BEG,END,AUX);
        printf("\n%d from %c to %c",n,BEG,END);
        c++;
        TOH(n-1,AUX,BEG,END);
    }
}

int main(){
    int n;
    printf("Enter total number of rings:");
    scanf("%d",&n);
    TOH(n, 'A', 'C', 'B');
    printf("\n\nTotal no. of steps=%d",c);
    return 0;
}
