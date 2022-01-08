#include <stdio.h>
void Quick_Sort(int arr[], int lb, int ub);
int partition(int arr[], int lb, int ub);
void Quick_Sort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc;
        loc = partition(arr, lb, ub);
        Quick_Sort(arr, lb, loc - 1);
        Quick_Sort(arr, loc + 1, ub);
    }
}
int partition(int arr[], int lb, int ub)
{
    int pivot, start, end, temp;
    pivot = arr[lb];
    start = lb;
    end = ub;
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end++;
        }
        if (start < end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    return end;
}
int main()
{
    int N;
    printf("Enter number of elements: ");
    scanf("%d", &N);
    int arr[N];
    int lb, ub;
    for (int i = 0; i < N; i++)
    {
        printf("Enter element %d: ", (i + 1));
        scanf("%d", &arr[i]);
    }
    lb = 0;
    ub = N - 1;
    Quick_Sort(arr, lb, ub);
    printf("Sorted Elements are: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}