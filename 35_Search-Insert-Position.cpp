#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int> &nums, int target) {
		int start = 0, end = nums.size() - 1;

		while (start <= end) {
			int mid = (start + end) / 2;

			if (target == nums[mid]) 
				return mid;

			if (target < nums[mid]) {
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}

		return start;
	}
};

int main() {
	int num[] = {1, 3, 5, 6};
	int target = 2;
	int length = sizeof(num) / sizeof(int);
	vector<int> nums(num, num + length);

	Solution solution;
	int searchTarget = solution.searchInsert(nums,  target);
	cout << "The index is " << searchTarget << endl;
}
