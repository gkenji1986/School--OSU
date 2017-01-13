
//
#include <iostream>
#include <fstream>
#include <time.h>
#include <ctime>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

vector<int> changegreedy(vector<int> coins, int amount);
void InitVector(vector<int>& vtr, int size, int value);
int CountVector(const vector<int>& vtr);
bool changeHelper(vector<int> coins, vector<int>& countVector, int coinsIdx, int coinCount, int amountLeftOver);
int GetCoinCountNum(int coinAmount, int amount);
void SetMinVector(const vector<int>& coins, int amount);
vector<int> changeslow(vector<int> coins, int amount);
vector<int> changedp(vector<int> coins, int amount);
void print_arr(vector<int> array, int amount);
vector< vector<int> > from_file();
void numberfour();
void numberfive();
void numbersix();
vector<int> minVector;
int totalAmount = 0;
int sum_vector(vector<int> arr);
vector<int> changedp(vector<int> denoms, int amount);

vector<int> changeslow(vector<int> curr, int amount)
{
	int size = curr.size();

	totalAmount = amount;

	InitVector(minVector, size, 999);

	SetMinVector(curr, amount);

	return minVector;
}

void SetMinVector(const vector<int>& coins, int amount)
{
	vector<int> coinsReturn;
	vector<int> countVector;

	int coinsSize = coins.size();

	InitVector(countVector, coinsSize, 0);

	//** Loop through and test each coin
	for (int i = coinsSize - 1; i >= 0; i--)
	{
		int coinAmount = coins[i];

		//** Get the number of times a coin can go into an amount. Will try each coinCount
		int coinCountNum = GetCoinCountNum(coinAmount, totalAmount);

		for (int j = coinCountNum; j >= 0; j--)
		{
			InitVector(countVector, coinsSize, 0);
			changeHelper(coins, countVector, i, j, totalAmount);
			if (CountVector(minVector) == 1)
			{
				break;
			}
		}

	}
}

bool changeHelper(vector<int> coins, vector<int>& countVector, int coinsIdx, int coinCount, int amountLeftOver)
{

	//** Process each number of coins that can go into amount Like if amount = 16 and coin is 8 you will have 3 counts (i.e. 0, 1, 2 )
	//** 
	int coinAmount = coins[coinsIdx];
	int newAmount = amountLeftOver - (coinCount*coinAmount);
	countVector[coinsIdx] = coinCount;

	if (0 == newAmount)
	{
		if (CountVector(countVector) < CountVector(minVector))
		{
			minVector = countVector;
		}

		//** we may need to retry this count so just zero out
		countVector[coinsIdx] = 0;

		return true;
	}
	else
	{

		int nextCoinsIdx = coinsIdx - 1;

		if (nextCoinsIdx < 0)
		{
			return true;
		}

		int nextCoinAmount = coins[nextCoinsIdx];
		int nextCoinCountNum = GetCoinCountNum(nextCoinAmount, newAmount);

		for (int i = nextCoinCountNum; i >= 0; i--)
		{
			if (changeHelper(coins, countVector, nextCoinsIdx, nextCoinCountNum, newAmount))
			{
				return true;
			}
		}
	}

	return false;

}

int CountVector(const vector<int>& vtr)
{
	int count = 0;

	for (int i = 0; i< (int)vtr.size(); i++)
	{
		count += vtr[i];
	}

	return count;
}

int GetCoinCountNum(int coinAmount, int amount)
{
	//** This determines how many times a coin can go into a given amount
	
	if (amount < coinAmount)
	{
		return 0;
	}
	else
	{
		return (int)amount / coinAmount;
	}
}

void InitVector(vector<int>& vtr, int size, int value)
{
	vtr.resize(size);
	for (int i = 0; i< (int)vtr.size(); i++)
	{
		vtr[i] = value;
	}
}

vector<int> changegreedy(vector<int> coins, int amount){
	vector<int> numCoins;
	int coinSize = coins.size();

	for (int i = 0; i < coinSize; i++)
	{
		numCoins.push_back(0);
	}
	//base case
	if (amount <= 0)
		return numCoins;

	for (int i = coinSize - 1; i >= 0; i--)
	{
		if (coins.at(i) <= amount)
		{
			if (amount - coins.at(i) >= 0)
			{
				while (amount > 0)
				{
					amount -= coins.at(i);
					numCoins.at(i)++;
				}
				if (amount != 0)
				{
					amount += coins.at(i);
					numCoins.at(i)--;
				}
			}
		}
	}
	return numCoins;
}

