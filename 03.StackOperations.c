/*
3 Design, Develop and Implement a menu driven Program in C for the
following operations on STACK of Integers (Array Implementation of Stack
with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
Support the program with appropriate functions for each of the above
operations
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int stack_full(int top);
int stack_empty(int top);
void push(int stack[], int *top, int ele);
int pop(int stack[], int *top);
int is_palindrome(int stack[], int top);
void display(int stack[], int top);

void main()
{
	int stack[MAX], top = -1, ele, ch;
	for(;;)
	{
		printf("\nMenu\n");
		printf("1. Push\n2. Pop\n3. Check Palindrome\n4. Stack Status\n5. Display\n6. Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				if(stack_full(top))
					printf("Stack Full\n");
				else
				{
					printf("Enter an Element\n");
					scanf("%d", &ele);
					push(stack, &top, ele);
				}
				break;
			case 2:
				if(stack_empty(top))
					printf("Stack Empty\n");
				else
				{
					ele = pop(stack, &top);
					printf("Deleted Element is %d", ele);
				}
				break;
			case 3:
				if(stack_empty(top))
					printf("Stack Empty\n");
				else if(is_palindrome(stack, top))
				{
					printf("Stack is Palindrome\n");
					display(stack, top);
				}
				else
					printf("Stack is not Palindrome\n");
				break;
			case 4:
				if(stack_empty(top))
					printf("Stack Empty\n");
				else if(stack_full(top))
					printf("Stack Full\n");
				else
					printf("Stack contains %d elements\n", top+1);
				break;
			case 5:
				if(stack_empty(top))
					printf("Stack Empty\n");
				else
					display(stack, top);
				break;
			case 6:
				exit(0);
		}
	}
}

int stack_full(int top)
{
	if(top == MAX-1)
		return 1;
	return 0;
}

int stack_empty(int top)
{
	if(top == -1)
		return 1;
	return 0;
}

void push(int stack[], int *top, int ele)
{
	stack[++(*top)] = ele;
}

int pop(int stack[], int *top)
{
	return stack[(*top)--];
}

int is_palindrome(int stack[], int top)
{
	int i, not_palindrome=0;
	for(i=0; i<=top/2; i++)
	{
		if(stack[i] != stack[top-i])
		{
			not_palindrome = 1;
			break;
		}
	}
	if(not_palindrome)
		return 0;
	else
		return 1;
}

void display(int stack[], int top)
{
	int i;
	for(i=0; i <= top; i++)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}