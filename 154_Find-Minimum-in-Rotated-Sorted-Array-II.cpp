#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
        	if (nums[start] < nums[end]) 
        		break;

        	int mid = (start + end) / 2;
        	if (nums[mid] < nums[start]) {
        		end = mid;
        	} else if (nums[mid] == nums[start]) {
                start++;
        	} else {
        		start = mid + 1;
        	}
        }
        return nums[start];
    }
};

int main() {
	Solution solution;
	int num[] = {3, 3, 3, 3, 3, 0, 1, 2};
	int length = sizeof(num) / sizeof(int);
	vector<int> nums(num, num + length);
	int min = solution.findMin(nums);
	cout << min << " is the smallest in array." << endl;
}
