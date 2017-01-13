/**************************************************************************
* Name: Grant Nakashima
* Filename: nakashig.adventure.c
* Date Due: 02/08/16
* Description:  This assignment has us create a simple text adventure game
* 		that generates a number of random rooms from a pool of rooms.
* 		It will create connections between the rooms at random. The 
* 		player will use inputs to move around and track where they are.
* 		The game will end when the player makes it to the last room. 
***************************************************************************/

#include <sys/types.h>			//for pid_t
#include <sys/stat.h>			//for stat
#include <stdio.h>			//for fopen,fclsoe
#include <stdlib.h>			//for rand and srand
#include <string.h>			//for strcpy
#include <unistd.h>			//for getpid
#include <time.h>			//for time
#include <dirent.h>
#include <stddef.h>
#include <fcntl.h>     // for open

#define ROOM_NUM	7
#define MAX_ROOMS	10
#define MIN_CONNECT	3
#define MAX_CONNECT	6

struct Room
{
	char name[20];					//name of room
	char type[20];					//tells if the room is start, mid or end
	int connection[MAX_CONNECT];	//array for room id
	int connect_num;				//total number of connections
	int room_id;					//id for room
};

/*******************
* Function Prototype
********************/
void createDirectory(int proID, char *directoryName);	//creates directory 
void createRoomFiles(struct Room rooms[ROOM_NUM]);
void connectRooms(struct Room rooms[ROOM_NUM]);
void completeRoomsConnection(struct Room rooms[ROOM_NUM]);
void create_file(struct Room rooms[ROOM_NUM]);
void read_file(struct Room rooms[ROOM_NUM], char *dir_name);
void game(struct Room rooms[ROOM_NUM]);
void show_room(int current_room, struct Room rooms[ROOM_NUM]);
void check_input(int current_room, struct Room rooms[ROOM_NUM], char user_path[100][20], int user_moves);
void check_gameover(int current_room, int end_room, int finish, int user_moves, char user_path[100][20]);

int main()
{
	srand(time(NULL));					//initialize to get random numbers
	struct Room rooms[ROOM_NUM];		//struct of 7 rooms
	int proID = getpid();				//processID

	char roomDirectory[50];				//array for directory

	createDirectory(proID, roomDirectory);	//create directory
	createRoomFiles(rooms);						//create files that will be put into directory
	read_file(rooms, roomDirectory);		// ready the files
	game(rooms);							//run game

	return 0; 
}
/**************************************
 * Reference: http://cboard.cprogramming.com/c-programming/165757-using-process-id-name-file-directory.html
 * Reference: http://stackoverflow.com/questions/7430248/creating-a-new-directory-in-c
 **************************************/
void createDirectory(int proID, char *directoryName)
{
	sprintf(directoryName, "nakashig.rooms.%d", proID);		//create name for directory
	struct stat st = {0};

	if(stat(directoryName, &st) == -1)
	{
		mkdir(directoryName, 0755);
	}
	chdir(directoryName);
}

