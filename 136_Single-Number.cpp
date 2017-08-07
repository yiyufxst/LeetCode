#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int number = 0;

		for (int i = 0; i < nums.size(); i++) {
			number ^= nums[i];
		}
		return number;
	}
};

int main() {
	int num[] = {1, 1, 2, 2, 3};
	int length = sizeof(num) / sizeof(int);
	vector<int> nums(num, num + length);

	Solution solution;
	int number = solution.singleNumber(nums);
	cout << "The single number is " << number << endl;
}
