// reverse an array without using extra array
#include<stdlib.h>
#include<stdio.h>
void main()
{
    int a,n,i,j,*p;
    printf("enter number of elements: ");
    scanf("%d", &n);
    p=(int*)malloc(n*sizeof(int));
    
    printf("enter array:");
    for(a=0;a<n;a++){
        scanf("%d",&p[a]);
    }
    
    printf("Entered array is: ");
    for(a=0;a<n;a++){
    printf("%d ",*(p+a));
    }

    i=0; j=n-1;
    while(i<j){
    int t=*(p+i);
    *(p+i)=*(p+j);
    *(p+j)=t;
    i++;
    j--;
    }
    
    printf("\nReversed array is: ");	
    for(a=0;a<n;a++)
    printf("%d ",*(p+a));
    printf("\n");
}

