#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

char st[MAX];
int top=-1;

void push(char st[], char val)
{

		if(top==MAX-1){
			printf("\n!!! Stack Overflow !!!\n");
			return;
		}
		else{
			st[++top]=val;
	}
}

char pop(char st[])
{

    char val;
    if(top==-1){
        printf("\n!!! Stack Underflow !!!");
        return;
    }

    else{
        return st[top--];
    }
}

int getpriority(char op)
{

    if(op=='/' || op=='*' || op=='%')
        return 1;

    else if(op=='+' || op=='-')
        return 0;
}

void InfixtoPostfix(char source[], char target[])
{
    int i=0, j=0;
    char temp;

    strcpy(target, "");
    while(source[i]!='\0')
    {
        if(source[i]=='(')
        {
            push(st, source[i]);
            i++;
        }
        else if(source[i]==')')
        {
            while((top!=-1) && (st[top]!='('))
            {
                target[j]=pop(st);
                j++;
            }
            if(top==-1)
            {
                printf("Incorrect Expression");
                exit(1);
            }
            temp=pop(st);
            i++;
        }
        else if(isdigit(source[i]) || isalpha(source[i]))
        {
            target[j]=source[i];
            j++;
            i++;
        }
        else if(source[i]=='+' || source[i]=='-' || source[i]=='*' || source[i]=='/' || source[i]=='%')
        {
            while((top!=-1) && (st[top]!='(') && (getpriority(st[top])>=getpriority(source[i])))
            {
                target[j]=pop(st);
                j++;
            }
            push(st, source[i]);
            i++;
        }
        else
        {
            printf("Incorrect Element in Expression");
            exit(1);
        }
    }
    while(top!=-1 && (st[top]!='('))
    {
        target[j]=pop(st);
        j++;
    }
    target[j]='\0';
}

int main()
{
    char infix[100], postfix[100];
    printf("Enter any Infix Expression: ");
    gets(infix);
    strcpy(postfix, "");
    InfixtoPostfix(infix, postfix);
    printf("Postfix: ");
    puts(postfix);
    printf("\n");
    return 0;
}
