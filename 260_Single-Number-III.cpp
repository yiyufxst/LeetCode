#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
        vector<int> single;
        int xXory = 0;

        for (int i = 0; i < nums.size(); i++) {
        	xXory ^= nums[i];
        }

        int mask = 1;
        for (; (xXory & mask) == 0; mask <<= 1);

        int x = 0, y = 0;
    	for (int i = 0; i < nums.size(); i++) {
    		if (nums[i] & mask) {
    			x ^= nums[i];
    		} else {
    			y ^= nums[i];
    		}
    	}

    	single.push_back(x);
    	single.push_back(y);
    	return single;
    }
};

int main() {
	int num[] = {1, 1, 2, 2, 3, 4, 4, 5};
	int length = sizeof(num) / sizeof(int);
	vector<int> nums(num, num + length);

	Solution solution;
	vector<int> single;
	single = solution.singleNumber(nums);
	cout << "The single numbers are ";
	for (int i = 0; i < single.size(); i++) {
		cout << single[i] << " ";
	}
}
