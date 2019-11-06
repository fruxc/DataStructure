#include<stdio.h>
#include<stdlib.h>

void push();
void display();
void pop();
int counter=0;

// A linked list node 
struct Node 
{ 
	int data;
	struct Node *next;
}*r, *temp, *top = NULL, *q, *p;

//menu driven program for insertion deletion and to display linked list
int main()
{
	int ch;
	
	do
	{
		printf("\n Enter Choice :-\n");
		printf("\n 1. Push an element.\n 2. Pop an element.\n 3. Display Stack.\n 4. Exit.\n");

		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\n Bye!!!\n");
				exit(0);
				break;
			default:
				printf("\n Invalid Choice\n");
				break;
		}
	}while(ch!=4);
}

void push()
{
	int data1;
        if(top==NULL)
        {
                p = (struct Node *)malloc(sizeof(struct Node));//To assign memory location.
                printf("\n Enter an element to insert.\n");//input.
                scanf("%d",&data1);
                p->data = data1;        //setting very first element->next to null eg list->data = data1 and list->next = NULL.
                p->next = NULL;
                top = p;

        }
        else
        {
                p = (struct Node *)malloc(sizeof(struct Node));//To assign memory location.
                printf("\n Enter an element to insert.\n");//input.
                scanf("%d",&data1);
		p->data = data1;
                p->next = NULL;         //NULL because it'll be the last element of the linked list.
		q = top;
		while(q->next != NULL)
		{
			q = q->next;	//To check pointer q has reached last location of the linked list.
		}
		q->next = p;		//setting last element to p which will be like adding a new element at the last location.
	}
}

void pop()
{
	if(top == NULL)
	{
		printf("\n Stack is empty.\n");		//to check whether it is empty or not
	}
        else
        {
                q = top;
		if(q->next == NULL)
		{
			top = NULL;
		}
                while(q->next!=NULL)		//while to point q pointer at the very last location of linked list, we're running it till end.
		{
			r = q;			//r will store previous pointed out location of linked list
			q=q->next;		//to increment q
		}
		r->next=NULL;			//setting previous location's next pointer to NULL since it's very last element so it should point to NULL.
		free(q);			// delocating memory of q
                printf("\n Popped an element from the stack.\n");
        }
}


void display()
{
	if(top==NULL)
        {
                printf("\n Stack is empty.\n");
        }
        else
        {
		printf(" Elements :-\t");
		q=top;
		counter = 0;
		while(q != NULL)
		{	
			printf("%d\t",q->data);
			q = q->next;
			counter++; // to count total number of elements in the linked list
		}
		printf(" Total count of elements = %d",counter);
	}
}

