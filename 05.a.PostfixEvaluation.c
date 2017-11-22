/* 5. Design Develop and Implement a Program in C for the following Stack operations:
(a) Evaluation of Suffix expression with single digit operand and operator +,-,*,/,^ and %
*/

#include<stdio.h>
#include<math.h> // math header file is used so link it by cc ProgramName.c -lm
#include<ctype.h>

#define MAX 20

void push (int item);
int pop ();

int stack[MAX], top = -1;

void main()
{
    char postfix[MAX];
    int i , temp;
    double t1, t2;
    printf("Enter Postfix Expression");
    scanf("%s",postfix);
    for(i=0 ; postfix[i] != '\0'; i++)
    {
        if(isdigit(postfix[i]))
            push(postfix[i]-'0');
        switch(postfix[i])
        {
            case '+' : push(pop() + pop());
                       break;
            case '-' : temp = pop();
                       push(pop() - temp);
                       break;
            case '*' : push(pop() * pop());
                       break;
            case '/' : temp = pop();
                       push(pop() / temp);
                       break;
            case '%' : temp = pop();
                       push(pop() % temp);
                       break;
            case '^' : t1 = pop();
                       t2 = pop();
                       push(pow(t2,t1)); //As pow() accepts two double data type variables
                       break;
          }
  
     }
     printf("Value of given expression is %d\n",pop());
 }               
 
void push (int item)
{
    stack[++top] = item;
}

int pop()
{
    return stack[top--];
}
    