void print_arr(vector<int> array, int amount) {

	ofstream results;
	results.open("Amountchange.txt", ofstream::app);

	results << "[";
	int size = array.size() - 1;
	for (int i = 0; i < size; i++) {
		results << array.at(i) << ", ";
	}
	results << array.at(size) << "]" << endl;

	results << amount << endl << endl;

	results.close();

	return;
}

vector<int> changedp(vector<int> denoms, int amount) {

	vector<int> count_arr;
	count_arr.push_back(0);

	vector<int> coins_used;
	coins_used.push_back(0);

	for (int i = 1; i <= amount; i++) {
		int min = count_arr.at(i - 1) + 1;
		int coin;
		for (unsigned int j = 0; j < denoms.size(); j++) {
			if (denoms.at(j) <= i) {
				int num_check = count_arr.at(i - denoms.at(j)) + 1;
				if ((num_check <= min)) {
					min = num_check;
					coin = denoms.at(j);
				}
			}
		}
		count_arr.push_back(min);
		coins_used.push_back(coin);
	}

	vector<int> coin_results;
	int i = coins_used.size() - 1;
	while (i > 0) {
		coin_results.push_back(coins_used.at(i));
		i = i - coins_used.at(i);
	}

	vector<int> denom_results;
	for (unsigned int i = 0; i < denoms.size(); i++) {
		denom_results.push_back(0);
	}

	for (unsigned int j = 0; j < coin_results.size(); j++) {
		for (unsigned int k = 0; k < denoms.size(); k++) {
			if (denoms.at(k) == coin_results.at(j)) {
				denom_results.at(k) += 1;
			}
		}
	}

	return denom_results;

}

int sum_vector(vector<int> arr) {

	int sum = 0;
	for (unsigned int i = 0; i < arr.size(); i++) {
		sum += arr.at(i);
	}
	return sum;
}

vector< vector<int> > from_file() {

	ifstream inputFile;
	inputFile.open("coin.txt");

	vector<string> input;
	string line;

	vector< vector<int> > num_arrays;

	while (getline(inputFile, line)){
		input.push_back(line);
	}
	int size = input.size();
	//loop through each array line
	for (int i = 0; i < size; i++) {
		vector<int> nums;

		//loop through chars in the string
		line = input.at(i);
		string num = "";
		int lineL = line.length();
		for (int j = 0; j < lineL; j++) {
			char curr = line.at(j);
			if (curr != '[' && curr != ' ') {
				if (curr == ',' || curr == ']') {
					nums.push_back(atoi(num.c_str()));
					num = "";
				}
				else {
					num += curr;
				}
			}
		}
		if (atoi(num.c_str()) > 0)
		{
			nums.push_back(atoi(num.c_str()));
		}
		num_arrays.push_back(nums);
	}

	return num_arrays;
}

