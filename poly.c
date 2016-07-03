#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int exp;
    struct node *next;
};
struct node *start1=NULL;
struct node *start2=NULL;
struct node * insert(struct node*,int ,int);
void display(struct node*);
void sum(struct node*,struct node*);

int main()
{
    char ch;
    int x,y;
    printf("ENTER 1st POLYNOMIAL \n");
    do
    {
        printf("ENTER THE DATA \n");
        scanf("%d",&x);
        printf("ENTER THE EXP \n");
        scanf("%d",&y);
        start1=insert(start1,x,y);
        printf("DO YOU WANT TO ADD MORE:(y/n) \n");
        ch=getch();
    }
    while(ch=='y');
    printf("ENTER 2nd POLYNOMIAL \n");
    do
    {
        printf("ENTER THE DATA \n");
        scanf("%d",&x);
        printf("ENTER THE EXP \n");
        scanf("%d",&y);
        start2=insert(start2,x,y);
        printf("DO YOU WANT TO ADD MORE:(y/n) \n");
        ch=getch();
    }
    while(ch=='y');
    display(start1);
    display(start2);
    sum(start1,start2);

    return 0;
}


struct node* insert(struct node* p,int r,int c)
{
     if(p==NULL)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->data=r;
        p->exp=c;
        p->next=NULL;
    }
    else
    {
        struct node *temp=p;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=(struct node*)malloc(sizeof(struct node));
        temp=temp->next;
        temp->data=r;
        temp->exp=c;
        temp->next=NULL;
    }
    return p;
}
void sum(struct node *temp1,struct node *temp2)
{   struct node*r=NULL;
    while(temp1!=NULL&&temp2!=NULL)
    {
        if(temp1->exp==temp2->exp)
        {

            r=insert(r,temp1->data+temp2->data,temp1->exp);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if((temp1->exp)<(temp2->exp))
        {
            r=insert(r,temp1->data,temp1->exp);
            temp1=temp1->next;


        }
        else if((temp1->exp)>(temp2->exp))
        {
            r=insert(r,temp2->data,temp2->exp);
            temp2=temp2->next;
        }
    }
   while(temp1!=NULL)
    {
        r=insert(r,temp1->data,temp1->exp);
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {

        r=insert(r,temp2->data,temp2->exp);
        temp2=temp2->next;
    }
    display(r);
}


void display(struct node *temp)
{
    struct node *loc=temp;
    while(loc!=NULL)
    {
        printf("%dx^%d ",loc->data,loc->exp);
        loc=loc->next;
    }
    printf("\n");
}

