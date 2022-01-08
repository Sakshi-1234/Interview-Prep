
#include<stdio.h>
#include<stdlib.h>
struct node{
    float coef;
    int pow;
    struct node*next;   
};
void create_node(float x,int y,struct node*temp);
void store_quotient(float mul_c,int diff,struct node*quo);
void formNewPoly(int diff,float mul_c,struct node*poly);
void copyList(struct node*r,struct node*copy);
void polySub(struct node*poly1,struct node*poly2,struct node*poly);
void show(struct node* Node);
void create_node(float x,int y,struct node*temp){
    struct node*r,*z;
    z=temp;
    if(z==0){
        r=(struct node*)malloc(sizeof(struct node));
        r->coef=x;
        r->pow=y;
        r=temp;
        r->next=(struct node*)malloc(sizeof(struct node));
        r=r->next;
        r->next=0;
    }
    else{
        r->coef=x;
        r->pow=y;
        r->next=(struct node*)malloc(sizeof(struct node));
        r=r->next;
        r->next=0;
    }
}
void store_quotient(float mul_c,int diff,struct node*quo){
    while(quo->next!=0){
        quo=quo->next;
    }
    quo->pow=diff;
    quo->coef=mul_c;
    quo->next=(struct node*)malloc(sizeof(struct node));
    quo=quo->next;
    quo->next=0;
}
void formNewPoly(int diff,float mul_c,struct node*poly){
    while(poly->next!=0){
        poly->pow +=diff;
        poly->coef*=mul_c;
        poly=poly->next;
    }
}
void copyList(struct node*r,struct node*copy){
    while(r!=0){
        struct node*z=(struct node*)malloc(sizeof(struct node));
        z->coef=r->coef;
        z->pow=r->pow;
        z->next=0;
        struct node*dis=copy;
        if(dis==0){
            copy=z;
        }
        else{
            while(dis->next!=0){
                dis=dis->next;
            }
            dis->next=z;
        }
        r=r->next;
    }
}
void polySub(struct node*poly1,struct node*poly2,struct node*poly){
    while(poly1->next && poly2->next){
        if(poly1->pow > poly2->pow){
            poly->pow=poly1->pow;
            poly->coef=poly1->coef;
            poly1=poly1->next;
            poly->next=(struct node*)malloc(sizeof(struct node));
            poly=poly->next;
            poly->next=0;
        }
        else if(poly1->pow < poly2->pow){
            poly->pow=poly2->pow;
            poly->coef=-1*poly2->coef;
            poly2=poly2->next;
            poly->next=(struct node*)malloc(sizeof(struct node));
            poly=poly->next;
            poly->next=0;
        }
        else{
            if((poly1->coef-poly2->coef)!=0){
                poly->pow=poly1->pow;
                poly->coef=(poly1->coef-poly2->coef);
                poly->next=(struct node*)malloc(sizeof(struct node));
                poly=poly->next;
                poly->next=0;
            }
            poly1=poly1->next;
            poly2=poly2->next;
        }
    }
    while(poly1->next || poly2->next){
        if(poly1->next){
            poly->pow=poly1->pow;
            poly->coef=poly1->coef;
            poly1=poly1->next;
        }
        if(poly2->next){
            poly->pow=poly2->pow;
            poly->coef=-1*poly2->coef;
            poly2=poly2->next;
        }
        poly->next=(struct node*)malloc(sizeof(struct node));
        poly=poly->next;
        poly->next=0;
    }
}
void show(struct node* Node){
    int count=0;
    while(Node->next!=0 && Node->coef!=0){
        if(count==0){
            printf("%d",Node->coef);

        }
        else{
            printf("%d",abs(Node->coef));
        }
        count++;
        if(Node->pow!=0){
            printf("x^%d",Node->pow);
            Node=Node->next;
        }
        if(Node->next!=0){
            if(Node->coef>0){
                printf("+");
            }
            else{
                printf("-");
            }
        }
    }
    printf("\n");
}
void divide_poly(struct node*poly1,struct node*poly2){
    struct node*rem=0;
    struct node*quo=0;
    quo=(struct node*)malloc(sizeof(struct node));
    quo->next=0;
    struct node*q=0;
    struct node*r=0;
    copyList(poly1,q);
    copyList(poly2,r);
    while(q!=0 && (q->pow >= poly2->pow)){
        int diff=q->pow-poly2->pow;
        float mul_c=(q->coef / poly2->coef);
        store_quotient(mul_c,diff,quo);
        struct node*q2=0;
        copyList(r,q2);
        formNewPoly(diff,mul_c,q2);
        struct node*store=0;
        store=(struct node*)malloc(sizeof(struct node));
        polySub(q,q2,store);
        q=store;
        free(q2);
    }
    printf("Quotient: ");
    show(quo);
    printf("Remainder: ");
    rem=q;
    show(rem);
}



int main (){
    struct node*poly1=0;
    struct node*poly2=0;
    struct node*poly=0;
    create_node(5.0,2,poly1);
    create_node(4.0,1,poly1);
    create_node(2.0,0,poly1);
    create_node(5.0,1,poly2);
    create_node(5.0,0,poly2);
    divide_poly(poly1,poly2);
    return 0;
}