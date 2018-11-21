#include <QCoreApplication>

#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> subs;
        vector<int> v;
        for(int i=0;i<s.size();++i)
        {
            auto fin = findcha(s[i],subs);
            if(fin==subs.end())//找不到
            {
                subs.push_back(s[i]);
                if(i==s.size()-1)
                {
                    v.push_back(subs.size());
                }

            }
            else//找到
            {
                v.push_back(subs.size());
                subs.erase(subs.begin(),++fin);
                subs.push_back(s[i]);
            }

        }
        if(v.empty())
            return 0;
        else
            return  *std::max_element(v.begin(),v.end());
    }
    vector<char>::iterator findcha(char c,vector<char>& v)
    {
        vector<char>::iterator it = v.begin();
        for(;it!=v.end();++it)
        {
            if(c==*it)
                return it;
        }
        return v.end();

    }
};

int main(int argc, char * * argv)
{
    cout<<Solution().lengthOfLongestSubstring("pwwkew")<<endl;
}

