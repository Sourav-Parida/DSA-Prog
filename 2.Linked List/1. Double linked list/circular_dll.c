#include <stdio.h>
#include <malloc.h>

struct node{
    struct node *pre;
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);

void main()
{
    start = create_ll(start);
    printf("\n   ***link list created***   \n");
    start = display(start);
}

struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num, n;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    printf("\nEnter the data :");
    scanf("%d", &num);
    for (int i = 0; i < n; i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
        {
            start = new_node;
            start->next = start;
            start->pre = NULL;
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->pre = ptr;
            new_node->next = start;
            start->pre = new_node;
        }
        if (i < n - 1)
        {
            printf("Enter the data :");
            scanf("%d", &num);
        }
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    printf("\nThe linked list is:\n ");
    while (ptr->next != start)
    {
        printf("%d , ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d , ", ptr->data);
    printf("\n");
    return start;
}