/*
4 Design, Develop and Implement a Program in C for converting an Infix
Expression to Postfix Expression. Program should support for both
parenthesized and free parenthesized expressions with the operators: +, -, *,/,
 %(Remainder), ^(Power) and alphanumeric operands.
*/

#include<stdio.h>
#include<stdlib.h>

typedef enum {lparen, rparen, plus, minus, mul, divi, mod, pwr, eos, operand} precedence;

precedence getToken(char infix[], char *symbol, int *n);
void convert(char infix[]);
void push(int stack[], int *top, precedence token);
precedence pop(int stack[], int *top);
void printToken(precedence token);

void main()
{
	char infix[30];
	printf("Enter Infix Expression\n");
	gets(infix);
	convert(infix);
}

precedence getToken(char infix[], char *symbol, int *n)
{
	*symbol = infix[(*n)++];
	switch(*symbol)
	{
		case '(':	return lparen;
		case ')':	return rparen;
		case '+':	return plus;
		case '-':	return minus;
		case '*':	return mul;
		case '/':	return divi;
		case '%':	return mod;
		case '^':	return pwr;
		case '\0':	return eos;
		default:	return operand;
	}
}

void convert(char infix[])
{
	int stack[20], top = 0, n=0;
	int icp[] = {5, 4, 1, 1, 2, 2, 2, 3, 0};
	int isp[] = {0, 4, 1, 1, 2, 2, 2, 3, 0};
	precedence token;
	char symbol;
	stack[0] = eos;
	for(token = getToken(infix, &symbol, &n); token != eos; token = getToken(infix, &symbol, &n))
	{
		if(token == operand)
			printf("%c", symbol);
		else if(token == rparen)
		{
			while(stack[top] != lparen)
			{
				printToken(pop(stack, &top));
			}
			pop(stack, &top);
		}
		else
		{
			while(isp[stack[top]] >= icp[token])
			{
				printToken(pop(stack, &top));
			}
			push(stack, &top, token);
		}
	}
	while(stack[top] != eos)
	{
		printToken(pop(stack, &top));
	}
}

void push(int stack[], int *top, precedence token)
{
	stack[++(*top)] = token;
}

precedence pop(int stack[], int *top)
{
	return stack[(*top)--];
}

void printToken(precedence token)
{
	switch(token)
	{
		case plus:
			printf("+");
			break;
		case minus:
			printf("-");
			break;
		case mul:
			printf("*");
			break;
		case divi:
			printf("/");
			break;
		case mod:
			printf("%c", '%');
			break;
		case pwr:
			printf("^");
			break;
	}
}