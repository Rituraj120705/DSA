Bottom View of Binary Tree



Difficulty: MediumAccuracy: 54.18%Submissions: 354K+Points: 4Average Time: 45m
You are given the root of a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

Examples :

Input: root = [1, 2, 3, 4, 5, N, 6]
    
Output: [4, 2, 5, 3, 6]
Explanation: The Green nodes represent the bottom view of below binary tree.
    
Input: root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
    
Output: [5, 10, 4, 28, 25]
Explanation: The Green nodes represent the bottom view of below binary tree.
    
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

Expected Complexities
Company Tags
PaytmFlipkartAccoliteAmazonOYO RoomsWalmartCouponDunia

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
    vector<int> bottomView(Node *root) {
        queue<pair<Node*,int>> q;
        map<int,int>mp;

        q.push({root,0});

        while(q.size()>0){
            Node * curr = q.front().first;
            int hd = q.front().second;
            q.pop();

            mp[hd] = curr->data;

            if(curr->left != NULL){
                q.push({curr->left,hd-1});
            }
            if(curr->right != NULL){
                q.push({curr->right,hd+1});
            }
        }

        vector<int>ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
        
    }
};