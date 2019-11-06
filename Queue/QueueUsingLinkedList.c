#include<stdio.h>
#include<stdlib.h>

void enqueue();
void display();
void dequeue();
int counter=0;

// A linked list node 
struct Node 
{ 
	int data;
	struct Node *next;
}*temp, *front = NULL, *r, *q, *p;

//menu driven program for insertion deletion and to display linked list
int main()
{
	int ch;
	
	do
	{
		printf("\n Enter Choice :-\n");
		printf("\n 1. Enqueue an element.\n 2. Dequeue an element.\n 3. Display.\n 4. Exit.\n");

		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
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
void enqueue()
{
	int data1;
        if(front==NULL)
        {
                p = (struct Node *)malloc(sizeof(struct Node));//To assign memory location.
                printf("\n Enter an element to insert.\n");//input.
                scanf("%d",&data1);
                p->data = data1;        //setting very first element->next to null eg list->data = data1 and list->next = NULL.
                p->next = NULL;
                front = p;

        }
        else
        {
                p = (struct Node *)malloc(sizeof(struct Node));//To assign memory location.
                printf("\n Enter an element to insert.\n");//input.
                scanf("%d",&data1);
		p->data = data1;
                p->next = NULL;         //NULL because it'll be the last element of the linked list.
		q = front;
		while(q->next != NULL)
		{
			q = q->next;	//To check pointer q has reached last location of the linked list.
		}
		q->next = p;		//setting last element to p which will be like adding a new element at the last location.

	}
}

void dequeue()
{
	if(front == NULL)
	{
		printf("\n Queue Underflow.\n");		//to check whether it is empty or not
	}
	else
	{
		q = front;
		front = front->next;				//since list is pointing at first location and we're storing it in q and pointing out list to next element. Free q will delocate memeory.
		if(q->next == NULL)
		{
			front = NULL;
		}
		free(q);
		printf("\n Dequeued an element.\n");
	}
}

void display()
{
	if(front==NULL)
        {
                printf("\n Queue is empty.\n");
        }
        else
        {
		printf(" Elements :-\n\n\t\t");
		q=front;
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

