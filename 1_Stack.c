#include<stdio.h>
#include<stdlib.h>

#define max 50

int p=0;
int top=-1;
int stack [max];

int isEmpty(){

		if(top==-1){
			return 1;
		}
		else{
			return 0;
		}
}

int isFull(int size){

		if(top==size-1){
			return 1;
		}
		else{
			return 0;
		}
}

void push(int value, int size){

		if(isFull(size)){
			printf("\n!!! Stack Overflow !!!\n");
			return;
		}
		else{
			stack[++top]=value;
	}
}

int pop(){

        int value;
		if(isEmpty()){
                p=0;
		}
		else{
            p=1;
			return stack[top--];
		}
}

int peek(){

		if(isEmpty()){
			p=0;
		}
		else{
            p=1;
			return stack[top];
		}
}

void display(){

		if(isEmpty()){
			printf("\n!!! Stack Underflow !!!\n");
		}
		else{
			for(int i=top; i>=0; i--){
					printf("%d\n", stack[i]);
				}
		}
}

int main(){

	int size, c, x, value;
	printf("Enter the Size of the Stack: ");
	scanf("%d", &size);


	do{

			printf("\n*****MENU*****");
			printf("\n1. Push");
			printf("\n2. Pop");
			printf("\n3. Peek");
			printf("\n4. Display");
			printf("\n5. Exit");
			printf("\n\nChoice: ");
			scanf("%d", &c);

			switch(c){

					case 1:
						printf("Enter the Element to be Pushed: ");
						scanf("%d", &x);
						push(x, size);
						break;

					case 2:
					    value=pop();
					    if(p!=0)
                            printf("Element Popped Out: %d\n", value);
                        else
                            printf("\n!!! Stack Underflow !!!\n");

						break;

					case 3:
					    peek();
					    if(p!=0)
                            printf("Element present at the top: %d\n", peek());
						else
                            printf("\n!!! Stack Underflow !!!\n");
						break;

					case 4:
						display();
						break;

					case 5:
						printf(".......Program Terminating.......\n\n");
						exit(0);

                    default:
                        printf("Invalid Choice\n");
                        break;
			}
	}while(c!=5);
}
