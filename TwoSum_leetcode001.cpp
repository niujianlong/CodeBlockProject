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
#include <unordered_map>
#include <time.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

/*
Time complexity : O(n^2). For each element, we try to find its complement 
by looping through the rest of array which takes O(n)O(n) time. 
Therefore, the time complexity is O(n^2)

Space complexity : O(1). 

*/
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

/*
Complexity Analysis:

Time complexity : O(n). We traverse the list containing nn elements exactly twice. 
Since the hash table reduces the look up time to O(1), the time complexity is O(n).

Space complexity : O(n). The extra space required depends on the number of items stored in the hash table, 
which stores exactly nn elements. 

*/
class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		// hash[i]表示nums中数值为i的下标
		unordered_map<int, int> hash;
		vector<int> result;

		// 一边循环每个数，一边加入hash表。
		for (int i = 0; i < nums.size(); i++) {
			if (hash.find(target - nums[i]) != hash.end()) {
				// target - nums[i]的下标更小，放在前面
				result.push_back(hash[target - nums[i]]);
				result.push_back(i);
				return result;
			}
			hash[nums[i]] = i;
		}

		// 无解的情况
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}
};

class Solution2 {
public:
    int findY(int x, int target){
        if(x == 0) return target;
        if(target == 0) return -x;
        else{
            if(x == target)
                return 0;
            else
                return -x + target;
        }
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> bank;
        int find = 0;
        for(int i = 0; i < nums.size(); i++){
            find = findY(nums[i], target);
            if(bank.find(find) != bank.end()){
                result.push_back(i);
                result.push_back(bank[find]);
            return result;
            }else{
                if(bank.find(nums[i]) == bank.end())
                    bank.insert({nums[i],i});
            }
        }
        return result;
    }
};


/*
Solution mys;
0.003831
Running time is: 0.118ms
result[0] is 1
result[1] is 2

9个元素
0.004282
Running time is: 0.107ms
result[0] is 1
result[1] is 7

Solution1 mys;
0.021745
Running time is: 0.141ms
result[0] is 1
result[1] is 2
9个元素
0.040912
Running time is: 0.142ms
result[0] is 1
result[1] is 7

为什么hash时间更长
以下是50万个元素的测试数据
Solution2 mys;

250.164
Running time is: 252.498ms
result[0] is 499996
result[1] is 499994

Solution1 mys;

226.121
Running time is: 228.478ms
result[0] is 499994
result[1] is 499996
^C
njl@njl-HP:~/Documents/test$ ./a.out 
226.451
Running time is: 229.755ms
result[0] is 499994
result[1] is 499996

Solution mys;
897492 竟然需要大概15分钟
Running time is: 897455ms
result[0] is 499992
result[1] is 499998

*/
int main(int argc, char * * argv)
{
    int test[500000] = {0};

for(int i =0;i<500000;i++)
{
    test[i] = i;
    //cout<<i<<endl;
}
	
	vector<int> result1(2, -1);
	vector<int> nums(test, test + 499999);
	int target = 999990;
	Solution1 mys;
	vector<int> result;
	clock_t start_time = clock();
	high_resolution_clock::time_point t1 = high_resolution_clock::now(); //返回时间戳
	result = mys.twoSum(nums, target);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double, std::milli> time_span = t2 - t1;

	std::cout << time_span.count() << std::endl;
	clock_t end_time = clock();
	cout << "Running time is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;//输出运行时间
	for (int i = 0; i < result.size(); ++i)
	{
		cout << "result[" << i << "] is " << result[i] << endl;
	}
	cin >> target;

}