void numberfour(){

	vector<int> coins;
	coins.push_back(1);
	coins.push_back(5);
	coins.push_back(10);
	coins.push_back(25);
	coins.push_back(50);

	for (int i = 2010; i <= 2200; i += 5){
		//clock the time
		clock_t slw = clock();
		vector<int> slow = changeslow(coins, i);

		//get the total number of coins
		int totalCoins = 0;
		int slowSize = slow.size();

		for (int j = 0; j < slowSize; j++)
		{
			totalCoins += slow.at(j);
		}

		slw = clock() - slw;

		//get the runtime
		double runtime = (double)(slw / (CLOCKS_PER_SEC / 1000));

		//print to an output file to make the data easier to analyze
		ofstream ex4SlowTime;
		ex4SlowTime.open("ex4SlowTime.txt", ofstream::app);
		ex4SlowTime << "Run time: " << runtime << endl;

		ofstream ex4SlowCoins;
		ex4SlowCoins.open("ex4SlowCoins.txt", ofstream::app);
		ex4SlowCoins << totalCoins << endl;

		ofstream numSlow;
		numSlow.open("ex4Slownum.txt", ofstream::app);
		numSlow << i << endl;

		//print the result to the screen
		cout << "Slow: when A = " << i << " num coins = " << totalCoins << " in " << runtime << " milliseconds." << endl;

		//clock the time 
		clock_t grdy = clock();
		vector<int> greedy = changegreedy(coins, i);
		
		//get the total number of coins
		totalCoins = 0;
		int greedySize = greedy.size();
		for (int j = 0; j < greedySize; j++)
		{
			totalCoins += greedy.at(j);
		}
		grdy = clock() - grdy;

		//get the runtime
		runtime = (double)(grdy / (CLOCKS_PER_SEC / 1000));

		//print to an output file to make the data easier to analyze 
		ofstream ex4GreedyTime;
		ex4GreedyTime.open("ex4GreedyTime.txt", ofstream::app);
		ex4GreedyTime << "Run time: " << runtime << endl;

		ofstream ex4GreedyCoins;
		ex4GreedyCoins.open("ex4GreedyCoins.txt", ofstream::app);
		ex4GreedyCoins << totalCoins << endl;


		ofstream numGreedy;
		numGreedy.open("ex4Greedynum.txt", ofstream::app);
		numGreedy << i << endl;

		//print the results to the screen
		cout << "Greedy: when A = " << i << " num coins = " << totalCoins << " in " << runtime << " milliseconds." << endl;


		//clock the time
		clock_t dpTime = clock();
		vector<int> dp = changedp(coins, i);
		
		totalCoins = 0;

		int dpSize = dp.size();
		for (int j = 0; j < dpSize; j++)
		{
			totalCoins += dp.at(j);
		}
		dpTime = clock() - dpTime;

		//get the runtime
		runtime = (double)(dpTime / (CLOCKS_PER_SEC / 1000));

		//print to an output file to make the data easier to analyze
		ofstream ex4DPTime;
		ex4DPTime.open("ex4DPTime.txt", ofstream::app);
		ex4DPTime << "Run time: " << runtime << endl;

		ofstream ex4DPCoins;
		ex4DPCoins.open("ex4DPCoins.txt", ofstream::app);
		ex4DPCoins << totalCoins << endl;

		ofstream numDP;
		numDP.open("ex4DPnum.txt", ofstream::app);
		numDP << i << endl;

		cout << "Dynamic: when A = " << i << " num coins = " << totalCoins << " in " << runtime << " milliseconds." << endl << endl;

	}
}

