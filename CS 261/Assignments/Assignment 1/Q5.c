/*********************************************************************
** Program Filename: Q5.c
** Author: Grant Nakashima
** Date: 04/09/15
** Description: This program will take in an input from the user and then
**				alter the string to change the caps of the letters from either upper to lower or 
**				from lower to upper. 
** Input: The user will input a string
** Output: The user's input will get changed. For example, if the input was
			Grant it would get changed to GrAnT
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void sticky(char*);
char toUpperCase(char);
char toLowerCase(char);

int main()
{
	char word[100];

	/*Read word from the keyboard using gets*/
	printf("Enter the string: ");
	scanf("%s", word);

	/*Call sticky*/
	sticky(word);
	/*Print the new word*/
	printf("%s \n", word);

	return 0;
}

/*********************************************************************
** Function: sticky
** Description: It will alternate and change the letters to lower case or to upper case.
** Parameters: it will take in the char array pointer 
** Pre-Conditions: must have input from user
** Post-Conditions: none
*********************************************************************/
void sticky(char* word)
{
	int length = 0;

	while (word[length] != '\0')		// get the length of the char array
	{
		length++;
	}

	for (int i = 0; i < length; i++)
	{
		if (word[i] == '\0')			// will break if reaches null
		{
			return;
		}
		if (i % 2)						// will make the letters lower case if even
		{
			word[i] = toLowerCase(word[i]);
		}
		else                            // will make letters upper case if odd
		{
			word[i] = toUpperCase(word[i]);
		}
	}
}

/*********************************************************************
** Function: toUpperCase
** Description: It will change the character to upper case
** Parameters: it will take in the char
** Pre-Conditions: must have input from user
** Post-Conditions: none
*********************************************************************/
char toUpperCase(char ch)
{
	if (ch == toupper(ch))
	{
		return ch;
	}
	else
	{
		return ch - 'a' + 'A';
	}
}

/*********************************************************************
** Function: toLowerCase
** Description: It will change the character to lower case
** Parameters: it will take in the char
** Pre-Conditions: must have input from user
** Post-Conditions: none
*********************************************************************/
char toLowerCase(char ch)
{
	if (ch == tolower(ch))
	{
		return ch;
	}
	else
	{
		return ch - 'A' + 'a';
	}
}
