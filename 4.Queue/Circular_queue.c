
// Write a program to implement a circular queue

#include <stdio.h>

#define MAX 4
int queue[MAX];
int front = -1;
int rear = -1;

void insert(int);
void delete(void);
int peek(void);
void display(void);

void main()
{
    int val, option, x;

    do
    {
        printf("\n****MAIN MENU****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. PEEK");
        printf("\n 4. Display the queue");
        printf("\n 5. EXIT");
        printf("\n Enter your option");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the element which is to be inserted");
            scanf("%d", &x);
            insert(x);
            break;
        case 2:
            delete ();
            break;
        case 3:
            val = peek();
            if (val != -1)
                printf("\n The first value in queue is : %d", val);
            break;

        case 4:

            display();
            break;
        }

    } while (option != 5);
}

void insert(int element)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else if ((rear + 1) % MAX == front)
    {
        printf("Queue is overflow..");
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = element;
    }
}

void delete()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is underflow..");
    }
    else if (front == rear)
    {
        printf("\nThe dequeued element is %d", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\nThe dequeued element is %d", queue[front]);
        front = (front + 1) % MAX;
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty..");
    }
    else
    {
        printf("\nElements in a Queue are :");
        while (i <= rear)
        {
            printf("%d,", queue[i]);
            i = (i + 1) % MAX;
        }
    }
}

int peek()
{

    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty");
        return -1;
    }

    else

        return (queue[front]);
}