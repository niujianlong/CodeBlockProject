/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); ++i)
		{
			int temp = target - nums[i];

			for (int k = 0; k < nums.size(); ++k)
			{
				if ((temp == nums[k]) && (k != i))
				{
					//result.push_back(i);
					//result.push_back(k);
					result[0] = i;
					result[1] = k;
					return result;
				}
			}
		}
		return result;
	}
	Solution():result(2,-1)  //类成员对象初始化必须使用初始化列表
	{
		//result.assign(2,-1);
	}
private:
	int a = 1;
	vector<int> result;
};
int main(int argc, char * * argv)
{
	int test[] = { 2, 7, 11, 15 };
	vector<int> result1(2, -1);
	vector<int> nums(test, test + 4);
	int target = 18;
	Solution mys;
	vector<int> result;
	result = mys.twoSum(nums, target);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << "result[" << i << "] is " << result[i] << endl;
	}
	cin >> target;

}
