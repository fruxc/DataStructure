#include<stdio.h>

int queue[100], front, rear, c, n, x;
void enqueue(int);
void dequeue(void);
void display(void);

int main()
{
	rear = -1;
	front = 0;
	printf("\n Enter the size of Queue max is 100 :");
	scanf("%d",&n);
	printf("\n\t Queue operations using array");
	printf("\n\t 1. Enqueue.\n\t 2. Dequeue.\n\t 3. Display.\n\t 4. Exit");
	do
	{
		printf("\n Enter your choice :\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				printf("\n Enter an element to enqueue\n");
				scanf("%d",&x);
				enqueue(x);
				break;
			}
			case 2:
			{
				printf("\n Dequeuing the element\n");
				dequeue();
				break;
			}
			case 3:
			{
				printf("\n Queue Array\n");
				display();
				break;
			}
			case 4:
			{
				printf("\n Exit ...\n");
				break;
			}
			default:
			{
				printf("\n Invalid Option\n");
				break;
			}
		}
	}while(c != 4);
return 0;
}

void enqueue(int p)
{

	if(rear >= n-1)
	{
		printf(" Queue overflow.\n");
	}
	else
	{
		rear++;
		queue[rear] = p;
	}
}

void dequeue()
{
	if(rear>=front)
	{
		int  ele = queue[front];
		queue[front] = '\0';
		printf(" Deleted Element - %d \n",ele);
		front++;
	}
	else
	{
		printf(" Queue is underflow\n");
	}
}

void display()
{
	if(rear<0)
	{
		printf(" Queue is empty\n");
	}
	else
	{	if(front <= rear)
		{
			for(int i=front; i<=rear; i++)
			{
				printf(" Queue Elements :- %d \n",queue[i]);
			}
		}
		else
		{
			printf(" All elements has been deleted \n");
		}
	}
}

