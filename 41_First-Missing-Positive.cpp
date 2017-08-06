#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
        int length = nums.size();

		for (int i = 0; i < length;) {
			if (nums[i] == i + 1) {
				i++;
			} else if ((nums[i] <= i) || (nums[i] > length) || (nums[nums[i] - 1] == nums[i])) {
				nums[i] = nums[--length];
			} else {
				swap(nums[i], nums[nums[i] - 1]);
			}
		} 
        return length + 1;
	}
};

int main() {
	int num[] = {3, 4, -1, 1};
	int length = sizeof(num) / sizeof(int);
	vector<int> nums(num, num + length);

	Solution solution;
	int number = solution.firstMissingPositive(nums);
	cout << "The first missing positive integer is " << number << endl;
}
