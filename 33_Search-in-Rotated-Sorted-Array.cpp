#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int start = 0, end = nums.size() - 1;

		while (start <= end) {
			int mid = (start + end) / 2;

			if (target == nums[mid]) {
				return mid;
			}

			if (nums[mid] < nums[start]) {
				if (target > nums[mid] && target <= nums[end]) {
					start = mid + 1;
				} else {
					end = mid - 1;
				}
			} else {
				if (target >= nums[start] && target < nums[mid]) {
					end = mid - 1;
				} else {
					start = mid + 1;
				}
 			}
		}
        return -1;
	}
};

int main() {
	int num[] = {7, 8, 0, 1, 2, 3, 4, 5, 6};
	int target = 0;
	int length = sizeof(num) / sizeof(int);
	vector<int> nums(num, num + length);

	Solution solution;
	int index = solution.search(nums, target);
	cout << "The index is " << index << endl;
}
