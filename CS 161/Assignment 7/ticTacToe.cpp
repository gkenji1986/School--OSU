/************************************************************************
* Author: Grant Nakashima
* Date Created: 11/14/14
* Late Modification: 11/16/14
* FileName: ticTacToe.cpp
*
* Overview: This program is a game of ticTacToe. The user
* will input a coordinate and it will then it will place it on
* the game board. The two users will continue to input coordinates
* until there is a winner or a draw. 
*
* Input : The user will input how many games they will play. Other inputs
* will be the coordinates.
*
* Output: When a user inputs a coordinate it will display an O or X 
* on the gameBoard. The game board will be displayed. It will continue
* to get inputs and will display who is the winner if there is one or 
* if there is a draw. 
*
*
* Output example: 
*  0 1 2
*0 X O X
*1 O X O
*2 X
**********************************************************************/

#include <iostream>		// need for cin and cout
#include <string>		// need for strings
#include <algorithm>	// need for atoi
#include <string.h>		// need for c- strings

using namespace std;

void GameBoardNew();			// makes a new board game
void GameBoard(char [3][3]);		// shows the game board
void MarkXO(char [3][3], int, int);		// marks the board depending on the players 
void PlayerInput();					// gets the players input 
bool CheckRowWin(char [3][3]);		// check if there is a win in the rows
bool CheckColumnWin(char[3][3]);	// checks if there is a win in the columns
bool CheckDiagonalWin(char[3][3]);	// checks if there is a win in the diagonal section
bool CheckWin(char[3][3]);			// the win function that has all of the win checks
bool CheckForDraw(char[3][3]);		// checks if there is a draw 
bool GetArrayData(int&, int&);		// receives the input from the user
char gameBoard[3][3];				// the game board for the game
int iPlayerTurn = 1;				// used to determine player 1 and 2
int Xsum, Osum;						// counter for checking win
int PlayerNumber(int);				// determine player 1 and 2
int game_counter = 0;

int main(int argc, const char * argv[])
{
	int rows = 3;   // sets the number of rows to 3
	int column = 3; // sets number of columns to 3
	cout << " Let's play a game of TicTacToe. Player one is x and Player two is o. " << endl << endl;
	//GameBoardNew();	// calling a new game
	//GameBoard(gameBoard);	// setting the gameboard to display blanks
	
	int games = atoi(argv[1]);

	while (game_counter < games)
	{
		GameBoardNew();	// calling a new game
		GameBoard(gameBoard);	// setting the gameboard to display blanks

		while (true)
		{
 			PlayerInput();  // receives the input from user
			if (CheckWin(gameBoard) == true) // checks if there is a win
			{
				cout << "Player " << PlayerNumber(iPlayerTurn) << " you win. " << endl;
				break;
			}
			else if (CheckForDraw(gameBoard) == true)  // if there is no win checks for draw
			{
				cout << "This game is a draw. " << endl;
				break;
			}
			else
			{
				iPlayerTurn++;		// if both above are false then it goes to the next player
				continue;
			}
		}
	}
	return 0;
}

/**************************************************************
* Entry: gets the gameboard size from gameboard[3][3]
* 
* Exit: When it displays the last coordinate
*
* Purpose: Display the gameboard
*
***************************************************************/
void GameBoard(char gameBoard[3][3])
{
	cout << "  0  1  2 " << endl;
	cout << "0 " << gameBoard[0][0] << "  " << gameBoard[1][0] << "  " << gameBoard[2][0] << endl;
	cout << "1 " << gameBoard[0][1] << "  " << gameBoard[1][1] << "  " << gameBoard[2][1] << endl;
	cout << "2 " << gameBoard[0][2] << "  " << gameBoard[1][2] << "  " << gameBoard[2][2] << endl;
}
/**************************************************************
* Entry: gets the gameboard
*
* Exit: When the last . is displayed
*
* Purpose: Display the gameboard with .
*
***************************************************************/
void GameBoardNew()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			gameBoard[i][j] = '.';
		}
	}
	iPlayerTurn = 1;
}

/**************************************************************
* Entry: gets the gameboard and the coordinates
*
* Exit: once it inputs the inputs the result into gameboard
*
* Purpose: add an x or o in the gameboard
*
***************************************************************/
void MarkXO(char gameBoard[3][3], int rows, int column)
{
	char XorO;

	if (iPlayerTurn % 2 == 1)
	{
		XorO = 'X';

	}
	else
	{
		XorO = 'O';
	}
	gameBoard[rows][column] = XorO;
	GameBoard(gameBoard);
}

