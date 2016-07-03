#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void insert();
void dequeue();
void display();

int main()
{
    char ch;
    int choice;
    printf("MAIN MENU \n");
    printf("1.INSERT \n");
    printf("2.DELETE \n");
    printf("3.DISPLAY \n");
    printf("ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    while(choice<4)
    {
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        }
        printf("\n ENTER YOUR CHOICE \n");
        scanf("%d",&choice);
    }
    return 0;
}

void insert()
{
    struct node *new1= (struct node*)malloc(sizeof(struct node));
    printf("ENTER THE DATA \n");
    scanf("%d",&(new1->data));
    new1->next=NULL;
    if(front==NULL)
    {
        front=new1;
        rear=new1;
    }
    else
    {
        rear->next=new1;
        rear=new1;
    }
}
void dequeue()
{
    if(front==NULL)
    {
        printf("UNDERFLOW \n");
        return ;
    }
    printf("DELETED DATA IS %d",front->data);
     if(front->next==NULL)
    {
        free(front);
        front=rear=NULL;
    }
    else
    {
        struct node*temp=front;
        front=front->next;
        free(temp);
    }
}


void display()
{
    struct node*loc=front;
    while(loc!=NULL)
    {
        printf("%d  ",loc->data);
        loc=loc->next;
    }
}





