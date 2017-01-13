#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"
#include <assert.h>
#include <math.h>


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	assert(stack != 0);

	TYPE secondNum = topDynArr(stack);
	popDynArr(stack);

	TYPE firstNum = topDynArr(stack);
	popDynArr(stack);

	TYPE sum = firstNum + secondNum;
	pushDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	assert(stack != 0);

	TYPE secondNum = topDynArr(stack);
	popDynArr(stack);

	TYPE firstNum = topDynArr(stack);
	popDynArr(stack);

	TYPE sum = firstNum - secondNum;
	pushDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	assert(stack != 0);

	TYPE secondNum = topDynArr(stack);
	popDynArr(stack);

	TYPE firstNum = topDynArr(stack);
	popDynArr(stack);

	TYPE sum = firstNum / secondNum;
	pushDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their product is pushed back onto the stack.
*/
void multiply(struct DynArr *stack)
{
	assert(stack != 0);

	TYPE secondNum = topDynArr(stack);
	popDynArr(stack);

	TYPE firstNum = topDynArr(stack);
	popDynArr(stack);

	TYPE sum = firstNum * secondNum;
	pushDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their sum is pushed back onto the stack.
*/
void power(struct DynArr *stack)
{
	assert(stack != 0);

	TYPE secondNum = topDynArr(stack);
	popDynArr(stack);

	TYPE firstNum = topDynArr(stack);
	popDynArr(stack);

	TYPE sum = pow(firstNum, secondNum);
	pushDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the top two elements are popped and
their sum is pushed back onto the stack.
*/
void square(struct DynArr *stack)
{
	assert(stack != 0);

	TYPE firstNum = topDynArr(stack);
	popDynArr(stack);

	TYPE secondNum = 2;

	TYPE sum = pow(firstNum, secondNum);
	pushDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the top two elements are popped and
their sum is pushed back onto the stack.
*/
void cube(struct DynArr *stack)
{
	assert(stack != 0);

	TYPE firstNum = topDynArr(stack);
	popDynArr(stack);

	TYPE secondNum = 3;

	TYPE sum = pow(firstNum, secondNum);
	pushDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the top two elements are popped and
their sum is pushed back onto the stack.
*/
void absolute(struct DynArr *stack)
{
	assert(stack != 0);

	TYPE firstNum = topDynArr(stack);
	popDynArr(stack);

	TYPE sum = (abs(firstNum));
	pushDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the top two elements are popped and
their sum is pushed back onto the stack.
*/
void squareRoot(struct DynArr *stack)
{
	assert(stack != 0);

	TYPE firstNum = topDynArr(stack);
	popDynArr(stack);

	TYPE sum = sqrt(firstNum);
	pushDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the top two elements are popped and
their sum is pushed back onto the stack.
*/
void exponential(struct DynArr *stack)
{
	assert(stack != 0);

	TYPE firstNum = topDynArr(stack);
	popDynArr(stack);

	TYPE sum = exp(firstNum);
	pushDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the top two elements are popped and
their sum is pushed back onto the stack.
*/
void naturalLog(struct DynArr *stack)
{
	assert(stack != 0);

	TYPE firstNum = topDynArr(stack);
	popDynArr(stack);

	TYPE sum = log(firstNum);
	pushDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the top two elements are popped and
their sum is pushed back onto the stack.
*/
void baseTenLog(struct DynArr *stack)
{
	assert(stack != 0);

	TYPE firstNum = topDynArr(stack);
	popDynArr(stack);

	TYPE sum = log10(firstNum);
	pushDynArr(stack, sum);
}

/*	param: integer size of input and char
pre: argc is not equal to 1
post: the final number is calculated without errors. 
*/
double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		if (strcmp(s, "+") == 0)			// add
		{
			if (sizeDynArr(stack) >= 2)		// make sure stack has two numbers to add together
			{
				add(stack);
			}
			else
			{
				printf("Not enough numbers. %s is causing an error. Exiting.\n", s);
				exit(0);
			}
		}
		else if (strcmp(s, "-") == 0)		// subtract
		{
			if (sizeDynArr(stack) >= 2)		// make sure stack has two numbers to subtract together
			{
				subtract(stack);
			}
			else
			{
				printf("Not enough numbers. %s is causing an error. Exiting.\n", s);
				exit(0);
			}
		}
		else if (strcmp(s, "/") == 0)		// divide
		{
			if (sizeDynArr(stack) >= 2)		// make sure stack has two numbers to divide together
			{
				divide(stack);
			}
			else
			{
				printf("Not enough numbers. %s is causing an error. Exiting.\n", s);
				exit(0);
			}
		}
		else if (strcmp(s, "x") == 0)		// multiply
		{
			if (sizeDynArr(stack) >= 2)		// make sure stack has two numbers to multiply together
			{
				multiply(stack);
			}
			else
			{
				printf("Not enough numbers. %s is causing an error. Exiting.\n", s);
				exit(0);
			}
		}
		else if (strcmp(s, "^") == 0)		// calculate power
		{
			if (sizeDynArr(stack) >= 2)		// make sure stack has two numbers to use for power
			{
				power(stack);
			}
			else
			{
				printf("Not enough numbers. %s is causing an error. Exiting.\n", s);
				exit(0);
			}
		}
		else if (strcmp(s, "^2") == 0)		// calculate square
		{
			square(stack);
		}
		else if (strcmp(s, "^3") == 0)		// calculate cube
		{
			cube(stack);
		}
		else if (strcmp(s, "abs") == 0)		// calculate absolute
		{
			absolute(stack);
		}
		else if (strcmp(s, "sqrt") == 0)	// calculate square root
		{
			squareRoot(stack);
		}
		else if (strcmp(s, "exp") == 0)		// calculate exponetial
		{
			exponential(stack);
		}
		else if (strcmp(s, "ln") == 0)		// calculate natural log
		{
			naturalLog(stack);
		}
		else if (strcmp(s, "log") == 0)		// get log
		{
			baseTenLog(stack);
		}
		else 
		{
			if (strcmp(s, "pi") == 0)			// convert pi to a number
			{
				s = "3.14159265";
			}
			else if (strcmp(s, "e") == 0)		// convert e to a number
			{
				s = "2.7182818";
			}

			if (isNumber(s, &result) != 0)		// if a number see if you can push on stack
			{
				pushDynArr(stack, result);	
			}
			else                               // exit if not a number
			{
				printf("Error. Following input causing an error: %s \n", s);
				exit (0);
			}
			
		}
	}	

	assert(!isEmptyDynArr(stack));		// check to make sure stack isn't empty
	if (sizeDynArr(stack) > 1)
	{
		printf("Not enough operators. Too many numbers. ");
		for (int i = 1; i < numInputTokens; i++)
		{
			printf("%s ", inputString[i]);
		}
		printf(" \n");

		exit(0);
	}

	result = topDynArr(stack);			// get final number and make it it result

	return result;
}

int main(int argc , char** argv)
{
	if (argc == 1)
	{
		return 0;
	}

	double result = calculate(argc,argv);		// find sum of algorithm

	printf("Result: %g \n", result);			// print results

	return 0;
}
