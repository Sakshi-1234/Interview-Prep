#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int Rear = -1;
int Front = -1;
int isFull();
int isEmpty();
void enqueue(int x);
void dequeue();
void display();
void peek();
int isFull()
{
    if ((Front == Rear + 1) || (Front == 0 && Rear == SIZE - 1))
        return 1;
    return 0;
}
int isEmpty()
{
    if (Front == -1)
        return 1;
    return 0;
}

void enqueue(int x)
{
    if (Rear == SIZE - 1)
    {
        printf("Overflow \n");
    }
    else if (isFull())
    {
        printf("\n Queue is full!! \n");
    }
    else if (Front == -1 && Rear == -1)
    {
        Front = 0;
        Rear = 0;
        queue[Rear] = x;
    }
    else
    {
        Rear++;
        queue[Rear] = x;
        int i, j;
        int temp;

        for (i = Front; i < Rear; i++)
        {
            for (j = Front; j < Rear; j++)
            {
                if (queue[j] < queue[j + 1])
                {
                    temp = queue[j+1];
                    queue[j+1] = queue[j];
                    queue[j] = temp;
                }
            }
        }
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("\n Queue is empty !! \n");
        return (-1);
    }
    else if (Front == -1 && Rear == -1)
    {
        printf("Underflow \n");
    }
    else if (Front == Rear)
    {
        Front = -1;
        Rear = -1;
    }
    else
    {
        Front++;
        printf("Removed Element from Queue is %d \n", queue[Front - 1]);
    }
}

void display()
{

    if (Front == -1 && Rear == -1)
    {
        printf("Empty Queue \n");
    }
    else
    {
        printf("Elements of Queue are: \n");
        for (int i = Front; i <= Rear; i++)
        {
            printf("%d ", queue[i]);
            printf("\n");
        }
    }
}
void peek()
{
    if (Front == -1 && Rear == -1)
    {
        printf("Priority Queue is empty \n");
    }
    else
    {
        printf("Element with highest priority is %d", queue[Front]);
    }
}
int main()
{
    int n;
    int a;
    printf("1.Enqueue Operation\n");
    printf("2.Dequeue Operation\n");
    printf("3.Display the Queue\n");
    n = 1;
    while (n <= 3)
    {
        printf("Enter your choice of operations : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter element to be inserted \n");
            scanf("%d", &a);
            enqueue(a);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        default:
            printf("Incorrect choice \n");
        }
    }
    return 0;
}
