#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int p=0;
int queue[MAX];
int front =-1, rear=-1;

int isEmpty(){

		if(front==-1 || front>rear){
			return 1;
		}
		else{
			return 0;
		}
}

int isFull(int size){

		if(rear==size-1){
			return 1;
		}
		else{
			return 0;
		}
}

void enqueue(int size)
{
    int num;
    printf("Enter the Number to be inserted in the Queue: ");
    scanf("%d", &num);

    if(isFull(size))
    {
        printf("\n!!! Queue Overflow !!!\n");
        return;
    }


    else if(front==-1 && rear==-1)
        front =rear =0;

    else
        rear ++;

    queue[rear]= num;
}

int dequeue()
{
    int val;
    if (isEmpty())
    {
        printf("\n!!! Queue Underflow !!!\n");
        p=0;
        return;
    }

    else
    {
        val = queue[front];
        front++;
        p=1;
        if(front>rear)
            front=rear=-1;

        return val;
    }
}

int peek()
{
    if(isEmpty())
    {
        printf("\n!!! Queue Underflow !!!\n");
        p=0;
        return;
    }

    else
    {
        p=1;
        return queue[front];
    }
}

void display()
{
    if(isEmpty())
        printf("\n!!! Queue Underflow !!!\n");

    else
    {
        printf("Queue: ");
        for(int i=front; i<=rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int option, val, size;

    printf("Enter the Size of the Queue (Less than 100): ");
	scanf("%d", &size);

    do
    {
        printf("\n*****MENU*****\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("\nYour Choice: ");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            enqueue(size);
            break;

        case 2:
            val=dequeue();
            if(p!=0)
                printf("The Element Dequeued: %d\n", val);
            break;

        case 3:
            val=peek();
            if(p!=0)
                printf("The Element at the Front: %d\n", val);
            break;

        case 4:
            display();
            break;

        case 5:
            printf("\n.......Program Terminating.......\n\n");
            break;

        default:
            printf("!!! Invalid Choice !!!\n");
        }
    }while(option!=5);
}
