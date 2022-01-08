#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef,expo;
    struct node* next;
};

struct node* insertpoly(struct node* head_1_2,int c,int e);
struct node* append(struct node* head_1_2,int c,int e);
struct node* polyaddition(struct node* thead_1,struct node* thead_2);
void display(struct node* thead);
struct node* append(struct node* head_1_2,int c,int e)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    if(head_1_2==NULL){// Corner Case to handle if the list is empty...
    newnode->next=NULL;
    return newnode;
    }
    struct node* temp1=head_1_2;
    while(temp1->next!=NULL) // Traversing to point to the last node...
        temp1=temp1->next;
    temp1->next=newnode;
    newnode->next=NULL;
    return head_1_2;
}

struct node* insertpoly(struct node* head_1_2,int c,int e)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    if(head_1_2==NULL){            // for inserting the first node..
        newnode->next=NULL;
        return newnode;
    }
    struct node* prev,* curr;
    prev=curr=head_1_2;
    while(curr!=NULL && curr->expo>e){
        prev=curr;
        curr=curr->next;
    }
    if(curr==head_1_2){            // for inserting before the first node...
        newnode->next=curr;
        return newnode;
    }
    else if(curr==NULL){        //for inserting after the last node....
        prev->next=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=curr;
        prev->next=newnode;
    }
    return head_1_2;
}

struct node* polyaddition(struct node* thead_1,struct node* thead_2)
{
    struct node* add=NULL;
    struct node* h1,* h2;
    h1=thead_1;
    h2=thead_2;
    while(h1!=NULL && h2!=NULL){
        if(h1->expo > h2->expo){
            add=append(add,h1->coef,h1->expo);
            h1=h1->next;
        }
        else if(h1->expo < h2->expo){
            add=append(add,h2->coef,h2->expo);
            h2=h2->next;
        }
        else{
            add=append(add,(h1->coef)+(h2->coef),h1->expo);
            h1=h1->next;
            h2=h2->next;
        }
    }

    while(h1!=NULL){            //coping the remaining terms of polynomial 1...
        add=append(add,h1->coef,h1->expo);
        h1=h1->next;
    }

    while(h2!=NULL){            //coping the remaining terms of polynomial 2...
        add=append(add,h2->coef,h2->expo);
        h2=h2->next;
    }
    return add;
}

void display(struct node* thead)
{
    struct node* temp=thead;
    if(temp==NULL){
        printf("\nEmpty..");
    }
    else{
        while(temp->next!=NULL){
            printf(" %dx^%d +",temp->coef,temp->expo);
            temp=temp->next;
        }
       printf(" %dx^%d ",temp->coef,temp->expo);
    }
}



int main()
{
    int a,b,n,i;
    struct node* head1,* head2,* head3;
    head1=head2=NULL;

    // Inputing the first polynomial..

    printf("Enter the no of terms of polynomial 1..");
    scanf("%d",&n);
    printf("\nEnter the polynomial..");
    for(i=0;i<n;i++){
        printf("\nEnter the coefficient and exponent of the term..");
        scanf("%d%d",&a,&b);
        head1=insertpoly(head1,a,b);
    }

    // Inputing the second polynomial..

    printf("\nEnter the no of terms of polynomial 2..");
    scanf("%d",&n);
    printf("\nEnter the polynomial..");
    for(i=0;i<n;i++){
        printf("\nEnter the coefficient and exponent of the term..");
        scanf("%d%d",&a,&b);
        head2=insertpoly(head2,a,b);
    }

    //Performing Addition..

    head3=polyaddition(head1,head2);

    //Displaying the polynomial..

    printf("\nThe polynomial 1 is..");
    display(head1);
    printf("\nThe polynomial 2 is..");
    display(head2);
    printf("\nThe sum of the two polynomials is..");
    display(head3);
}

