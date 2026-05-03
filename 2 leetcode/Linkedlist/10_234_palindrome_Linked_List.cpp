234. Palindrome Linked List

Solved
Easy
Topics
premium lock icon
Companies
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       stack<int>s;

        ListNode* temp = head;

        while(temp!=NULL){
            s.push(temp->val);
            temp=temp->next;
        }
        temp = head;
        while(temp!=NULL){
            if(s.top()!=temp->val){
                return false;

            }
            s.pop();
            temp=temp->next;
        }
        return true;
    }
};