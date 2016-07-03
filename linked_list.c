#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
void insert_first();
void insert_last();
void delete_first();
void delete_last();
void insert_info();
void insert_pos();
void sort();
int count();
void display();
void insert_node();

int main()
{
    char ch;
    int choice;
    printf("MAIN MENU \n");
    printf("1.INSERT AT BEGINING \n");
    printf("2.INSERT AT LAST \n");
    printf("3.DELETE AT BEGINING \n");
    printf("4.DELETE AT LAST \n");
    printf("5.SEARCH INFO\n");
    printf("6.SEARCH POSITION \n");
    printf("7.DISPLAY \n");
    printf("8.SORT \n");
    printf("ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    while(choice<10)
    {
        switch(choice)
        {
        case 1:
            insert_first();
            break;
        case 2:
            insert_last();
            break;
        case 3:
            delete_first();
            break;
        case 4:
            delete_last();
            break;
        case 5:
            insert_info();
            break;
        case 6:
            insert_pos();
            break;
        case 7:
            display();
            break;
        case 8:
            sort();
            break;
        case 9:
            insert_node();
            break;
        }
        printf("\n ENTER YOUR CHOICE \n");
        scanf("%d",&choice);
    }

    return 0;
}

void insert_first()
{
    struct node *new1= (struct node*)malloc(sizeof(struct node));
    printf("ENTER THE DATA \n");
    scanf("%d",&(new1->data));
    if(start==NULL)
    {
        new1->next=NULL;
        start=new1;
    }
    else
    {
        new1->next=start;
        start=new1;
    }
}
void insert_last()
{
    struct node *new1= (struct node*)malloc(sizeof(struct node));
    printf("ENTER THE DATA \n");
    scanf("%d",&(new1->data));
    new1->next=NULL;
    if(start==NULL)
    {
        start=new1;
    }
    else
    {
        struct node*loc=start;
        while(loc->next!=NULL)
        {
            loc=loc->next;
        }
        loc->next=new1;
    }
}
void delete_first()
{
    struct node*loc=start;

    start=start->next;
    printf("DELETED ITEM IS %d \n",loc->data);
    free(loc);
}
void delete_last()
{
    struct node*loc=start;
    struct node *locp;
    while(loc->next!=NULL)
    {
        locp=loc;
        loc=loc->next;
    }
    printf("DELETED ITEM IS %d \n",loc->data);
    locp->next=NULL;
    free(loc);
}
void insert_info()
{
    struct node *new1= (struct node*)malloc(sizeof(struct node));
    int info;
    printf("ENTER THE INFO \n");
    scanf("%d",&info);
    struct node*loc=start;
    while(loc->data!=info)
    {
        loc=loc->next;
    }
    printf("ENTER THE DATA \n");
    scanf("%d",&(new1->data));
    new1->next=loc->next;
    loc->next=new1;
}
void insert_pos()
{
    int info,no=1;
    printf("ENTER THE INFO \n");
    scanf("%d",&info);
    if(info>count())
    {
        printf("WRONG POSITION \n");
        return;
    }
    else
    {
        struct node *new1=(struct node*)malloc(sizeof(struct node));
        struct node*loc=start;
        while(no!=info)
        {
            no++;
            loc=loc->next;
        }
        printf("ENTER THE DATA \n");
        scanf("%d",&(new1->data));
        if(info==count())
        {
            new1->next=NULL;
        }
        else
        {
            new1->next=loc->next;
        }
        loc->next=new1;

    }
}
int count()
{
    int no=0;
    struct node*loc=start;
    while(loc!=NULL)
    {
        loc=loc->next;
        no++;
    }
    return no;
}
void display()
{
    struct node*loc=start;
    while(loc!=NULL)
    {
        printf("%d  ",loc->data);
        loc=loc->next;
    }
}
void sort()
{
    struct node *temp1,*temp2,*temp3;
    int temp;
    for(temp3=start; temp3->next!=NULL; temp3=temp3->next)
    {
        temp1=start;
        temp2=start->next;
        while(temp2!=NULL)
        {
            if(temp1->data>temp2->data)
            {
                temp=temp1->data;
                temp1->data=temp2->data;
                temp2->data=temp;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    display();
}
void insert_node()
{
    struct node *new1= (struct node*)malloc(sizeof(struct node));
    printf("ENTER THE DATA \n");
    scanf("%d",&(new1->data));
    struct node *loc=start;
    struct node *locp=(start->next);
    if((loc->data)>(new1->data))
    {
        new1->next=loc;
        start=new1;
        return ;
    }
    else
    {
        while(loc->next!=NULL)
        {
            if((loc->data<=new1->data )&& (locp->data>=new1->data))
            {
                loc->next=new1;
                new1->next=locp;
                return;

            }
            loc=loc->next;
            locp=locp->next;
        }
    }
    if(loc->data<=new1->data)
    {
        new1->next=NULL;
        loc->next=new1;
    }
    display();
}

