Linked List Insertion At Beginning


Difficulty: EasyAccuracy: 67.99%Submissions: 22K+Points: 2
You are given the head of a Singly Linked List and a value x, insert that value x at the beginning of the LinkedList and return the head of the modified Linked List.

Examples :

Input: x = 1,
    
Output: 1 -> 2 -> 10
Explanation: We can see that 1 is inserted at the beginning of the linked list.
    
Input: x = 1,
    
Output: 1 -> 2 -> 3 -> 4 -> 5
Explanation: We can see that 1 is inserted at the beginning of the linked list.
       
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data, x ≤ 103





/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node *insertAtFront(Node *head, int x) {
        
        Node* newNode = new Node(x);

        newNode -> next = head;

        head = newNode;

        return head;
        
    }
};