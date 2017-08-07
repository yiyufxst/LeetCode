#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int number = 0;

		for (int i = 0; i < 32; i++) {
			int count = 0;
			int temp = 1 << i;

			for (int j = 0; j < nums.size(); j++) {
				if (nums[j] & temp)
					count++;
			}

			if (count % 3)
				number |= temp;
		}
		return number;
	}
};

int main() {
	int num[] = {1, 1, 1, 2, 3, 3, 3};
	int length = sizeof(num) / sizeof(int);
	vector<int> nums(num, num + length);

	Solution solution;
	int number = solution.singleNumber(nums);
	cout << "The single number is " << number << endl;
}
