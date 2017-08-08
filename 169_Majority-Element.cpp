#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int number = 0, count = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (count == 0) {
				number = nums[i];
				count = 1;
			} else if (number == nums[i]) {
				count++;
			} else {
				count--;
			}
		}
		return number;
	}
};

int main() {
	int num[] = {1, 1, 2, 2, 2};
	int length = sizeof(num) / sizeof(int);
	vector<int> nums(num, num + length);

	Solution solution;
	int number = solution.majorityElement(nums);
	cout << "The majority element is " << number << endl;
}
