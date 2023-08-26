#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

float st[MAX];
int top=-1;

void push(float st[], float val)
{

		if(top==MAX-1){
			printf("\n!!! Stack Overflow !!!\n");
			return;
		}
		else{
			st[++top]=val;
	}
}

float pop(float st[])
{

    float val;
    if(top==-1){
        printf("\n!!! Stack Underflow !!!");
        return;
    }

    else{
        return st[top--];
    }
}

float evaluatePostfix(char exp[])
{
    int i=0;
    float op1, op2, value;
    while(exp[i]!='\0')
    {
        if(isdigit(exp[i])){

            //to handle the case when there are more than double digit numbers
            float num = 0;
                while (isdigit(exp[i])) {
                    num = num * 10 + (exp[i] - '0');
                    i++;
                }

            push(st, num);
        }
        else if(exp[i]==' ')
        {
            i++;
            continue;
        }
        else
        {
            op2=pop(st);
            op1=pop(st);

            switch(exp[i])
            {
            case '+':
                value=op1+op2;
                break;

            //to handle cases when spaces are added
            case '-':
                value=op1-op2;
                break;

            case '/':
                value=op1/op2;
                break;

            case '*':
                value=op1*op2;
                break;

            case '%':
                value=(int)op1%(int)op2;
                break;

            case '^':
                value=pow(op1,op2);
                break;

            }

            push(st,value);
        }
        i++;
    }
    return (pop(st));
}

int main()
{
    float val;
    char exp[100];
    printf("Enter any Postfix Expression (Add Spaces): ");
    gets(exp);
    val=evaluatePostfix(exp);
    printf("The Evaluated Postfix Expression: %.2f", val);
    return 0;

}
