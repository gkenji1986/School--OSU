#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

//helper functions
int sum_from_to(vector<int> array, int from, int to);
vector<int> rand_arr(int num_nums);
vector<int> rand_arr(int num_nums);


//input/output functions
vector< vector<int> > from_file();
void print_arr(vector<int> array, vector<int> subarray);

//algorithms
vector<int> alg1(vector<int> array);
vector<int> alg2(vector<int> array);
vector<int> alg3(vector<int> nums);
vector<int> alg4(vector<int> nums);


int main() {



	//This section is for testing proof of correctness on the supplied MSS_Problems.txt file. 
	vector< vector<int> > num_arrays = from_file();
	int size = num_arrays.size();
	for (int i = 0; i < size; i++) {
		vector<int> subarray = alg1(num_arrays.at(i));
		print_arr(num_arrays.at(i), subarray);

		subarray = alg2(num_arrays.at(i));
		print_arr(num_arrays.at(i), subarray);

		subarray = alg3(num_arrays.at(i));
		print_arr(num_arrays.at(i), subarray);

		subarray = alg4(num_arrays.at(i));
		print_arr(num_arrays.at(i), subarray);
	}


	//This section is for testing proof of correctness on a random array.
	// vector<int> random = rand_arr(1000);
	// vector<int> subarray = alg1(random);
	// print_arr(random, subarray);

	// subarray = alg2(random);
	// print_arr(random, subarray);

	// subarray = alg3(random);
	// print_arr(random, subarray);

	// subarray = alg4(random);
	// print_arr(random, subarray);

	//This section is for run time analysis -- 
	// int sizes[] = {100, 250, 500, 750, 1000, 1500, 2000, 2500, 3000, 4000, 5000, 5500, 10000, 25000, 50000, 70000, 100000, 120000, 150000, 175000, 200000, 1000000, 10000000, 100000000};

	//  for (int i = 0; i < 25; i++) {
	// 	vector<int> random = rand_arr(sizes[i]);
	// 	 clock_t tStart = clock();
	// 	 vector<int> tmp = alg4(random);
	// 	 double runtime = (double)(clock() - tStart)/CLOCKS_PER_SEC;
	// 	 cout << sizes[i] << ": " << runtime << endl;
	// }

	return 0;
}

vector<int> rand_arr(int num_nums) {

	vector<int> random;
	for (int i = 0; i < num_nums; i++) {
		int neg = (-1) * (rand() % 100);
		int pos = rand() % 100;
		random.push_back(pos + neg);
	}

	return random;
}


vector< vector<int> > from_file() {

	ifstream inputFile;
	inputFile.open("MSS_Problems.txt");

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
		num_arrays.push_back(nums);
	}

	return num_arrays;
}

int sum_from_to(vector<int> array, int from, int to) {
	int sum = 0;

	for (int i = from; i <= to; i++) {
		sum += array[i];
	}
	return sum;
}

void print_arr(vector<int> array, vector<int> subarray) {

	ofstream results;
	results.open("MSS_Results.txt", ofstream::app);

	results << "[";
	int size = array.size();
	for (int i = 0; i < size - 1; i++) {
		results << array.at(i) << ", ";
	}
	results << array.at(size - 1) << "]" << endl;


	results << "[";
	int subSize = subarray.size();
	for (int i = 0; i < subSize - 1; i++) {
		results << subarray.at(i) << ", ";
	}
	results << subarray.at(subSize - 1) << "]" << endl;


	int sum = sum_from_to(subarray, 0, subSize - 1);
	results << sum << endl << endl;

	results.close();

	return;
}

vector<int> alg1(vector<int> array){
	int max_sum;
	int first_index;
	int second_index;

	int size = array.size();

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			int current_sum = sum_from_to(array, i, j);
			if (!max_sum || current_sum > max_sum) {
				max_sum = current_sum;
				first_index = i;
				second_index = j;
			}
		}
	}

	vector<int> maxSub;
	for (int i = first_index; i <= second_index; i++){
		maxSub.push_back(array.at(i));
	}

	return maxSub;
}

vector<int> alg2(vector<int> array){
	int max_sum;
	int first_index;
	int second_index;

	int size = array.size();

	for (int i = 0; i < size; i++) {
		int sum = 0;
		for (int j = i; j < size; j++) {
			sum += array[j];
			if (!max_sum || sum > max_sum) {
				max_sum = sum;
				first_index = i;
				second_index = j;
			}
		}
	}

	vector<int> maxSub;
	for (int i = first_index; i <= second_index; i++){
		maxSub.push_back(array.at(i));
	}

	return maxSub;
}

