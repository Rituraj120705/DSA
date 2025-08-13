/*234. Palindrome Linked List
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
 

Follow up: Could you do it in O(n) time and O(1) space?*/
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
            
    ListNode* reverseList(ListNode* head) {
             
        ListNode * curr = head;
        ListNode * prev = NULL;

        while(curr!= NULL){
            ListNode * next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;

        }
       return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next== NULL){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondhalfstart = reverseList(slow);

        ListNode * p1 = head;
        ListNode * p2 = secondhalfstart;
        bool result = true;

        while(p2!=NULL){
            if(p1->val != p2->val){
                return false;
                break;
            }
            p1=p1->next;
            p2=p2->next;
        }
         reverseList(secondhalfstart);
        return result;
    }

};