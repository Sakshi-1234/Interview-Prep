#include <stdio.h>
#include <stdlib.h>
int queue[20], visited[20], front = -1, rear = -1;
int adjmatrix[20][20];

int main()
{
    int n;
    printf("Enter number of vertces: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("Enter 1 if %d has a node with %d: ", i, j);
            scanf("%d", &adjmatrix[i][j]);
        }
    }
    printf("Adjceny mstrix is: \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf(" %d ", adjmatrix[i][j]);
        }
        printf("\n");
    }
    int s;
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    bfs(s, n);
    return 0;
}
void bfs(int s, int n)
{
    int p;
    add(s);
    visited[s] = 1;
    p = delete ();
    if (p != 0)
    {
        printf("%d ", p);
    }
    while (p != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (adjmatrix[p][i] != 0 && visited[i] != 0)
            {
                add(i);
                visited[i] = 1;
            }
        }
        p = delete ();
        if (p != 0)
        {
            printf("%d ", p);
        }
    }
    for (i = 1; i <= n; i++)
        if (visited[i] == 0)
            bfs(i, n);
}
int delete ()
{
    int k;
    if (front > rear || front == -1)
    {
        return (0)
    }
    else
    {
        k = queue[front++];
        return (k);
    }
}
void add(int s)
{
    if (rear == 19)
    {
        printf("Queue is full");
    }
    else
    {
        if (rear == -1)
        {
            queue[++rear] = s;
            front++;
        }
        else
        {
            queue[++rear] = s;
        }
    }
}

