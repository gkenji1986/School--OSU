/****************************
* Grant Nakashima
* CS362-400
* 7/6/2016
* Assignment 3
* Unit test for getCost
*****************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void myassert(int val)
{
	if (val)
	{
		printf("PASSED.\n");
	}

	else
	{
		printf("FAILED.\n");
	}

	return;
}

int main(int argc, char** argv)
{

	printf("Checking getCost function... \n");

	int card_array[26];		

	//initialize array with costs of different cards
	printf("Initializing card_array... \n");
	card_array[0] = getCost(curse);
	card_array[1] = getCost(estate);
	card_array[2] = getCost(duchy);
	card_array[3] = getCost(province);
	card_array[4] = getCost(copper);
	card_array[5] = getCost(silver);
	card_array[6] = getCost(gold);
	card_array[7] = getCost(adventurer);
	card_array[8] = getCost(feast);
	card_array[9] = getCost(mine);
	card_array[10] = getCost(baron);
	card_array[11] = getCost(tribute);
	card_array[12] = getCost(ambassador);
	card_array[13] = getCost(sea_hag);
	card_array[14] = getCost(treasure_map);
	card_array[15] = getCost(salvager);
	card_array[16] = getCost(outpost);
	card_array[17] = getCost(embargo);
	card_array[18] = getCost(council_room);
	card_array[19] = getCost(gardens);
	card_array[20] = getCost(remodel);
	card_array[21] = getCost(village);
	card_array[22] = getCost(great_hall);
	card_array[23] = getCost(cutpurse);
	card_array[24] = getCost(smithy);
	card_array[25] = getCost(minion);


	//by brute force check if cost for each card was returned correctly
	printf("Checking card_array...\n");
	myassert(card_array[0] == 0);
	printf("Curse Passed...\n");
	myassert(card_array[1] == 2);
	printf("Estate Passed...\n");
	myassert(card_array[2] == 5);
	printf("Duchy Passed...\n");
	myassert(card_array[3] == 8);
	printf("Province Passed...\n");
	myassert(card_array[4] == 0);
	printf("Copper Passed...\n");
	myassert(card_array[5] == 3);
	printf("Silver Passed...\n");
	myassert(card_array[6] == 6);
	printf("Gold Passed...\n");
	myassert(card_array[7] == 6);
	printf("Adventurer Passed...\n");
	myassert(card_array[8] == 4);		
	printf("Feast Passed...\n");
	myassert(card_array[9] == 5);
	printf("Mine Passed...\n");
	myassert(card_array[10] == 4);
	printf("Baron Passed...\n");
	myassert(card_array[11] == 5);
	printf("Tribute Passed...\n");
	myassert(card_array[12] == 3);
	printf("Ambassador Passed...\n");
	myassert(card_array[13] == 4);
	printf("Sea Hag Passed...\n");
	myassert(card_array[14] == 4);
	printf("Treasure map Passed...\n");
	myassert(card_array[15] == 4);
	printf("Salvager Passed...\n");
	myassert(card_array[16] == 5);
	printf("Outpost Passed...\n");
	myassert(card_array[17] == 2);
	printf("Embargo Passed...\n");
	myassert(card_array[18] == 5);
	printf("Council Room Passed...\n");
	myassert(card_array[19] == 4);
	printf("Gardens Passed...\n");
	myassert(card_array[20] == 4);
	printf("Remodel Passed...\n");
	myassert(card_array[21] == 3);
	printf("VillagePassed...\n");
	myassert(card_array[22] == 3);
	printf("Great Hall Passed...\n");
	myassert(card_array[23] == 4);
	printf("Cutpurse Passed...\n");
	myassert(card_array[24] == 4);
	printf("Smithy Passed...\n");
	myassert(card_array[25] == 5);
	printf("Minion Passed...\n");

	printf("\nCard costs Testing complete. \n\n");

	return 0;




}