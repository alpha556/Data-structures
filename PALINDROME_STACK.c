#include <stdio.h>
#define MAXSIZE 5
struct stack
{
    char stk[MAXSIZE];
    int top;
}s;
int palindrome(char []);
void push(char);
char pop(void);
void display(void);
void main ()
{
    int choice;
    int option = 1;
    s.top = -1;
    printf ("ENTER STRING\n");
    char a[10];
    gets(a);
    palindrome(a);
    }
void push (char x)
{


    {
        s.top = s.top + 1;
        s.stk[s.top] = x;
    }
    return;
}
char pop ()
{
    char num;
    if(s.top==-1)
{
    return ('\0');
}
else{
        num = s.stk[s.top];
        s.top = s.top - 1;
}

    return(num);
}
void display ()
{
    int i;
    if (s.top == -1)
    {
        printf ("Stack is empty \n");
        return;
    }
    else
    {
        for (i = s.top; i >= 0; i--)
        {
            printf ("%c\n", s.stk[i]);
        }
    }
    printf ("\n"); }
int palindrome(char x[])
{
    int i=0;
    while(x[i]!='c')
    {

        push(x[i]);
        i++;
    }
    i++;

    while(s.top!=-1||x[i]!='\0')
    {

        if(x[i]!=pop())
        {
            printf("NOT PALINDROME \n");
            return 0;
        }
        i++;
    }
    if(x[i]!='\0'||s.top!=-1)
    {
        printf("NOT PALINDROME :1\n");
            return 0;
    }
    else
          printf(" PALINDROME \n");
          return 1;
}
