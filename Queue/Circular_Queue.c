#include<stdio.h>

int queue[100], front, rear, c, n, x, i;
int isEmpty();
void enqueue(int);
void dequeue(void);
void display(void);

int main()
{
	rear = -1;
	front = -1;
	printf("\n Enter the size of Queue max is 100 :");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		queue[i]='\0';
	}
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
    if(isFull()) 
	{
    	printf("\n Queue is full!! \n");
	}
    else
    {
        if(front == -1) front = 0;
        rear = (rear + 1) % n;
        queue[rear] = p;
        printf("\n Inserted -> %d", p);
    }
}

void dequeue()
{
    int ele;
    if(isEmpty()) {
        printf("\n Queue is empty !! \n");
        return(-1);
    } 
	else 
	{
        ele = queue[front];
        if (front == rear){
            front = -1;
            rear = -1;
        } 
        else {
            front = (front + 1) % n;
        }
        printf("\n Deleted element -> %d \n", ele);
    }
}

void display()
{
    int i;
    if(isEmpty())
	{
		printf("\n Empty Queue\n");
	} 
    else
    {
        for( i = front; i!=rear; i=(i+1)%n) {
            printf("%d \t",queue[i]);
        }
        printf("%d ",queue[i]);
    }
}


int isFull()
{
    if( (front == rear + 1) || (front == 0 && rear == n-1)) 
	{
		return 1;
	}
    return 0;
}

int isEmpty()
{
    if(front == -1)
    {
    	return 1;
	}
    return 0;
}