vector<int> alg4(vector<int> nums) {
	/* algorthm modified from https://en.wikipedia.org/wiki/Maximum_subarray_problem */
	int sum = 0, maxSum = 0, maxStart = 0, start = 0, end = 0;

	int size = nums.size();

	for (int i = 0; i < size; i++){
		if (sum == 0 && nums.at(i) < 0) {
			start = i + 1;
		}
		sum += nums.at(i);

		if (sum > maxSum) {
			end = i;
			maxSum = sum;
			maxStart = start;
		}
		if (sum < 0) {
			start = i + 1;
			sum = 0;
		}
	}

	vector<int> maxSub;
	for (int i = maxStart; i <= end; i++){
		maxSub.push_back(nums.at(i));
	}

	return maxSub;
}

void maxSumWithMid(vector<int> nums, int left, int right, int* total, int* low, int* high)
{
	/* algorthm modified from proof of correctness updated office hours discussion video from OSU CS325  */
	int tempSum = 0;
	int sumLeft = 0;
	int sumRight = 0;
	int mid = (left + right) / 2;

	/*find sum of left half of elements*/
	for (int i = mid; i >= left; i--)
	{
		tempSum += nums.at(i);

		if (tempSum > sumLeft)
		{
			sumLeft = tempSum;
			*low = i;
		}
	}
	tempSum = 0;
	/*find sum of right half of elements*/
	for (int i = mid + 1; i <= right; i++)
	{
		tempSum += nums.at(i);

		if (tempSum > sumRight)
		{
			sumRight = tempSum;
			*high = i;
		}
	}

	*total = sumLeft + sumRight;
}



void helperAlg3(vector<int> nums, int left, int right, int* total, int *leftIndex, int *rightIndex, int* bestTotal, int* bestLIdx, int *bestRIdx)
{
	/* algorthm modified from proof of correctness updated office hours discussion video from OSU CS325  */
	// just in case low and high are the same
	if (left == right)
	{
		*total = nums.at(left);
	}

	// get mid
	else
	{
		int mid = (left + right) / 2;
		int leftLow = 0;
		int leftHigh = 0;
		int leftSum = 0;
		int rightLow = 0;
		int rightHigh = 0;
		int rightSum = 0;
		int midLow = 0;
		int midHigh = 0;
		int midSum = 0;

		helperAlg3(nums, left, mid, &leftSum, &leftLow, &leftHigh, bestTotal, bestLIdx, bestRIdx);
		helperAlg3(nums, mid + 1, right, &rightSum, &rightLow, &rightHigh, bestTotal, bestLIdx, bestRIdx);
		maxSumWithMid(nums, left, right, &midSum, &midLow, &midHigh);

		if (leftSum > rightSum && leftSum > midSum)
		{
			if (leftSum > *bestTotal)
			{
				*total = leftSum;
				*bestTotal = leftSum;
				*bestLIdx = leftLow;
				*bestRIdx = leftHigh;
			}
		}
		else if (rightSum > leftSum && rightSum > midSum)
		{
			if (rightSum > *bestTotal)
			{
				*total = rightSum;
				*bestTotal = rightSum;
				*bestLIdx = rightLow;
				*bestRIdx = rightHigh;
			}
		}
		else if (midSum > rightSum && midSum > leftSum)
		{
			if (midSum > *bestTotal)
			{
				*total = midSum;
				*bestTotal = midSum;
				*bestLIdx = midLow;
				*bestRIdx = midHigh;
			}
		}
	}

	/*return three required cases*/
}

vector <int> alg3(vector<int> nums)
{
	int low = 0;
	int high = nums.size() - 1;
	int total = 0;
	int leftIndex = 0;
	int rightIndex = 0;
	int bestTotal = 0;
	int bestLIdx = 0;
	int bestRIdx = 0;
	vector<int> temp;
	/*return three required cases*/
	helperAlg3(nums, low, high, &total, &leftIndex, &rightIndex, &bestTotal, &bestLIdx, &bestRIdx);

	for (int i = bestLIdx; i <= bestRIdx; i++)
	{
		temp.push_back(nums.at(i));
	}

	return temp;
}