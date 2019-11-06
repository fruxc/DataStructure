#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define max 100
 
int top = -1;
char stack[max];

void push(char);
char pop();
void find_top();
int precedence(char);
int isOperator(char);
void InfixToPostfix(char[] , char[]);
 
int main()
{
	int i;
	char infix_temp[max], postfix_temp[max];
	printf("\nEnter Infix expression : \n");
	gets(infix_temp);
	
	InfixToPostfix(infix_temp, postfix_temp);
	printf("\nPostfix Expression : \n");
	puts(postfix_temp);
	
	return 0;
}

void push(char item)
{
	if(top >= max-1)
	{
		printf("\nStack Overflow.\n");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}
 
char pop()
{
	char item ;

	if(top <0)
	{
		printf("\nStack Underflow.\n");
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

void find_top()
{
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}
	else
		printf("\nValid Expression.\n");
}

int precedence(char s)
{
	if(s == '^')
	{
		return(3);
	}
	else if(s == '*' || s == '/')
	{
		return(2);
	}
	else if(s == '+' || s == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int is_operator(char c)
{
	if(c == '^' || c == '*' || c == '/' || c == '+' || c =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

void InfixToPostfix(char infix[], char postfix[])
{
	int i, j;
	char item;
	char x;

	push('(');
	strcat(infix,")");

	i=0;
	j=0;
	item=infix[i];

	while(item != '\0')
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix[j] = item;
			j++;
		}
		else if(is_operator(item) == 1)
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix[j] = x;
				j++;
				x = pop();
			}
			push(x);
			push(item);
		}
		else if(item == ')')
		{
			x = pop();
			while(x != '(')
			{
				postfix[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ 
			printf("\nInvalid infix Expression.\n");
			getchar();
			exit(1);
		}
		i++;


		item = infix[i];
	}
	
	find_top();
	
	postfix[j] = '\0';
}
