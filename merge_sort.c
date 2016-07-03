#include<stdio.h>
void merge_sort(int [],int ,int );
void merge(int [],int ,int ,int);
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
    merge_sort(array,0,size-1);
     for(i=0;i<size;++i)
    {
       printf("%d ",array[i]);
    }
    return 0;
}
void merge_sort(int array[],int p,int r)
{
    if(p<r)
    {
       int q=(p+r)/2;

    merge_sort(array,p,q);
    merge_sort(array,q+1,r);
    merge(array,p,q,r);
    }
}
void merge(int array[],int p,int q,int r)
{
    int i,j;
    int n1=q-p+1;
    int n2=r-q;
    int b[n1],c[n2];
    for( i=0;i<n1;++i)
    {
        b[i]=array[i+p];
    }
     for( i=0;i<n2;++i)
    {
        c[i]=array[i+q+1];
    }
    i=j=0;
    int k=p;
    while ((i<n1 )&&(j<n2))
    {
        if (b[i] <= c[j])
        {
            array[k] = b[i];
            i++;
        }
        else
        {
            array[k] = c[j];
            j++;
        }
        k++;
    }
   while(i<n1)
    {
        array[k] = b[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        array[k]=c[j];
        j++;
        k++;
    }
}
