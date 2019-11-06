#include<stdio.h>
#include<stdlib.h>

void insertE();
void display();
void traversal();
int counter=0;

// A linked list node 
struct Node 
{
	struct Node *left;
	int data;
	struct Node *right;
}*temp, *r, *list = NULL, *s, *root, *q, *p;

//menu driven program for insertion deletion and to display linked list
int main()
{
	int ch;
	do
	{
		printf("\n Enter Choice :-\n");
		printf("\n 1. Insert at the binary tree.\n 2. Traversal.\n 3. Display. \n 9. Exit.\n");

		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertE();
				break;
			case 2:
				traversal();
				break;
			case 3:
				display();
				break;
			case 9: 
				printf("\n Bye!!!\n");
				exit(0);
				break;
			default:
				printf("\n Invalid Choice\n");
				break;
		}
	}while(ch!=9);
}

void insertE()
{
	int data1;
        if(root==NULL)
        {
                p = (struct Node *)malloc(sizeof(struct Node));//To assign memory location.
                printf("\n Enter an element to insert.\n");//input.
                scanf("%d",&data1);
                p->data = data1;        //setting very first element->next to null eg list->data = data1 and list->next = NULL.
                p->left = NULL;
		p->right = NULL;
                root = p;
		r = p;
        }
        else
        {
                p = (struct Node *)malloc(sizeof(struct Node));//To assign memory location.
                printf("\n Enter an element to insert.\n");//input.
                scanf("%d",&data1);
		p->data = data1;
		p->left = NULL;
		p->right = NULL;
                q = root;
		while(q!=NULL)
		{
			if(p->data>q->data)
			{
				if(q->right==NULL)
				{
					q->right = p;
					break;
				}
				q = q->right;
			}
			else if(p->data<q->data)
			{
				if(q->left == NULL)
				{
					q->left = p;
					break;
				}
				q = q->left;
			}
		}
	}
}
void display()
{
	if(root==NULL)
        {
                printf("\n Linked List is empty.\n");
        }
        else
        {
		printf(" Elements :-");
		q=root;
		counter = 0;
		while(q != NULL)
		{	
			while(q->left!=NULL)
			{
				if(q->left != NULL)
				{
					printf("%d\t",q->data);counter++;
				}
				else if(q->right != NULL)
				{
					printf("%d\t",q->data);counter++;
				}
				q=q->left;
			}
			while(q->right!=NULL)
			{
				if(q->right != NULL)
				{
					printf("%d\t",q->data);counter++;
				}
				else if(q->left != NULL)
				{
					printf("%d\t",q->data);counter++;
				}
				q=q->right;
			}
		}
		printf(" Total count of elements = %d",counter);
	}
}

void traversal()
{

}
