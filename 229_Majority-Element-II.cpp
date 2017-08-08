#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int x = 0, y = 0;
		int countX = 0, countY = 0;
		vector<int> majority;

		for (int i = 0; i < nums.size(); i++) {
			if (x == nums[i]) {
				countX++;
			} else if (y == nums[i]) {
				countY++;
			} else if (countX == 0) {
				x = nums[i];
				countX = 1;
			} else if (countY == 0) {
				y = nums[i];
				countY = 1;
			} else {
				countX--;
				countY--;
			}
		}

		countX = 0, countY = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (x == nums[i]) {
				countX++;
			}
			if (y == nums[i]) {
				countY++;
			}
		}
		if (countX > nums.size() / 3) {
			majority.push_back(x);
		}

		if (x == y) {
			return majority;
		}

		if (countY > nums.size() / 3) {
			majority.push_back(y);
		}

		return majority;
	}
};

int main() {
	int num[] = {1 , 2 , 3};
	int length = sizeof(num) / sizeof(int);
	vector<int> nums(num, num + length);

	Solution solution;
	vector<int> majority;
	majority = solution.majorityElement(nums);
	cout << "The majority elements are ";
	for (int i = 0; i < majority.size(); i++) {
		cout << majority[i] << " ";
	}
}
