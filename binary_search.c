#include<stdio.h>
int main()
{
    int a[10],n,i,item,flag=0,low=0,high,mid;
    printf("ENTER SIZE OF ARRAY :");
    scanf("%d",&n);
    printf("ENTER ARRAY IN ASCENDING ORDER \n");
    for(i=0;i<n;++i)
    {
        printf("ENTER ELEMENT %d :",i+1);
        scanf("%d",&a[i]);
    }
    printf("ENTER THE ELEMNT TO BE SEARCHED");
    scanf("%d",&item);
    high=n;
    while(low<high)
    {
        mid=(high+low)/2;
        if(item>a[mid])
        {
            low=mid+1;
        }
        else if(item<a[mid])
        {
            high=mid-1;
        }
        else
        {
            flag=1;
            i=mid;
            break;
        }
    }
    if(flag==0)
    {
        printf("element not found");
    }
    else
    {
        printf("ELEMENT AT %d",i+1);
    }
    return 0;
}