/**************************************************************
* Entry: from the main
*
* Exit: When it determines it is a vaild input and sends the input 
* to check where to input the x and o
*
* Purpose: To get the input from user and determine if it is a valid
* input or not. 
*
***************************************************************/
void PlayerInput()
{
	if (iPlayerTurn % 2 == 1)
	{
		cout << "Player one, please input the row and column to pick a spot. Ex: # # " << endl;
	}
	else
	{
		cout << "Player two, please input the row and column to pick a spot. Ex: # # " << endl;
	}

	cout << "Please select a location (COL ROW): " << endl;
	int rows = 0, column = 0;
	GetArrayData(rows, column);
	
	if (rows > 2 || rows < 0 || column > 2 || column < 0) 
	{
		cout << "Those numbers won't fit on the board. Please input number between 0 and 2" << endl;
		GetArrayData(rows, column);
	}
	if (iPlayerTurn % 2 == 1 && gameBoard[rows][column] != 'X' && gameBoard[rows][column] != 'O')
	{
		MarkXO(gameBoard,rows,column);
	}
	else if (iPlayerTurn % 2 == 0 && gameBoard[rows][column] != 'X' && gameBoard[rows][column] != 'O')
	{
		MarkXO(gameBoard, rows, column);
	}
	else
	{
		cout << "That spot has been taken. " << endl;
		GetArrayData(rows, column);
	}
}
/**************************************************************
* Entry: gets the current gameBoard
*
* Exit: When it checks the last array 
*
* Purpose: To check if there is a win in the rows
*
***************************************************************/
bool CheckRowWin(char gameBoard[3][3])
{
	Xsum = 0;
	Osum = 0;
	int i;

	for (int j = 0; j < 3; j++)
	{
		Xsum = 0;
		Osum = 0;

		for (int i = 0; i < 3; i++)
		{
			if (gameBoard[i][j] == 'X')
			{
				Xsum++;
			}
			else if (gameBoard[i][j] == 'O')
			{
				Osum++;
			}
		}
		if (gameBoard[0][j] == gameBoard[1][j] && gameBoard[1][j] == gameBoard[2][j] && Xsum == 3)
			{
				return true;
			}
			else if (gameBoard[0][j] == gameBoard[1][j] && gameBoard[1][j]== gameBoard[2][j] && Osum == 3)
			{
				return true;
			}
	}
	return false;
}
/**************************************************************
* Entry: gets the current gameBoard
*
* Exit: When it checks the last array
*
* Purpose: To check if there is a win in the column
*
***************************************************************/
bool CheckColumnWin(char gameBoard[3][3])
{
	Xsum = 0;
	Osum = 0;

	for (int i = 0; i < 3; i++)
	{
		Xsum = 0;
		Osum = 0;

		for (int j = 0; j < 3; j++)
		{
			if (gameBoard[i][j] == 'X')
			{
				Xsum++;
			}
			else if (gameBoard[i][j] == 'O')
			{
				Osum++;
			}
		}
		if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && Xsum == 3)
			{
				return true;
			}
			else if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && Osum == 3)
			{
				return true;
			}
	}
	return false;
}
/**************************************************************
* Entry: gets the current gameBoard
*
* Exit: When it checks the last array
*
* Purpose: To check if there is a win in the diagonals
*
***************************************************************/
bool CheckDiagonalWin(char gameBoard[3][3])
{
	if (gameBoard[0][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][2] =='X' || gameBoard[0][2] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][0] == 'X' 
		|| gameBoard[0][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][2] == 'O' || gameBoard[0][2] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][0] == 'O')
	{
			return true;
	}
	else
	{
		return false;
	}
}
/**************************************************************
* Entry: gets the current gameBoard
*
* Exit: When it checks the last function
*
* Purpose: To check all of the functions.
*
***************************************************************/
bool CheckWin(char gameBoard[3][3])
{
	if (CheckRowWin(gameBoard))
	{
		game_counter++;
		return true;
	}
	else if(CheckColumnWin(gameBoard))
	{
		game_counter++;
		return true;
	}
	else if(CheckDiagonalWin(gameBoard))
	{
		game_counter++;
		return true;
	}
	return false;
}

bool CheckForDraw(char gameBoard[3][3])
{
	if (iPlayerTurn == 9 && CheckWin(gameBoard) == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**************************************************************
* Entry: gets coordinates from the users input
*
* Exit: When it checks the input and if it is valid it will 
* get converted to an int and returned true
*
* Purpose: Split up the input into two different integers
*
***************************************************************/
bool GetArrayData(int& iRow, int& iCol)
{
	string strLine;
	iRow = -1;
	iCol = -1;
	
	cout << "Please enter in the coordinates using spaces.For example, 2 0 " << endl;
	getline(cin, strLine);

	char  delims[] = " ";

	char szNewString[512] = { NULL };
	strcpy(szNewString, strLine.c_str());

	char* rowToken = strtok(szNewString, delims);
	if (rowToken == NULL)
	{
		return false;
	}

	char* columnToken = strtok(NULL, delims);
	if (columnToken == NULL)
	{
		return false;
	}
	if (isdigit(rowToken[0]))		// checking to see if there are any letters
	{
		iRow = atoi(rowToken);
	}
	else
	{
		cout << "Invalid input" << endl;
	}
	if (isdigit(columnToken[0]))
	{
		iCol = atoi(columnToken);
	}
	else
	{
		cout << "Invalid input" << endl;
	}
	return true;
}
/**************************************************************
* Entry: gets the current turn counter
*
* Exit: Gets a new number and returns it
*
* Purpose: Get a player number and determine who is the winner
*
***************************************************************/
int PlayerNumber(int iPlayerTurn)
{
	int numPlayer = 0;

	if (iPlayerTurn % 2 == 1)
	{
		numPlayer = 1;
	}
	else
	{
		numPlayer = 2;
	}
	return numPlayer;
}
