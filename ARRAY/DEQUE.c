#include <stdio.h>
#include <stdlib.h>
#define N 20
int Deque[20];
int front = -1;
int rear = -1;
void insert_front(int x);
void insert_rear(int x);
void delete_front();
void delete_rear();
void get_front();
void grt_rear();
void display();
int isFull();
int isEmpty();
int isFull()
{
    if ((front == 0 && rear == N - 1) || (front == rear + 1))
    {
        printf("\n Queue is full\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if ((front == -1 && rear == -1))
    {
        printf("\n Queue is emty\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
void insert_front(int x)
{
    if (isFull())
    {
        printf("\noverflow condition\n");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        Deque[front] = x;
    }
    else if (front == 0)
    {
        front = N - 1;
        Deque[front] = x;
    }
    else
    {
        front--;
        Deque[front] = x;
    }
}
void insert_rear(int x)
{
    if (isFull())
    {
        printf("\n Queue is overflow\n");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        Deque[rear] = x;
    }
    else if (rear = N - 1)
    {
        rear = 0;
        Deque[rear] = x;
    }
    else
    {
        rear++;
        Deque[rear] = x;
    }
}
void delete_front()
{
    if (isEmpty())
    {
        printf(" \nQueue underflow\n");
        exit(1);
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == N - 1)
    {
        printf("Removed Element is %d \n", Deque[front]);
        front = 0;
    }
    else
    {
        printf("Removed Element is %d \n", Deque[front]);
        front++;
    }
}
void delete_rear()
{
    if (isEmpty())
    {
        printf("\n Queue underflow \n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        printf("Removed Element is %d \n ", Deque[rear]);
        rear = N - 1;
    }
    else
    {
        printf("Removed Element is %d\n ", Deque[rear]);
        rear--;
    }
}
void get_front()
{
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        exit(1);
    }
    else
    {
        printf("Front element is %d \n", Deque[front]);
    }
}
void get_rear()
{
    if (isEmpty())
    {
        printf("\nQueue is empty \n");
    }
    else
    {
        printf("Rear element is %d : ", Deque[rear]);
    }
}
void display()
{
    int i = front;
    while (i != rear)
    {
        printf("%d \n", Deque[i]);
        i = (i + 1) % N;
    }
    printf("%d \n", Deque[rear]);
}

int main()
{
    int n;
    int a;
    printf("1.Insert at the front end\n");
    printf("2.Insert at the rear end\n");
    printf("3.Delete from front end\n");
    printf("4.Delete from rear end\n");
    printf("5.Display\n");
    printf("6.Get the front element\n");
    printf("7.Get the rear element \n");
    printf("8.Quit\n");
    while (1)
    {
        printf("Enter your choice of operations : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter element to be inserted \n");
            scanf("%d", &a);
            insert_front(a);
            break;
        case 2:
            printf("Enter element to be inserted \n");
            scanf("%d", &a);
            insert_rear(a);
            break;
        case 3:
            delete_front();
            break;
        case 4:
            delete_rear();
        case 5:
            display();
            break;
        case 6:
            get_front();
            break;
        case 7:
            get_rear();
            break;
        case 8:
            exit(1);
        default:
            printf("Incorrect choice \n");
        }
    }

    return 0;
}