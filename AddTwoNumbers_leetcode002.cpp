/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/
#include <iostream>
#include <forward_list>
 
std::ostream& operator<<(std::ostream& ostr, const std::forward_list<int>& list)
{
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    typedef  std::forward_list<int> ListNode;
    Solution(ListNode* ln):listSum(ln){}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode::iterator it2 = l2->begin();
        bool isBig = false;
        for(ListNode::iterator it1 = l1->begin();it1!=l1->end();++it1)
            {
        switch(isBig){
            case false:
                if(((*it1+*it2)<10)){
                    listSum->push_front(*it1+*it2);
                    isBig = false;
                }
                else
                    {
                        listSum->push_front(*it1+*it2-10);
                    isBig = true;
                }
                break;
            case true:
                if(((*it1+*it2+1)<10)){
                    listSum->push_front(*it1+*it2+1);
                    isBig = false;
                }
                else
                    {
                        listSum->push_front(*it1+*it2+1-10);
                    isBig = true;
                }
                break;
            default:
            break;

        }
        it2++;
    }
        listSum->reverse();
        return listSum;
    }
private:
    ListNode* listSum;
};

int main()
{
    std::forward_list<int> l1 = { 2,4,3 };
    std::forward_list<int> l2 = { 5,6,4 };
    std::forward_list<int> listSum;
    Solution mys(&listSum);
    mys.addTwoNumbers(&l1, &l2);
    
    std::cout << "before:     " << listSum << "\n";
    //list.sort();
    //std::cout << "ascending:  " << list << "\n";
    //listSum.reverse();
    //std::cout << "descending: " << listSum << "\n";
}
