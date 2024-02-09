#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums);
void printVector(const vector<int>& nums);

int main() {
	// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
	// Note that you must do this in - place without making a copy of the array.

	// Case 1: No zeroes in container
	vector<int> case1 = { 2, 1 };
	moveZeroes(case1);
	printVector(case1);

	// Case 2: Leading zero
	vector<int> case2 = { 0, 1, 0, 3, 12 };
	moveZeroes(case2);
	printVector(case2);

	// Case 3: Container with one element
	vector<int> case3 = { 0 };
	moveZeroes(case3);
	printVector(case3);

	// Case 4: All zeroes
	vector<int> case4 = { 0, 0, 0, 0 };
	moveZeroes(case4);
	printVector(case4);

	// Case 5: Mixed zeroes and non-zeroes
	vector<int> case5 = { 1, 0, 2, 0, 3, 0, 4 };
	moveZeroes(case5);
	printVector(case5);

	// Case 6: All non-zeroes
	vector<int> case6 = { 5, 1, 3, 7 };
	moveZeroes(case6);
	printVector(case6);

	// Case 7: Zeroes at the end
	vector<int> case7 = { 1, 2, 3, 0, 0 };
	moveZeroes(case7);
	printVector(case7);

	// Case 8: Single non-zero element
	vector<int> case8 = { 1 };
	moveZeroes(case8);
	printVector(case8);

	// Case 9: Zero in the middle
	vector<int> case9 = { 1, 2, 0, 3, 4 };
	moveZeroes(case9);
	printVector(case9);

	// Case 10: Alternating zeroes and non-zeroes
	vector<int> case10 = { 0, 1, 0, 2, 0, 3, 0, 4, 0 };
	moveZeroes(case10);
	printVector(case10);

	return 0;
}

void moveZeroes(vector<int>& nums) {
	// Edge Cases
	int len = nums.size();
	if (len == 0 || len == 1) { return; }

	// Initialize two pointers:
	int left = 0; // Position where the next non-zero value will be placed
	int right = 0; // Position of the next non-zero value

	while (right < len) {
		if (nums[right] != 0) {
			if (right != left) {
				nums[left] = nums[right];
				nums[right] = 0;
			}
			left++;
		}
		++right;
	}
}

void printVector(const vector<int>& nums) {
	if (!nums.empty()) {
		int len = nums.size();
		cout << "[";
		for (int i = 0; i < len; ++i) {
			if (i == 0) {
				cout << nums[i];
			}
			else {
				cout << ", " << nums[i];
			}
		}
		cout << "]\n\n";
	}
}