// merging two sorded array

#include <stdio.h>
void main()
{
    int n,m;
    printf("Enter the size of first array:");
    scanf("%d",&n);    
    printf("Enter the size of the second array:");
    scanf("%d",&m);

    int a[n],b[m],c[m+n]; 

    printf("\nEnter the elements of the first array:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the elements of the second array:");
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }

    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++; k++;
        }
        else{
            c[k]=b[j];
            j++; k++;
        }
    }
    while(i<n){
        c[k]=a[i];
        k++; i++;
    }
    while(j<m){
        c[k]=b[j];
        k++; j++;
    }
    
    printf("\n\nThe merged array:=");  
    for(int p=0;p<(m+n);p++){
    printf("%d ",c[p]);
    }
}
