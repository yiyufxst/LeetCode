#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int start = 0, end = nums.size() - 1;

		while (start <= end) {
			int mid = (start + end) / 2;

			if (target == nums[mid]) {
				return true;
			}

			if (nums[mid] < nums[start]) {
				if (target > nums[mid] && target <= nums[end]) {
					start = mid + 1;
				} else {
					end = mid - 1;
				} 
			} else if (nums[mid] > nums[start]) {
				if (target >= nums[start] && target < nums[mid]) {
					end = mid - 1;
				} else {
					start = mid + 1;
				}
			} else {
				start++;
			}
		}
		return false;
	}
};

int main() {
	int num[] = {4, 4, 4, 4, 4, 0, 1, 2, 3};
	int target = 2;
	int length = sizeof(num) / sizeof(int);
	vector<int> nums(num, num + length);

	Solution solution;
	bool exist = solution.search(nums, target);
	cout << "In the array, whether the target exists:" << exist << endl;
}
