#include <stdio.h>
#include <stdlib.h>

int main(){

int r , c ;
printf("Enter the row and column size of the array:");
scanf("%d %d" , &r , &c);

//Taking the array elements as input
int a[r][c];
printf("Enter the elements of the array :\n");
for (int i=0;i<r;i++){
	for(int j=0;j<c;j++){
		printf("array[%d][%d]=",i,j);
		scanf("%d" , &a[i][j]);
	}
}

//Printing the array
printf("Entered 2D array:\n");
for (int i = 0; i < r; i++) {
	for (int j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
//Counting
int  count=0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
        	if(a[i][j]==0)
        	{  continue;  }
        	else
        	{ 
        	  count++;
                }   
        }
        
    }
    
//Sparse Matrix
printf("The Sparse Matrix in 3_tuple:\n"); 
printf("%d %d %d \n", r,c,count);  
for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
        	if(a[i][j]==0)
        	{  continue;  }
        	else
        	{ printf("%d %d %d ", i,j,a[i][j]);
        	  printf("\n");
        	
                }   
        }
    

 }
 
 return 0;
 }