#include<stdio.h>
#include<stdlib.h>



int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int* multiplication(int arr1[],int arr2[],int n1,int n2){
    int size = n1 + n2 -1;
    int* ans = (int*)calloc(size,sizeof(int));

    for(int i = 0;i<n1;i++){
        for(int j = 0;j<n2;j++){
            ans[i+j]  += arr1[i] * arr2[j];
        }
    }
    return ans;
}

int* add (int arr1[],int arr2[],int n1,int n2){
    int size = max(n1,n2);
    int* ans = (int*)calloc(size,sizeof(int));
    int i = 0, j = 0;

    while(i<n1){
        ans[i] = arr1[i];
        i++;
    }
    while(j<n2){
        ans[j] = ans[j] + arr2[j];
        j++;
    }
    return ans;
}

void print(int arr[],int size){
    for(int i = size-1;i>=0;i--){
        printf("%dx^%d ",arr[i],i);
        if(i != 0)
            printf("+");
    }
    printf("\n");
}


int main(){
    int n2,n1;
    printf("Enter the order of the polynomial 1: ");
    scanf("%d",&n1);
    n1++;
    int arr1[n1];

    printf("Enter the coefficients in the polynomial 1:\n");

    for(int i = n1-1;i>=0;i--){
        printf("Enter the coefficient of x^%d ",i);
        scanf("%d",&arr1[i]);
    }

    printf("Enter the order of the polynomial 2: ");
    scanf("%d",&n2);
    n2++;
    int arr2[n2];

    printf("Enter the coefficients in the polynomial 2:\n");

    for(int i = n2-1;i>=0;i--){
        printf("Enter the coefficient of x^%d ",i);
        scanf("%d",&arr2[i]);
    }



    int* arr_add;
    arr_add = add(arr1,arr2,n1,n2);
    print(arr_add,max(n1,n2));

    int* arr_mul;
    arr_mul = multiplication(arr1,arr2,n1,n2);
    print(arr_mul,n1+n2-1);
    return 0;
}