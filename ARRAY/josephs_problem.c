#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

void create();
void display();
int josephs_problem(int);

int main()
{
int survive,sk;
create();
display();   
printf("Enter the number of persons to be skipped\n");
scanf("%d",&sk);
survive=josephs_problem(sk);
printf("The person to survive is : %d \n",survive);
free(head);
}

void create()
{
    struct node *temp,*tail;
    int n,ch;
    do
    {
        printf("Enter a number : ");
        scanf("%d",&n);
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=n;
        temp->next=NULL;
       
        if(head==NULL)
        {
            head=temp;
            temp->next=head;
        }
        else
        {
            tail=head;
            while(tail->next!=head)
            {
                tail=tail->next;
            }
            tail->next=temp;
            temp->next=head;
        }
       
        printf("Do you want to add a number [1/0]?");
        scanf("%d",&ch);
    }
    while(ch!=0);
}

void display()
{
    struct node *temp;
    temp=head;
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=head);
    printf("\n");
}


int josephs_problem(int k)
{
    struct node *temp1,*temp2;
    int i;
    temp1=temp2=head;
    while(temp1->next!=temp1)
    {
        for(i=0;i<k-1;i++)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=temp1->next;
        printf("%d has been killed \n",temp1->data);
        free(temp1);
        temp1=temp2->next;
    }
    head=temp1;
    return (temp1->data);
}