/**************************************
* Reference: http://stackoverflow.com/questions/16565288/using-strcmp-in-an-if-statement
* Reference: http://cboard.cprogramming.com/game-programming/93989-help-my-text-adventure-game.html
* Reference: http://stackoverflow.com/questions/1176737/strncpy-and-using-sizeof-to-copy-maximum-characters
**************************************/
void createRoomFiles(struct Room rooms[ROOM_NUM])
{	
	char pick_room_name[ROOM_NUM][20];	//array to hold names from room
	char picked_name[20];				//name that is taken from room
	int temp_bool;						//bool for checking names
	int i = 0;

	char *room[MAX_ROOMS];			//set names for rooms
	room[0] = "Seattle"; 
	room[1] = "Portland"; 
	room[2] = "San Francisco";
	room[3] = "Los Angeles";
	room[4] = "Las Vegas";
	room[5] = "Boston";
	room[6] = "New York";
	room[7] = "Chicago";
	room[8] = "Dallas";
	room[9] = "Phoenix";

	while (i < ROOM_NUM)				//loop to create all 7 rooms
	{
		temp_bool = 1;

		while(temp_bool != 0)
		{
			int random = rand() % MAX_ROOMS;	//used to pick random name for rooms. tried a function but didnt work

			strncpy(picked_name, room[random], 30);		//copy name to temp name
			temp_bool = 0;								//set bool to false
			int k = 0;

			while (k != ROOM_NUM)					//loop to check if name has been used 
			{
				if(strcmp(pick_room_name[k], picked_name) == 0)		//compare names
				{
					temp_bool = 1;		//change to true if name has been used
				}
				k++;
			}

			if(temp_bool == 0)			//if name is not used
			{
				strncpy(pick_room_name[i],picked_name, 25);
				strncpy(rooms[i].name, picked_name, 25);
				strncpy(rooms[i].type, "MID_ROOM", 25);
				rooms[i].connect_num = 3;
				rooms[i].room_id = i;
			}	
		}
		i++;
	}
		
	int start = rand() % 7;			//create starting point
	strncpy(rooms[start].type, "START_ROOM", 25);	//add starting room
	
	temp_bool = 0;

	while(temp_bool != 1)		//loop until random number for start and end are not equal
	{
		int end = rand() % 7;

		if(start != end)			//make any room end room if number end isnt equal to start
		{
			strncpy(rooms[end].type, "END_ROOM", 25);		//change room type to end
			temp_bool = 1;
		}
	}
	connectRooms(rooms);
}

/**************************************
* Reference: http://stackoverflow.com/questions/30067436/connect-rooms-randomly-in-adventure-game
* Reference: http://stackoverflow.com/questions/33459226/text-adventure-game-randomly-connecting-rooms-together-c?lq=1
* Reference: http://stackoverflow.com/questions/1176737/strncpy-and-using-sizeof-to-copy-maximum-characters
**************************************/
void connectRooms(struct Room rooms[ROOM_NUM])			//break connection of rooms into two parts
{
	int i = 0;

	while (i != ROOM_NUM)
	{
		int room_index = 0;
		int temp_room[ROOM_NUM];			//create temp array for rooms
		rooms[i].connect_num = MIN_CONNECT;		//set total connections to minimum assignment requires
		int j;

		for(j = 0; j < ROOM_NUM; j++)		//initialize array
		{
			temp_room[j] = 8;	
		} 

		temp_room[room_index] = i;			//set number for room
		room_index++;
		int k = 0;

		while (k != rooms[i].connect_num)		//loop for number of connections
		{
			int room_checker = 0;
			
			while(room_checker != 1)			//loop to add connections		
			{
				int rand_room = rand() % 7;		//create random number to use for picking random room
				int dup = 0;
				int l = 0;

				while(l != 7)					//loop to check for duplicate connections
				{
					if(rand_room == temp_room[l])
					{
						dup = 1;
					}
					l++;
				}
				
				if(dup != 1)			//add room to connection if there are no duplicates
				{	
					rooms[i].connection[k] = rand_room;		//add room to connection array
					temp_room[room_index] = rand_room;		//add room to temp array to check keep track for duplicates
					room_index++;							//increment to get next room
					room_checker = 1;						//change to true to break loop
				}
			}
			k++;
		}
		i++;
	}
	completeRoomsConnection(rooms);			//second part of connecting rooms
}

