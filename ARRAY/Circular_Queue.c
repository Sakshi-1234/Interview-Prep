#include<stdio.h>
#define N 5
int CQueue[N];
int front=-1;
int rear=-1;
void enqueue(int x);
void dequeue();
void display();
void enqueue(int x){
    if (front==-1 && rear==-1){
        front=0;
        rear=0;
        CQueue[rear]=x;
    }
    else if((rear+1)%N==front){
        printf("CQueue is full");
    }
    else{
        rear=(rear+1)%N;
        CQueue[rear]=x;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        printf("CQueue underflow");
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%N;
        printf("dequed element is %d \n",CQueue[front-1]);
    }
}
void display(){
    int i=front;
    if(front==-1 && rear==-1){
        printf("CQueue is empty");
    }
    else{
        printf("Elements in CQueue is :");
        while(i!=rear){
            printf("%d \n",CQueue[i]);
            i=(i+1)%N;
        }
        printf("%d \n",CQueue[rear]);
    }
}

int main(){
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
        scanf("%d",&a);
        enqueue(a);
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        default:
        printf("Incorrect choice \n");
        }
    }
}

