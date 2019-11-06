#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

int top = -1;
char stack[max];

void push(char);
void pop();
void find_top();
 
int main()
{
	int i;
	char temp[max];
	printf("\nEnter expression\n");
	scanf("%s", &temp);
	for (i = 0; temp[i] != '\0';i++)
	{
		if (temp[i] == '(')
		{
			push(temp[i]);
		}
		else if (temp[i] == ')')
		{
			pop();
		}
		else if (temp[i] == '[')
		{
			push(temp[i]);
		}
		else if (temp[i] == ']')
		{
			pop();
		}
		else if (temp[i] == '{')
		{
			push(temp[i]);
		}
		else if (temp[i] == '}')
		{
			pop();
		}
	}
	find_top();
	return 0;
}

void push(char p)
{
	stack[top] = p;
	top++;
}
 
void pop()
{
	if (top == -1)
	{
		printf("\nStack Underflow\n");
		exit(0);
	}	
	else
	{		
		top--;
	}
}

void find_top()
{
	if (top == -1)
		printf("\nExpression's parentheses are balanced\n");
	else
		printf("\nExpression's parentheses not balanced\n");
}