void completeRoomsConnection(struct Room rooms[ROOM_NUM])
{
	int loop_num = 0;

	while (loop_num != ROOM_NUM)		//loop to create connections for both file
	{
		int temp_bool = 0;
		int i;

		for (i = 0; i < rooms[loop_num].connect_num; i++)	//loop for number of connections in specific room to 
		{
			int index = rooms[loop_num].connection[i];		//get connected room that will get checked
			int j;

			for (j = 0; j < rooms[index].connect_num; j++)		//check if room is connected
			{
				if (rooms[index].connection[j] == rooms[loop_num].room_id)		// check if current room number connection number has the same id to see if there is a connection
				{
					temp_bool = 1;		// change to true if there is a two way connection created
				}
			}
			if (temp_bool == 0)		//if there is no connection add connections
			{
				int connect_index = rooms[index].connect_num;			//get the index where the connection needs to get connected
				rooms[index].connection[connect_index] = loop_num;		//add room number to connection location
				rooms[index].connect_num++;								// increase the total connection number 
			}
		}
		loop_num++;
	}
	create_file(rooms);		//make the files once all rooms are connected together both ways. 
}
/**************************************
* Reference: http://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
* Reference: http://stackoverflow.com/questions/9840629/create-a-file-if-one-doesnt-exist-c
* Reference: http://stackoverflow.com/questions/2018730/fprintf-with-string-argument
**************************************/
void create_file(struct Room rooms[ROOM_NUM])
{
	FILE *file;
	
	int temp = 0;

	while(temp != ROOM_NUM)		//loop for the number of rooms that will be created for the game
	{
		char file_name[20];
		strncpy(file_name, rooms[temp].name, 20);				//get room name and copy it to temp file name
		file = fopen(file_name, "w");							//make file and name file with room name
		fprintf(file, "ROOM NAME: %s\n", rooms[temp].name);		//copy room name in file

		int i = 1;
		int j;

		for (j = 0; j < rooms[temp].connect_num; j++)		//find connections and print to file
		{
			fprintf(file, "CONNECTION %d: ", i);
			fprintf(file, "%s\n", rooms[rooms[temp].connection[j]].name);	//copy connection name to file. loop to get all connections
			i++;
		}

		fprintf(file, "ROOM TYPE: %s\n", rooms[temp].type);		//copy room type to file
		fclose(file);											//close file to prevent errors
		temp++;
	}
}

/******************
* Reference: http://stackoverflow.com/questions/19365109/using-o-rdwr-vs-o-rdonly-o-wronly
* Reference: http://stackoverflow.com/questions/8056146/breaking-down-string-and-storing-it-in-array
* Reference: http://stackoverflow.com/questions/18183633/string-parsing-in-c-using-strtok
* Reference: http://stackoverflow.com/questions/3270822/strcat-problem-with-char-a10
* Reference: http://stackoverflow.com/questions/2550774/what-is-size-t-in-c
* Reference: http://stackoverflow.com/questions/22059189/read-a-file-as-byte-array
* Reference: http://stackoverflow.com/questions/15798450/open-with-o-creat-was-it-opened-or-created
* Reference: http://cboard.cprogramming.com/c-programming/4198-reading-files-token-token.html
******************/
void read_file(struct Room rooms[ROOM_NUM], char *dir_name)
{
	int index = 0;							//index to keep track of rooms
	char *data;								//char pointer to keep track of the token names
	char file[40];							//file 
	int i = 0;								//loop
	char buffer[512];						//buffer need for data
	ssize_t numArray[ROOM_NUM];				// arrays for keeping track of I/O operations. using an int array will cause the program to freeze
	int connectionsLeft = 0;

	for (i = 0; i < MAX_ROOMS; i++)
	{
		strcpy(file, dir_name);
		strcat(file, "/");
		strcat(file, rooms[i].name);	//create file with proper name

		int file_descriptor = open(file, O_RDONLY);		//check if file creation occured

		if (file_descriptor < 0)	//check if error occurs
		{
			continue;
		}

		numArray[index] = read(file_descriptor, buffer, 512);			//read file

		data = strtok(buffer, " ");
		data = strtok(NULL, " ");
		data = strtok(NULL, "\n");		//parse file

		strcpy(rooms[index].name, data);		// copy name to room from token

		rooms[index].connect_num = 0;
		connectionsLeft = 1;			//true
		int j = 0;

		while (connectionsLeft != 0)
		{	
			data = strtok(NULL, " ");			// parse the buffer

			if (strcmp(data, "CONNECTION") != 0)		// check to make sure this is data for a connection
			{
				connectionsLeft = 0;		//will exit if no more connections
				continue;
			}

			data = strtok(NULL, " ");
			data = strtok(NULL, "\n");			// parse data

			strcpy(rooms[rooms[index].connection[j]].name, data);			//copy string to current rooms name in struct
			
			rooms[index].connect_num++;
			j++;						// increment the counters for connection number and room connection number tracker
		} 

		data = strtok(NULL, " ");
		data = strtok(NULL, "\n");	// parse data for room type

		strcpy(rooms[index].type, data);		// copy data for room type to struct for current room
	
		index++;		// increment current rooom index
	}
}

