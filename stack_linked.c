#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;
void push();
void pop();
void display();

int main()
{
    char ch;
    int choice;
    printf("MAIN MENU \n");
    printf("1.PUSH \n");
    printf("2.POP \n");
    printf("3.DISPLAY \n");
    printf("ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    while(choice<4)
    {
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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

void push()
{
    struct node *new1= (struct node*)malloc(sizeof(struct node));
    printf("ENTER THE DATA \n");
    scanf("%d",&(new1->data));
    if(top==NULL)
    {
        top=new1;
        top->next=NULL;
    }
    else
    {
        new1->next=top;
        top=new1;
    }

}
void pop()
{
    if(top==NULL)
    {
        printf("UNDERFLOW \n");
        return ;
    }
    else if(top->next==NULL)
    {
         printf("DELETED DATA IS %d",top->data);
         free(top);
         top=NULL;
    }
    else
    {   struct node *temp=top;
        printf("DELETED DATA IS %d",temp->data);
        top=top->next;
        free(temp);
    }
}


void display()
{
    struct node*loc=top;
    while(loc!=NULL)
    {
        printf("%d  ",loc->data);
        loc=loc->next;
    }
}




