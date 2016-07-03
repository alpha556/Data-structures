#include<stdio.h>
int main()
{
    int a[10],b[10],c[20];
    int i,j,k,n1,n2;
    printf("ENTER SIZE OF ARRAY 1 :");
    scanf("%d",&n1);
    for(i=0;i<n1;++i)
    {
        printf("ENTER ELEMENT %d :",i+1);
        scanf("%d",&a[i]);
    }

    printf("ENTER SIZE OF ARRAY 2 :");
    scanf("%d",&n2);
    for(i=0;i<n2;++i)
    {
        printf("ENTER ELEMENT %d :",i+1);
        scanf("%d",&b[i]);
    }

    i=0,j=0;
    printf("MERGED ARRAY IS: \n");
    for(k=0;k<n1+n2;++k)
    {
        if(a[i]<=b[j]&&i<n1)
        {
            c[k]=a[i];
            i++;
        }
        else if(j<n2)
        {
            c[k]=b[j];
            j++;
        }
    }
    for(i=0;i<n1+n2;++i)
    {
        printf("ELMENT %d: %d \n",i+1,c[i]);
    }
    return 0;
}