void numberfive(){

	vector<int> coins1;
	coins1.push_back(1);
	coins1.push_back(2);
	coins1.push_back(6);
	coins1.push_back(12);
	coins1.push_back(24);
	coins1.push_back(48);
	coins1.push_back(60);

	vector<int> coins2;
	coins2.push_back(1);
	coins2.push_back(6);
	coins2.push_back(13);
	coins2.push_back(37);
	coins2.push_back(150);

	for (int i = 2000; i <= 2200; i++){
		clock_t slow1Time = clock();
		vector<int> slow1 = changeslow(coins1, i);
		

		ofstream num5;
		num5.open("num5.txt", ofstream::app);
		num5 << i << endl;

		int totalCoins1 = 0;
		int slow1Size = slow1.size();
		for (int j = 0; j < slow1Size; j++)
		{
			totalCoins1 += slow1.at(j);
		}
		slow1Time = clock() - slow1Time;
		double runtime = (double)(slow1Time / (CLOCKS_PER_SEC / 1000));

		ofstream ex5Slow1Time;
		ex5Slow1Time.open("ex5Slow1Time.txt", ofstream::app);
		ex5Slow1Time << "Run time: " << runtime << endl;

		ofstream ex5Slow1Coins;
		ex5Slow1Coins.open("ex5Slow1Coins.txt", ofstream::app);
		ex5Slow1Coins << totalCoins1 << endl;

		cout << "Slow: on V1, when A = " << i << " num coins = " << totalCoins1 << endl;

		clock_t slow2Time = clock();
		vector<int> slow2 = changeslow(coins2, i);
		

		int totalCoins2 = 0;
		int slow2Size = slow2.size();
		for (int j = 0; j < slow2Size; j++)
		{
			totalCoins2 += slow2.at(j);
		}
		slow2Time = clock() - slow2Time;
		runtime = (double)(slow2Time / (CLOCKS_PER_SEC / 1000));

		ofstream ex5Slow2Time;
		ex5Slow2Time.open("ex5Slow2Time.txt", ofstream::app);
		ex5Slow2Time << "Run time: " << runtime << endl;

		ofstream ex5Slow2Coins;
		ex5Slow2Coins.open("ex5Slow2Coins.txt", ofstream::app);
		ex5Slow2Coins << totalCoins2 << endl;

		cout << "Slow: on V2, when A = " << i << " num coins = " << totalCoins2 << endl;

		clock_t greedy1Time = clock();
		vector<int> greedy1 = changegreedy(coins1, i);
	
		totalCoins1 = 0;
		int greedy1Size = greedy1.size();

		for (int j = 0; j < greedy1Size; j++)
		{
			totalCoins1 += greedy1.at(j);
		}
		greedy1Time = clock() - greedy1Time;
		runtime = (double)(greedy1Time / (CLOCKS_PER_SEC / 1000));

		ofstream ex5Greedy1Time;
		ex5Greedy1Time.open("ex5Greedy1Time.txt", ofstream::app);
		ex5Greedy1Time << "Run time: " << runtime << endl;

		ofstream ex5Greedy1Coins;
		ex5Greedy1Coins.open("ex5Greedy1Coins.txt", ofstream::app);
		ex5Greedy1Coins << totalCoins1 << endl;

		cout << "Greedy: on V1, when A = " << i << " num coins = " << totalCoins1 << endl;

		clock_t greedy2Time = clock();
		vector<int> greedy2 = changegreedy(coins2, i);

		totalCoins2 = 0;
		int greedy2Size = greedy2.size();
		for (int j = 0; j < greedy2Size; j++)
		{
			totalCoins2 += greedy2.at(j);
		}
		greedy2Time = clock() - greedy2Time;
		runtime = (double)(greedy2Time / (CLOCKS_PER_SEC / 1000));

		ofstream ex5Greedy2Time;
		ex5Greedy2Time.open("ex5Greedy2Time.txt", ofstream::app);
		ex5Greedy2Time << "Run time: " << runtime << endl;

		ofstream ex5Greedy2Coins;
		ex5Greedy2Coins.open("ex5Greedy2Coins.txt", ofstream::app);
		ex5Greedy2Coins << totalCoins2 << endl;

		cout << "Greedy: on V2, when A = " << i << " num coins = " << totalCoins2 << endl;

		clock_t dp1Time = clock();
		vector<int> dp1 = changedp(coins1, i);
	
		totalCoins1 = 0;
		int dp1Size = dp1.size();
		for (int j = 0; j < dp1Size; j++)
		{
			totalCoins1 += dp1.at(j);
		}
		dp1Time = clock() - dp1Time;
		runtime = (double)(dp1Time / (CLOCKS_PER_SEC / 1000));

		ofstream ex5Dp1Time;
		ex5Dp1Time.open("ex5Dp1Time.txt", ofstream::app);
		ex5Dp1Time << "Run time: " << runtime << endl;

		ofstream ex5DP1Coins;
		ex5DP1Coins.open("ex5DP1Coins.txt", ofstream::app);
		ex5DP1Coins << totalCoins1 << endl;

		cout << "Dynamic: on V1 when A = " << i << " num coins = " << totalCoins1 << endl;

		clock_t dp2Time = clock();
		vector<int> dp2 = changedp(coins2, i);
	
		totalCoins2 = 0;
		int dp2Size = dp2.size();
		for (int j = 0; j < dp2Size; j++)
		{
			totalCoins2 += dp2.at(j);
		}
		dp2Time = clock() - dp2Time;
		runtime = (double)(dp2Time / (CLOCKS_PER_SEC / 1000));

		ofstream ex5Dp2Time;
		ex5Dp2Time.open("ex5Dp2Time.txt", ofstream::app);
		ex5Dp2Time << "Run time: " << runtime << endl;

		ofstream ex5DP2Coins;
		ex5DP2Coins.open("ex5DP2Coins.txt", ofstream::app);
		ex5DP2Coins << totalCoins2 << endl;

		cout << "Dynamic: on V2 when A = " << i << " num coins = " << totalCoins2 << endl << endl;

	}
}

