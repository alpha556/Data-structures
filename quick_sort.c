#include<stdio.h>
void quick_sort(int [],int,int);
int partition(int [],int,int);
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    int array[10];
    int size;
    printf("ENTER THE SIZE \n");
    scanf("%d",&size);
    printf("ENTER THE ARRAY \n");
    int i;
    for( i=0;i<size;++i)
    {
        scanf("%d",&array[i]);
    }
    quick_sort(array,0,size-1);
     for(i=0;i<size;++i)
    {
       printf("%d ",array[i]);
    }
    return 0;
}
void quick_sort(int array[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(array,p,r);
        quick_sort(array,p,q-1);
        quick_sort(array,q+1,r);
    }
}
int partition(int array[],int p,int r)
{
    int i,j;
    i=p;
    for(j=p;j<r;++j)
    {
        if(array[j]<array[r])
        {
            swap(&array[j],&array[i]);
            i=i+1;
        }
    }
    swap(&array[i],&array[r]);
    return(i);
}
