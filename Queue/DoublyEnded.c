#include<stdio.h>

int queue[100], front, rear, c, n, x, front2, rear2, i;
void enqueue(int);
void enqueuer(int);
void dequeuer(void);
void dequeue(void);
void display(void);

int main()
{
	rear = -1;
	front = 0;
	printf("\n Enter the size of Queue max is 100 :");
	scanf("%d",&n);
	rear2 = n;
	front2 = n-1;
	printf("\n\t Queue operations using array");
	printf("\n\t 1. Enqueue.\n\t 11. Right Enqueue.\n\t 2. Dequeue.\n\t 22. Right Dequeue.\n\t 3. Display.\n\t 4. Exit");
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
			case 11:
			{
				printf("\n Enqueuing from right\n");
				printf("\n Enter an element to enqueue\n");
				scanf("%d",&x);
				enqueuer(x);
				break;
			}
			case 22:
			{
				printf("\n Dequeuing from right\n");
				dequeuer();
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
	if(rear >= rear2-1)
	{
		printf(" Queue overflow.\n");
	}
	else
	{
		rear++;
		queue[rear] = p;
	}
}

void enqueuer(int p)
{
	if(rear2 <= rear+1)
	{
		printf(" Queue Overflow\n");
	}
	else
	{
		rear2--;
		queue[rear2] = p;
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

void dequeuer()
{
	if(rear2<=front2)
	{
		int ele = queue[front2];
		queue[front2] = '\0';
		printf(" Deleted Element - %d \n",ele);
		front2--;
	}
	else
	{
		printf(" Queue is underflow\n");
	}
}

void display()
{
	if(rear<0 && rear2>n)
	{
		printf(" Queue is empty\n");
	}
	else
	{	if(front <= rear)
		{
			for(i=front; i<=rear; i++)
			{
				printf(" Queue Elements :- %d \n",queue[i]);
			}
		}
		else
		{
			printf(" All elements has been deleted from left side\n");
		}
		if(front2 >= rear2)
		{
			for(i=rear2; i<=front2; i++)
			{
				printf(" Queue Elements R :- %d \n",queue[i]);
			}
		}
		else
		{
			printf(" All elements has been deleted from right side \n");
		}
	}
}

