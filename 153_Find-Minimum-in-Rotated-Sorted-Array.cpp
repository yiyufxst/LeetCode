#include <iostream>
#include <vector>

using namespace std ;

class Solution {
public:
	int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
        	if (nums[start] < nums[end])
        		return nums[start];

        	int mid = (start + end) / 2;

        	if(nums[mid] < nums[start]) {
        		end = mid;
        	} else {
        		start = mid + 1;
        	}
        }

        return nums[start];
	}
};

int main() {
    Solution solution;
    int num[] = {7, 8, 1, 2, 3, 4, 5, 6};
    int length = sizeof(num) / sizeof(int);
	vector<int> nums(num, num+length);
	int min = solution.findMin(nums);
	cout << "Min:" << min << endl;
	return 0;
}
