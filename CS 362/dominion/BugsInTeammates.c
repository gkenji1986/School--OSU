/***********************************
* Name: Grant Nakashima
* Due Date: 7/23/16
* Assignment: Assignment 5
* File name: BugsInTeammates.c
************************************/

*******************
*monoroemaDominion*
*******************
Bug 1: adventurer

Checking status of initalization...
PASSED.
Status of initalization Passed
Checking status of adventurer...
PASSED.
Status of cardEffect Passed...
Check if treasure is 2...
FAILED.
Check if the deck counts is correct...
FAILED.
Check if discard count is correct..
FAILED.
Adventure card test complete.
File 'dominion.c'
Lines executed : 41.40% of 570
Branches executed : 41.01% of 417
Taken at least once : 31.65% of 417
Calls executed : 29.00% of 100
Creating 'dominion.c.gcov'

The bug that occured in adventurer happened with the treasure card count. In the test randomized tests, the hand count for the 
player is one card higher than expected. It appears the cause of the treasure card count being high has to do with the while loop
iterating one more time than it is supposed to do. Since there user has one more card than expected, the deck count and discard count
start to return incorrect counts as well. 

Bug 2: Smithy


Playing Smithy card.
Checking hand count...
handcount: 4 
FAILED.
Checking deck count...
FAILED.
Checking hand cards...
PASSED.
Checking hand cards...
PASSED.
Checking hand cards...
PASSED.
Checking action count...
PASSED.
Smithy card test complete...
File 'dominion.c'
Lines executed:41.05% of 570
Branches executed:41.01% of 417
Taken at least once:31.41% of 417
Calls executed:28.00% of 100
Creating 'dominion.c.gcov'

The bug that occurs in monoroemaDominion has to do with the hand count as well. The player gets one more card than they are supposed to
receiving. In turn, this starts changing other counts as well, like the deck count. In order to fix this the i >= 0; portion in the for loop 
has to iterate one less time. We can change this to i > 0; or i >= 1;.


*****************
*turgileDominion*
*****************
Bug 1: adventurer

Playing Adventurer card.

Checking status of initalization...
PASSED.
Status of initalization Passed
Checking status of adventurer...
PASSED.
Status of cardEffect Passed...
Check if treasure is 2...
FAILED.
Check if the deck counts is correct...
FAILED.
Check if discard count is correct..
FAILED.
Adventure card test complete.
File 'dominion.c'
Lines executed : 41.40% of 570
Branches executed : 41.01% of 417
Taken at least once : 31.65% of 417
Calls executed : 29.00% of 100
Creating 'dominion.c.gcov'


The bug that occured in turgileDominion was the same as in monoroemaDominion. The tests found that the hand count that was
returned would be one hard higher than it is supposed to be. Since the user would have a higher hand count, the other areas like 
deck count or discard count are affected as well. Looking at the treasure count, it is not 2 like it is supposed to be. When we take a look
at the code for adventurer, we find the loop will loop 3 times instead of 2 times. In order to fix this we have to change the loop from i < 3
to i < 2. 

Bug 2 : Smithy

Playing Smithy card.
Checking hand count...
handcount: 4 
FAILED.
Checking deck count...
FAILED.
Checking hand cards...
PASSED.
Checking hand cards...
PASSED.
Checking hand cards...
PASSED.
Checking action count...
PASSED.
Smithy card test complete...
File 'dominion.c'
Lines executed:41.05% of 570
Branches executed:41.01% of 417
Taken at least once:31.41% of 417
Calls executed:28.00% of 100
Creating 'dominion.c.gcov'

The same bug occured in turgileDominion. The hand count is higher than it is supposed to be. In this instance, the hand count the user returns is 4 when it
is supposed to be 3. This means the user is obtaining one more card than they are supposed to be receiving. Taking a look at the code, it becomes apparent where
the error occurs. In the for loop "for (i = 0; i <= 3; i++)", the loop will iterate 4 times instead of 3 times. The fix for this bug is simple, we just need to 
remove the '=' sign and that will return the correct number of cards. 