void numbersix(){
	vector<int> coins;
	coins.push_back(1);
	for (int i = 1; i <= 15; i++)
		coins.push_back(2 * i);

	for (int i = 2000; i <= 2200; i++){

		clock_t slw = clock();
		vector<int> slow = changeslow(coins, i);

		int totalCoins = 0;
		int slowSize = slow.size();

		ofstream num6;
		num6.open("exnum9.txt", ofstream::app);
		num6 << i << endl;

		for (int j = 0; j < slowSize; j++)
		{
			totalCoins += slow.at(j);
		}
		slw = clock() - slw;
		double runtime = (double)(slw / (CLOCKS_PER_SEC / 1000));
		
		ofstream ex6SlowTime;
		ex6SlowTime.open("ex6SlowTime.txt", ofstream::app);
		ex6SlowTime << runtime << endl;

		ofstream ex6SlowCoins;
		ex6SlowCoins.open("ex6SlowCoins.txt", ofstream::app);
		ex6SlowCoins << totalCoins << endl;

		cout << "Slow: when A = " << i << " num coins = " << totalCoins << " in " << runtime << " milliseconds." << endl;

		clock_t grdy = clock();
		vector<int> greedy = changegreedy(coins, i);
	
		totalCoins = 0;
		int greedySize = greedy.size();
		for (int j = 0; j < greedySize; j++)
		{
			totalCoins += greedy.at(j);
		}
		grdy = clock() - grdy;
		runtime = (double)(grdy / (CLOCKS_PER_SEC / 1000));

		ofstream ex6GreedyTime;
		ex6GreedyTime.open("ex9GreedyTime.txt", ofstream::app);
		ex6GreedyTime << runtime << endl;

		ofstream ex6GreedyCoins;
		ex6GreedyCoins.open("ex9GreedyCoins.txt", ofstream::app);
		ex6GreedyCoins << totalCoins << endl;

		cout << "Greedy: when A = " << i << " num coins = " << totalCoins << " in " << runtime << " milliseconds." << endl;

		clock_t dpTime = clock();
		vector<int> dp = changedp(coins, i);

		totalCoins = 0;
		int dpSize = dp.size();
		for (int j = 0; j < dpSize; j++)
		{
			totalCoins += dp.at(j);
		}
		ofstream ex6DPOut;

		dpTime = clock() - dpTime;
		runtime = (double)(dpTime /(CLOCKS_PER_SEC / 1000));
		ofstream ex6DPTime;
		ex6DPTime.open("ex9DPTime.txt", ofstream::app);
		ex6DPTime << runtime << endl;

		ofstream ex6DPCoins;
		ex6DPCoins.open("ex9DPCoins.txt", ofstream::app);
		ex6DPCoins << totalCoins << endl;

		cout << "Dynamic: when A = " << i << " num coins = " << totalCoins << " in " << runtime << " milliseconds." << endl << endl;

	}
}


int main(){
	
	vector< vector <int> > num_arrays = from_file();

	int numArraySize = num_arrays.size();

	for (int i = 0; i < numArraySize; i += 2){
		vector<int> curr = num_arrays.at(i);
		vector<int> temp = num_arrays.at(i+1);
		int amount = temp.at(0);
		

		vector<int> slow = changeslow(curr, amount);
		int numCoins = 0;
		int slowSize = slow.size();
		for (int j = 0; j < slowSize; j++)
			numCoins += slow.at(j);
		print_arr(slow, numCoins);

		vector<int> greedy = changegreedy(curr, amount);
		numCoins = 0;
		int greedySize = greedy.size();
		for (int j = 0; j < greedySize; j++)
			numCoins += greedy.at(j);
		print_arr(greedy, numCoins);

		vector<int> dp = changedp(curr, amount);
		numCoins = 0;
		int dpSize = dp.size();
		for (int j = 0; j < dpSize; j++)
			numCoins += dp.at(j);
		print_arr(dp, numCoins);

	}

	numberfour();
	numberfive();
	numbersix();

	return 0;
}
