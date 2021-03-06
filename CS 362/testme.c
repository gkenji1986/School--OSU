/************************************************
* Author: Grant Nakashima
* Due Date: 7/17/16
* Assignment: Quiz 2
*************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function

	char random = rand() % 94 + 32;		//character

	return random;
}

char *inputString()
{
    // TODO: rewrite this function
	int i = 0;
	char resetChars[] = { 'r','e', 's', 'e', 't' };
	char *inputReturn = (char *)malloc(6);
	char random;
	int index = 0;

	if ((rand() % 10) % 5 == 0)		//picked random number to create string from characters from a -z 
	{
		while (i < 5)
		{
			random = ((rand() % 26) + 97);
			inputReturn[i] = random;
			i++;
		}
		inputReturn[i] = '\0';
		i = 0;
	}
	else
	{
		while (i < 5)		//this loops increases the chance to create the string 'reset'. added to speed up the process/chance of printing
		{
			index = rand() % 6;
			inputReturn[i] = resetChars[index];
			i++;
		}
		inputReturn[i] = '\0';
		i = 0;

	}

    return inputReturn;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
	free(s);		//free memory 
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();

    return 0;
}
