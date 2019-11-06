#include<stdio.h>

int stack[100], c, n, top, x, i;
void push(int);
void pop(void);
void display(void);

int main()
{
	top = -1;
	printf("\n Enter the size of Stack max is 100 :");
	scanf("%d",&n);
	printf("\n\t Stack operations using array");
	printf("\n\t 1. Push.\n\t 2. Pop.\n\t 3.Display.\n\t 4.Exit");
	do
	{
		printf("\n Enter your choice :\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				printf("\nEnter an element to push\n");
				scanf("%d",&x);
				push(x);
				break;
			}
			case 2:
			{
				printf("\nPopping the element\n");
				pop();
				break;
			}
			case 3:
			{
				printf("\nStack Array\n");
				display();
				break;
			}
			case 4:
			{
				printf("\nExit ...\n");
				break;
			}
			default:
			{
				printf("\nInvalid Option\n");
				break;
			}
		}
	}while(c != 4);
return 0;
}

void push(int p)
{
	if(top>=n-1)
	{
		printf("\n Stack Overflow\n");
	}
	else
	{
		top++;
		stack[top]=p;
	}
}

void pop()
{
	if(top<0)
	{
		printf("\n Stack Underflow\n");
	}
	else
	{
		printf("\n Popped element in Stack is %d",stack[top]);
		top--;
	}
}

void display()
{
	if(top>=0)
	{
		printf("\nElements in the Stack\n");
		for(i=0; i<=top; i++)
		{
			printf("%d\t",stack[i]);
		}
	}
	else
	{
		printf("\nStack is empty\n");
	}
}

