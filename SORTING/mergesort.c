#include <stdio.h>
void MergeSort(int arr[], int lb, int ub);
void Merge(int arr[], int lb, int mid, int ub);

int main()
{
    int N;
    printf("Enter number of elements: ");
    scanf("%d", &N);
    int arr[N];
    int lb ;
    int ub;
    for (int i = 0; i < N; i++)
    {
        printf("Enter element %d: ", (i + 1));
        scanf("%d", &arr[i]);
    }
    lb=0;
    ub=N-1;
    MergeSort(arr,lb,ub);
    printf("Sorted Elements : ");
    for(int i=0;i<N;i++){
        printf("%d\n",arr[i]);
    }

    return 0;
}
void MergeSort(int arr[], int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        MergeSort(arr, lb, mid);
        MergeSort(arr, mid + 1, ub);
        Merge(arr, lb, mid, ub);
    }
}
void Merge(int arr[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[50];
    while(i <= mid && j <= ub)
    {
        if (arr[i]<=arr[j]){
            b[k]=arr[i];
            i++;
            k++;
        }
        else{
            b[k]=arr[j];
            k++;
            j++;
        }
    }
    if(i>mid){
        while(j<=ub){
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            b[k]=arr[i];
            i++;
            k++;
        }
    }
    int beg;
    beg=lb;
    while(beg<k){
        arr[beg]=b[beg];
        beg++;
    }

}