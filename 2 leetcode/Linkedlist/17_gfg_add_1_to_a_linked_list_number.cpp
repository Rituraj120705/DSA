/*Add 1 to a Linked List Number



Difficulty: MediumAccuracy: 31.91%Submissions: 362K+Points: 4Average Time: 20m
You are given the head of a linked list where each node contains a single digit. The digits together represent a number formed by concatenating the node values in order. Add 1 to this number and return the head of the modified linked list.

Examples :

Input: Head: 4->5->6
Output: 457

Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 
Input: Head: 1->2->3
Output: 124
 
Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124. 
Constraints:
1 <= len(list) <= 105
0 <= list[i] <= 9

Expected Complexities
Company Tags
Amazon*/


/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;

        while(curr!=NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }


    Node* addOne(Node* head) {
        
         head = reverse(head);
         Node* temp = head;
         int carry = 1;

         while(temp!=NULL){
            temp->data= temp->data + carry;

            if(temp->data < 10){
                carry = 0;
                break;
            }
            else{
                temp->data = 0;
                carry = 1;
            }
            temp = temp->next;
         }
         if(carry == 1){
            Node* newNode = new Node(1);
            head = reverse(head);
            newNode->next = head;
            return newNode;
         }

         head = reverse(head);
         return head;
        
    }
};