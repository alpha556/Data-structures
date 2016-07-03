#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
struct node *getnode();
void insert(struct node *,struct node *);
void  create();
void display();

int main()
{
    char ch;

    int choice;
    printf("MAIN MENU \n");
    printf("1.INSERT  \n");
    printf("2.DISPLAY \n");
    printf("ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    while(choice<3)
    {
        switch(choice)
        {
        case 1:
            create();
            break;
        case 2:
            printf("THE TREE IS \n");
            display(root);
            break;
        }
        printf("\n ENTER YOUR CHOICE \n");
        scanf("%d",&choice);
    }

    return 0;
}
struct node *getnode()
{
    struct node *new1= (struct node*)malloc(sizeof(struct node));
    new1->left=NULL;
    new1->right=NULL;
    return new1;
}
void  create()
{
    struct node *new1=getnode();
    printf("ENTER THE DATA \n");
    scanf("%d",&(new1->data));
    if(root==NULL)
    {
        root=new1;
    }
    else
    {
        insert(root,new1);
    }
}
void insert(struct node *root,struct node *new1)
{
    struct node *temp;
    char ch;
    printf("INSERT AT RIGHT OR LEFT (R/L) \n");
    ch=getch();
    if(ch=='R')
    {
        if(root->right==NULL)
        {
            root->right=new1;
        }
        else
        {
            insert(root->right,new1);
        }
    }
    else if(ch=='L')
    {
        if(root->left==NULL)
        {
            root->left=new1;
        }
        else
        {
            insert(root->left,new1);
        }
    }
    else
    {
        printf("WRONG CHOICE \n");
    }
}

void display(struct node *root)
{
    if(root==NULL)
        return;
    display(root->left);
    printf("%d \n",root->data);
    display(root->right);
}

