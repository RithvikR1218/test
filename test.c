#include<stdio.h>

char a[10];
int size = 10;
int p = -1;

int isEmpty()
{
    if (p == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    } 
}

int isFull()
{
    if ( p == size - 1 )
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int top()
{
    if (isEmpty())
    {
        return 0;
    }
    else
    {
        return a[p];
    }
}

void push(char q)
{
    if(isFull())
    {
        printf("Stack is Full\n");
    }
    else
    {
        p = p + 1;
        a[p] = q;
    }
}

int isOperator(char r)
{
    if ( r == '+' || r == '-' || r == '*' || r == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
        return 1;
    case '-': 
        return 2; 
    case '*': 
        return 3;
    case '/': 
        return 4; 
    case '^': 
        return 5; 
    } 
    return -1; 
}

void pop()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        int tmp;
        tmp = a[p -1];
        p = p - 1;
        a[p] = tmp;
    }
}

void main()
{
    printf("Length of Infix?\n");
    int b;
    scanf("%d",&b);
    char arr[b];
    scanf("%s",arr);
    for (int i = 0; i < b ; i++)
    {
        if ( arr[i] == '(')
        {
            push('(');
        }

        else if ( arr[i] == ')' )
        {
            while ( top() != '(')
            {
                printf("%c",top());
                pop();
            }
            if (top() == '(')
            {
                pop();
            }
        }
        
        else if( isOperator(arr[i]) )
        {
            if( isOperator(top()) && (precedence(top()) < precedence(arr[i])) )
            {
                printf("%c",arr[i+1]);
                push(arr[i]);
                i = i + 1;
            }
            else if( isOperator(top()) && (precedence(top()) >= precedence(arr[i])) )
            {
                printf("%c",top());
                pop();
                push(arr[i]);
            }
            else
            {
                printf("%c",arr[i+1]);
                push(arr[i]);
                i = i + 1;
            }
        }
        else
        {
            printf("%c",arr[i]);
        }
    }
    for (int j=p; j > -1 ; j--)
    {
        printf("%c",a[j]);
    }
}