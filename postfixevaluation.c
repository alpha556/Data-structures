#include<stdio.h>
int main()
{
    char exp[15];
    int stack[10],top=-1,a,b,i;
    printf("ENTER EXPRESSION \n");
    gets(exp);
    for( i=0;exp[i]!='\0';++i)
    {
        if(exp[i]>=48&&exp[i]<=57)
        {
                top++;
                stack[top]=(char)exp[i]-48;

        }
        else
        {
            a=stack[top];
            top--;
            b=stack[top];
            switch(exp[i])
            {
                case '+': stack[top]=b+a;
                            break;
                case '-': stack[top]=b-a;
                            break;
                case '*': stack[top]=b*a;
                            break;
                case '/': stack[top]=b/a;
                            break;
            }

        }
    }
    printf("%d",stack[top]);


    return 0;
}
