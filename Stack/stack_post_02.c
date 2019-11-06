#include<stdio.h>

int stack[100], c, n, top, x, i;
char s;
void push(int);
void op(char);
void display(void);

int main()
{
	top = -1;
	printf("\n Enter the size of Stack max is 100 :");
	scanf("%d",&n);
	printf("\n\t Stack operations using array");
	printf("\n\t 1. Push an Element.\n\t 2. Operator. \n\t 3. Display.\n\t 4. Exit");
	do
	{
		printf("\n Enter your choice :\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				printf("\n Enter an element to push\n");
				scanf("%d",&x);
				push(x);
				break;
			}
			case 2:
			{                                                                                                                                                                              
				printf("\n Enter Operator\n");
				scanf(" %c", &s);
				op(s);
				break;
			}
			case 3:
			{
				printf("\n Stack Array\n");
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

void op(char o)
{
	if(top>=0)
	{
	printf("Operator = %c",&o);
	if(o == '+')
	{
		printf("\n Addition between top and top-1 element\n");
		stack[top-1] = stack[top-1] + stack[top];
		top--;
	}
	else if(o == '-')
	{
		printf("\n Subtraction between top and top -1\n");
		stack[top-1] = stack[top-1] - stack[top];
		top--;
	}
	else if(o == '*')
	{
		printf("\n Multipilication between top and top -1\n");
		stack[top-1] = stack[top-1] * stack[top];
		top--;
	}
	else if(o == '/')
	{
		printf("\n Division between top and top -1 \n");
		stack[top-1] = stack[top-1] / stack[top];
		top--;
	}
	}
	else
	{
		printf("Stack is empty choose again!!!");
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

