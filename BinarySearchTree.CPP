#include<stdio.h>
#include<iostream.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int data;
	struct node*left;
	struct node*right;
};

struct node*createNode(int data)
{
	struct node*newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

struct node*insert(struct node* root,int data)
{
	if(root==NULL)
	{
		return createNode(data);
	}
	if(data<root->data)
	{
		root->left=insert(root->left,data);
	}
	else if(data>root->data)
	{
		root->right=insert(root->right,data);
	}
	return root;
}

void preorder(struct node*root)
{
	if(root==NULL){
	return;
    }
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct node*root)
{
	if(root==NULL){
	return;
    }
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

int main()
{
	int choice;
	struct node*root=NULL;
	clrscr();
    while(1)
	{
		printf("\nMenu\n");
		printf("\n1. Create Binary Tree: ");
		printf("\n2. Preorder: ");
		printf("\n3. Postorder: ");
		printf("\n4. exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		if(choice==1)
		{
			int data;
			printf("Enter data: ");
			scanf("%d",&data);
			root=insert(root,data);
		}
		else if(choice==2)
		{
			printf("Pre order: ");
			preorder(root);
			printf("\n");
		}
		else if(choice==3)
		{
			printf("Post order: ");
			postorder(root);
			printf("\n");
		}
		else if(choice==4)
		{
			break;
		}
		else
		{
			printf("\nEnter a valid option...!!!!");
		}
	}
	getch();
	return 0;
}