#include<stdio.h>

void insert(int ,int);
void display();
void heap_sort();
void delete();
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int loc=0;
int heap[10];
int main()
{
    int choice,data;
    printf("MAIN MENU \n");
    printf("1.INSERT \n");
    printf("2.HEAP SORT \n");
    printf("3.DISPALY \n");
    printf("ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    while(choice<4)
    {
        switch(choice)
        {
        case 1:
            printf("ENTER THE DATA \n");
            scanf("%d",&data);
            insert(loc,data);
            loc++;
            break;
        case 2:
            heap_sort(loc);
            break;
        case 3:
            display(loc);
            break;
        }
        printf("\n ENTER YOUR CHOICE \n");
        scanf("%d",&choice);
    }
    return 0;
}
void insert(int loc,int item)
{
    int par;
    while(loc>0)
    {
        par=(loc-1)/2;
        if(item<heap[par])
        {
            heap[loc]=item;
            return;
        }
        heap[loc]=heap[par];
        loc=par;
    }
    heap[0]=item;

}
void delete(int loc)
{
    int i=0;
    int left=2*i+1;
    int right=2*i+2;
    swap(&heap[loc],&heap[0]);
    while(right<loc)
    {
        if(heap[i]>heap[left]&&heap[i]>heap[right])
        {
            return;
        }
        if(heap[right]>heap[left])
        {
            swap(&heap[i],&heap[right]);
            i=right;
        }
        else if(heap[right]<heap[left])
        {
            swap(&heap[i],&heap[left]);
            i=left;
        }
            left=2*i;
            right=2*i+1;
    }
    if(left==loc-1&&heap[i]<heap[left])
    {
        swap(&heap[i],&heap[left]);
    }

}
void heap_sort(int loc)
{
    int i;
    for(i=loc; i>0; --i)
    {
        printf("%d ",heap[0]);
        delete(i);
    }
}
void display(int loc)
{
    int i;
    for(i=0; i<loc; ++i)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");
}
