#include <stdio.h>
int N = 8;
int stack[8];
int top = -1;
void push(int x)
{
    if (top == N - 1)
    {
        printf("stack is overflow ");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop(int x)
{
    if (top == -1)
    {
        printf("stack is underflow");
    }
    else
    {
        top--;
    }
}
void display()
{
    int i;
    for (i = 0; i < N - 1; i++)
    {
        printf("%d", stack[i]);
    }
}
void peek()
{
    if (top == -1)
    {
        printf("empty stack");
    }
    else
    {
        printf("%d", stack[top]);
    }
}

int main()
{
    push(3);
    push(5);
    push(9);
    push(1);
    push(12);
    push(15);
    printf("Elements present in stack are %d \n");
    display();

    return 0;
}
#include <stdio.h>
int N = 8;
int stack[8];
int top = -1;
void push(int x)
{
    if (top == N - 1)
    {
        printf("stack is overflow ");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("stack is underflow");
    }
    else
    {
        top--;
        printf("Element poped out is %d \n", stack[top + 1]);
    }
}
void display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%d \n", stack[i]);
    }
}
void peek()
{
    if (top == -1)
    {
        printf("empty stack");
    }
    else
    {
        printf("%d", stack[top]);
    }
}

int main()
{
    int n;
    int a, b, c, d;
    printf("Stack operation using array \n");
    printf("Enter choice 1 for PUSH,2 for POP,3 for DISPLAY \n");
    d = 1;
    while (1)
    {
        printf("Enter the choice : \n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter element to be entered: \n");
            scanf("%d", &a);
            push(a);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Elements of stack are:");
            display();
            break;
        default:
            printf("invalid choice");
        }
    }

    return 0;
}
