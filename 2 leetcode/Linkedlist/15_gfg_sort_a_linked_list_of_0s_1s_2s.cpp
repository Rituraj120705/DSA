/*Sort a linked list of 0s, 1s and 2s

Difficulty: MediumAccuracy: 60.75%Submissions: 293K+Points: 4Average Time: 30m
Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

Examples:

Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
   
Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between. The final list will be:
   
Input: head = 2 → 2 → 0 → 1
   
Output: 0 → 1 → 2 → 2
Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be:
   
Constraints:
1 ≤ no. of nodes ≤ 106
0 ≤ node->data ≤ 2

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
Company Tags
AmazonMicrosoftMakeMyTripNPCI
Topic Tags
Linked ListData Structures
Related Interview Experiences
Makemytrip Interview Experience Set 7 On Campus
Related Articles
Sort Linked List 0s 1s 2s Changing Links*/



/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        Node zeroDummy(-1);
        Node oneDummy(-1);
        Node twoDummy(-1);

        Node * zero = &zeroDummy;
        Node * one = &oneDummy;
        Node * two = &twoDummy;

        Node* temp = head;

        while(temp!=NULL){
            if(temp->data == 0){
                zero->next = temp;
                zero = zero->next;
            }
            else if(temp->data == 1){
                one->next = temp;
                one = one->next;
            }
            else{
                two->next = temp;
                two = two->next;
            }

            temp = temp->next;
        }


        zero->next = (oneDummy.next)? oneDummy.next : twoDummy.next;
        one->next = twoDummy.next;
        two->next = NULL;


        return zeroDummy.next;
        
    }
};