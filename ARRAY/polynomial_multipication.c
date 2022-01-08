#include <stdio.h>
#include <stdlib.h>

struct node
{

    float coef;
    int expo;
    struct node *next;
};

struct node *create_node(struct node *);
struct node *insert_node(struct node *, float, int);
struct node *insert(struct node *, float, int);
void display(struct node *ptr);
void polymultiplication(struct node *, struct node *);
struct node *create_node(struct node *head)
{

    int i, n, ex;
    float co;

    printf("Enter the number of terms : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {

        printf("Enter coeficient for term %d : ", i);
        scanf("%f", &co);

        printf("Enter exponent for term %d : ", i);
        scanf("%d", &ex);
        head = insert_node(head, co, ex);
    }

    return head;
}

//structure - insert
struct node *insert_node(struct node *head, float co, int ex)
{

    struct node *temp1, *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coef = co;
    newnode->expo = ex;

    //list empty or exp greater than first one
    if (head == NULL || ex > head->expo)
    {

        //tmp->next = start;
        head = newnode;
    }
    else
    {

        temp1 = head;

        while (temp1->next != NULL && temp1->next->expo >= ex)
            temp1 = temp1->next;
        newnode->next = temp1->next;
        temp1->next = newnode;
    }

    return head;
}
void display(struct node *temp1)
{

    if (temp1 == NULL)
    {

        printf("Zero polynomial\n");
        return;
    }

    while (temp1 != NULL)
    {

        printf("(%.1fx^%d)", temp1->coef, temp1->expo);
        temp1 = temp1->next;

        if (temp1 != NULL)
            printf(" + ");

        else
            printf("\n");
    }
}

void polymultiplication(struct node *p1, struct node *p2)
{
    struct node *start3;
    struct node *p2_beg = p2;
    start3 = NULL;

    if (p1 == NULL || p2 == NULL)
    {
        printf("Multiplied polynomial is zero polynomial\n");
        return;
    }

    while (p1 != NULL)
    {
        p2 = p2_beg;

        while (p2 != NULL)
        {
            start3 = insert_node(start3, p1->coef * p2->coef, p1->expo + p2->expo);
            p2 = p2->next;
        }

        p1 = p1->next;
    }

    printf("Multiplied polynomial is : ");
    display(start3);
}

int main()
{

    struct node *head1 = NULL, *head2 = NULL;

    printf("Enter polynomial 1 :\n");
    head1 = create_node(head1);

    printf("Enter polynomial 2 :\n");
    head2 = create_node(head2);

    printf("Polynomial 1 is : ");
    display(head1);

    printf("Polynomial 2 is : ");
    display(head2);

    polymultiplication(head1, head2);
}

//structure - create
struct node *create_node(struct node *head)
{

    int i, n, ex;
    float co;

    printf("Enter the number of terms : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {

        printf("Enter coeficient for term %d : ", i);
        scanf("%f", &co);

        printf("Enter exponent for term %d : ", i);
        scanf("%d", &ex);
        head = insert_node(head, co, ex);
    }

    return head;
}