/**************************************
* Reference: http://stackoverflow.com/questions/9278226/which-is-the-best-way-to-get-input-from-user-in-c
* Reference: http://stackoverflow.com/questions/4023895/how-to-read-string-entered-by-user-in-c
* Reference: http://stackoverflow.com/questions/7831755/what-is-the-simplest-way-of-getting-user-input-in-c
* Reference: http://stackoverflow.com/questions/21439059/c-fgets-skips-user-input
* Reference: http://stackoverflow.com/questions/1472537/c-trimming-newline-character-when-reading-input-from-file
* Reference: http://www.codingunit.com/c-reference-string-h-string-operation-strchr
* Reference: http://www.cplusplus.com/reference/cstring/strchr/
* Reference: http://www.java2s.com/Code/C/Console/Usefgetstoreadstringfromstandardinput.htm
**************************************/
void game(struct Room rooms[ROOM_NUM])
{
	printf("Grant's Adventure Maze\n");
	printf("\n");

	int start_room = 0;		//create start room indicator
	int end_room = 0;		//create end room indicator
	int i = 0;

	while (i != ROOM_NUM)		// loop to find where the start and end are
	{
		if (strcmp(rooms[i].type, "START_ROOM") == 0)
		{
			start_room = i;		//when 
		}
		if (strcmp(rooms[i].type, "END_ROOM") == 0)
		{
			end_room = i;
		}
		i++;
	}

	int current_room = start_room;		//current room will be the index to keep track of where the user is 
	int user_moves = 0;					//track number of moves a user does
	char user_path[100][20];			//char array to hold where the user went

	int finish = 0;

	while (finish != 1)					// game loop that will break when end room has been reached
	{
		show_room(current_room, rooms);		//print the files and where the user currently is

		char user_input[256];				//char array to get users input

		if (fgets(user_input, sizeof(user_input), stdin))		//get user input
		{
			char *position;
			position = strchr(user_input, '\n');

			if (position != NULL)
			{
				*position = '\0';
			}

			int input_check = 0;		// int to check if input good.
			int j;

			for (j = 0; j < rooms[current_room].connect_num; j++)		//create loop to compare input with room connection names
			{
				if (strcmp(user_input, rooms[rooms[current_room].connection[j]].name) == 0)
				{
					input_check = 1;		// chance to true for valid input
					current_room = rooms[current_room].connection[j];				//change current room number
					strncpy(user_path[user_moves], rooms[current_room].name, 20);	//add room name to path array
					user_moves++;	//increment move number indicator
					break;
				}
			}

			if (input_check == 0)
			{
				printf("\n That is not a valid input. Try again. \n");
			}

			if (current_room == end_room)		//check if the current room and end room number are the same
			{
				printf("\n You have reached the end. Congratulations.\n");
				printf("\n You took %d steps.\n", user_moves);				//print number of user moves
				int i;
				for (i = 0; i < user_moves; i++)						// print the array user_path
				{
					printf("%s\n", user_path[i]);
				}
				finish = 1;			// change finish to 1 to exit game
			}
		}
		printf("\n");
	}
}

void show_room(int current_room, struct Room rooms[ROOM_NUM])
{

		printf("CURRENT LOCATION: %s\n", rooms[current_room].name);		
		printf("POSSIBLE CONNECTIONS: ");
		int i;

		for (i = 0; i < rooms[current_room].connect_num; i++)		//loop to the number of connections
		{
				
			if (i == rooms[current_room].connect_num - 1)		//print connections
			{
				printf("%s.\n", rooms[rooms[current_room].connection[i]].name);
			}
			else
			{
				printf("%s, ", rooms[rooms[current_room].connection[i]].name);
			}
		}

	printf("\n");
	printf("WHERE TO?>");
}
