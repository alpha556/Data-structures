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
struct node * deletion(struct node *,int);
void search(struct node *,int);
void display();

int main()
{
    char ch;
    int choice,item;
    printf("MAIN MENU \n");
    printf("1.INSERT  \n");
    printf("2.DELETE \n");
    printf("3.SEARCH \n");
    printf("2.DISPLAY \n");
    printf("ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    while(choice<5)
    {
        switch(choice)
        {
        case 1:
            create();
            break;
        case 2:
             printf("ENTER THE VALUE TO BE DELETED \n");
            scanf("%d",&item);
            deletion(root,item);
            break;
        case 3:
            printf("ENTER THE VALUE TO BE SEARCHED \n");
            scanf("%d",&item);
            search(root,item);
            break;
        case 4:
            printf("THE TREE IS \n");
            display(root);

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
    if(new1->data>root->data)
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
    else
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
}
struct node *deletion(struct node *root,int item)
{
    if(root==NULL)
    {
        printf("EMPTY TREE \n");
        return;
    }
    else if(item<root->data)
    {
        root->left=deletion(root->left,item);
        return root;
    }
     else if(item>root->data)
    {
        root->right=deletion(root->right,item);
        return root;
    }
    else
    {
        if((root->left==NULL)&&(root->right==NULL))
        {
            free(root);
            root=NULL;
            return root;
        }
        else if(root->left==NULL)
        {
            struct node *temp=root;
            root=root->right;
            free(temp);
            return root;
        }
         else if(root->right==NULL)
        {
            struct node *temp=root;
            root=root->left;
            free(temp);
            return root;
        }
        else
        {
            struct node *temp=root->right;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=deletion(root->right,temp->data);
            return root;
        }
    }
}
void search(struct node *root,int item)
{
    if(root==NULL)
    {
        printf("NOT FOUND \n");
        return;
    }
    if(item>root->data)
    {
        search(root->right,item);
    }
    else if(item<root->data)
    {
        search(root->left,item);
    }
    else
    {
        printf("ITEM FOUND \n");
        return ;
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


