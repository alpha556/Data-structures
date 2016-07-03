#include<stdio.h>
#define max 3
int queue[max],front=-1,rear=-1;
void insert();
void Delete();
void display();
int main()

{   int choice;
    printf("MAIN MENU \n");
    printf("1.INSERT \n");
    printf("2.DELETE \n");
    printf("3.DISPLAY \n");
    printf("4.EXIT \n");
    printf("ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    while(choice<4)
    {
        switch(choice)
        {
            case 1:insert();
                    break;
            case 2:Delete();
                    break;
            case 3:display();
                    break;
            case 4:break;

        }
        printf("ENTER YOUR CHOICE \n");
        scanf("%d",&choice);
    }
    return 0;
}
void insert()
{   int item;
    if((front==0&&rear==max-1)||front==rear+1)
    {
        printf("OVERFLOW \n");
        return 0;
    }
    else if(front==-1)
        front=rear=0;
    else if(rear==max-1)
        rear=0;
    else
        rear=rear+1;
    printf("ENTER THE ELEMENT \n");
    scanf("%d",&item);
    queue[rear]=item;
}
void Delete()
{
    int item;
    if(front==-1)
    {
        printf("UNDERFLOW \n");
        return;
    }
    item=queue[front];
    printf("DELETED ITEM IS %d \n",item);
     if(front==rear)
        front=rear=-1;
    else if(front==max-1)
        front=0;

    else
        front=front+1;
}
void display()
{
    int i;
    if(front==-1&&rear==-1)
    {
        printf("Empty \n");
        return;
    }
   if(front<=rear)
   {
        for(i=front;i<=rear;++i)
        printf("%d  ",queue[i]);
        printf("\n");
   }
   else
   {
    for(i=front;i<max;++i)
        printf("%d  ",queue[i]);
    for(i=0;i<=rear;++i)
        printf("%d  ",queue[i]);
   }


}

