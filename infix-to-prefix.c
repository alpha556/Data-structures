#include<stdio.h>
#include<string.h>
void postfix(char []);
int precedence(char );
char stack[15];
int top=-1;
int main()
{
    char infix[15];
    int c=0;
    while(c<2)
    {
        printf("\n MAIN MENU \n");
        printf("1.ENTER EXPRESSION \n");
        printf("2.EXIT \n");
        printf("ENTER YOUR CHOICE \n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("ENTER THE EXPRESSION \n");
                    scanf("%s",infix);
                    postfix(infix);
                    break;
            case 2: c=3;

        }
    }


    return 0;

}
void postfix(char p[])
{
    char temp[15];
    int i,j=0;
    for(i=strlen(p)-1;i!=-1;--i)
    {
        if(isalnum(p[i]))
           {
               temp[j]=p[i];
                j++;
           }
         else if(p[i]==')')
        {
            top++;
            stack[top]=p[i];
        }

                else if(p[i]=='(')
                {
                     while(stack[top]!=')')
                        {
                            temp[j]=stack[top];
                j++;
                            top--;
                        }
                        top--;
                }

                 else if((precedence(p[i])<=precedence(stack[top]))&&top!=-1)
                 {
                     temp[j]=stack[top];
                j++;
                     stack[top]=p[i];
                 }
                else

                {
                    top++;
                    stack[top]=p[i];
                }

    }
    while(top!=-1)
    {
         temp[j]=stack[top];
                j++;
        top--;
    }
temp[j]='\0';
for(i=strlen(temp)-1;i!=-1;--i)
{
    printf("%c",temp[i]);
}
}
int precedence(char x)
{   if(x==')')
       return 0;
    if(x== '+' || x == '-')
        return(1);
    else if(x == '*' || x == '/')
        return(2);
        return 3;


}

