#include <stdio.h>
int N = 10;
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
        printf("%d ",top);
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
int main()
{
    int n, i, j, temp;
    int arr[64];
    int odd[n];
    int odd1 = 0;
    int even[n];
    int even1 = 0;
    int stack[10];
    int winner;
    int X;
    printf("Enter number of customers\n");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Enter bill number: ");
        scanf("%d", &arr[i]);
    }
    for (i = 1; i <= n - 1; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
    printf("Sorted list in ascending order:\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int k = 0; k < n; k++)
    {
        if (arr[k] % 2 == 0)
        {
            even[even1] == arr[k];
            even1++;
        }
        else
        {
            odd[odd1] == arr[k];
            odd1++;
        }
    }
    printf("ODD QUEUE IS: ")
    for (int k = 0; k < even1; k++)
    {
        printf("%d ", even[k]);
    }
        printf("EVEN QUEUE IS: ");
    for (int k = 0; k < odd1; k++)
    {
        printf("%d ", odd[k]);
    }
    int min = odd1;
    if (even1 < odd1)
    {
        min = even1;
    }
    int z = 0;
    for (int i = 1; i <= min; i++)
    {
        if (i % 2 != 0)
        {
            push(odd[z]);
            z++;
        }
        else
        {
            push(even[z]);
            z++;
            push(even[z]);
            z++;
        }
    }
    for(int k=0;k<z;k++)
    {
        display();
    }
    X=9%top;
    for(int i=1;i<=X;i++)
    {
        if(i!=X)
        {
            printf("Pop is: ");
            pop(stack[top]);
        }
        else
        {
            printf("%d is winner",stack[top]);
        }
    }
    return 0;
}