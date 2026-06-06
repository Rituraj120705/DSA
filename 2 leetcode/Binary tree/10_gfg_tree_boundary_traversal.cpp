Tree Boundary Traversal


Difficulty: MediumAccuracy: 23.33%Submissions: 555K+Points: 4Average Time: 35m
Given a root of a Binary Tree, return its boundary traversal in the following order:

Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.

Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.

Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and added in reverse order.

Note: The root is included once, leaves are added separately to avoid repetition, and the right boundary follows traversal preference not the path from the rightmost leaf.

Examples:

Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
Output: [1, 2, 4, 8, 9, 6, 7, 3]
Explanation:

Input: root = [1, N, 2, N, 3, N, 4, N, N] 
Output: [1, 4, 3, 2]
Explanation:

Left boundary: [1] (as there is no left subtree)
Leaf nodes: [4]
Right boundary: [3, 2] (in reverse order)
Final traversal: [1, 4, 3, 2]
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

Expected Complexities
Company Tags
FlipkartMorgan StanleyAccoliteAmazonMicrosoftOYO RoomsSamsungSnapdealFactSetHikePayuKritikal Solutions



/*

Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:

  bool isleaf(Node* root){
    return root && root->left == NULL && root->right == NULL;
  }

    void leftside(Node *root,vector<int>& result){
        Node* curr = root->left;
        while(curr){
            if(!isleaf(curr)){
                result.push_back(curr->data);
            }
            if(curr->left){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
    }

    void leaf(Node* root, vector<int> &result){
        if(root == NULL) return;
        if(isleaf(root)){
            result.push_back(root->data);
        }
         leaf(root->left,result);
         leaf(root->right,result);
    }


    void reverseright(Node* root, vector<int>& result){
        Node * curr = root->right;
        stack<int>st;

        while(curr){
            if(!isleaf(curr)){
                st.push(curr->data);
            }
            if(curr->right) curr = curr->right;
            else{
                curr = curr->left;
            }
        }

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

    }



    vector<int> boundaryTraversal(Node *root) {
        vector<int>result;
        if(root == NULL){
            return result;
        }
        if(!isleaf(root)){
            result.push_back(root->data);
        }

        leftside(root,result);
        leaf(root,result);
        reverseright(root,result);

        return result;
        
    }
};