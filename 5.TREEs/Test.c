#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>


struct node{
    int Emp_Id;
    char emp_name[20];
    int Emp_Salary;
    struct node *left;
    struct node *right;
};

struct node *tree;
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);

void main(){
    int option, val;
    struct node *ptr;
    tree = NULL;

        printf("\n ******MAIN MENU******* \n");
        printf("\n 1. Insert Element");
        printf("\n 2. Preorder Traversal");
        printf("\n 3. Inorder Traversal");
        printf("\n 4. Postorder Traversal");
        printf("\n 5. Exit");
    do
    {
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n Enter the Emp_Id of the new node : ");
            scanf("%d", &val);
            tree = insertElement(tree, val);
            break;
        case 2:
            printf("\n The elements in preorder : \n");
            preorderTraversal(tree);
            printf("\n");
            break;
        case 3:
            printf("\n The elements in inorder : \n");
            inorderTraversal(tree);
            printf("\n");
            break;
        case 4:
            printf("\n The elements in postorder : \n");
            postorderTraversal(tree);
            printf("\n");
            break;
        }
    } while (option <= 5);
    getch();
}

struct node *insertElement(struct node *tree, int val)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->Emp_Id = val;
    printf("Enter Name:");
    scanf("%s",&ptr -> emp_name);
    printf("Enter Salary:");
    scanf("%d",& ptr -> Emp_Salary);
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL){
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else{
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->Emp_Id)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        if (val < parentptr->Emp_Id)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return tree;
}

void preorderTraversal(struct node *tree){
    if (tree != NULL){
        printf("%d\t", tree -> data);
        preorderTraversal(tree -> left);
        preorderTraversal(tree -> right);
    }
}
void inorderTraversal(struct node *tree){
    if (tree != NULL){
        inorderTraversal(tree->left);
        printf("%d\t", tree->data);
        inorderTraversal(tree->right);
    }
}
void postorderTraversal(struct node *tree){
    if (tree != NULL)
    {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d\t", tree->data);
    }
}