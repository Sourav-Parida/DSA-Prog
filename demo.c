// Given an array of integers, find the number of sub array having
// sum exactly equal to a given number x in O(n) time complexity.

#include <stdio.h>


void main(){
    int n=10,k,sum=0,right=0,left=0,count=0;
    printf("Enter a number:");
    scanf("%d", &k);
    int a[10] = {2, 3, 4, 5, 6, 7, 8, 9, 11, 1};

int s=0, ctr=0;                                                                                                                                       for(int i=0,c=0;i<n,c<n;)
    for(int i=0,c=0;i<n,c<n;){
        s=s+a[i];
        if(s==k)
        {
            ctr++;
            c++;
            i=c;
            s=0;
        }
        else if(s>k)
        {
            c++;
            i=c;
            s=0;
        }
        else
        {
            i++;
        }
        if(i>=n)
            break;
    }
    printf("Total arr: %d",ctr);
}