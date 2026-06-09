Top View of Binary Tree
Difficulty: MediumAccuracy: 38.43%Submissions: 462K+Points: 4Average Time: 45m
You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note:

Return the nodes from the leftmost node to the rightmost node.
If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 
Examples:

Input: root = [1, 2, 3]
Output: [2, 1, 3]
Explanation: The Green colored nodes represents the top view in the below Binary tree.
 
Input: root = [10, 20, 30, 40, 60, 90, 100]
Output: [40, 20, 10, 30, 100]
Explanation: The Green colored nodes represents the top view in the below Binary tree.


Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

Expected Complexities
Company Tags
PaytmOla CabsWalmartNPCI


/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        queue<pair<Node*,int>>q;     // node,horizontal distance
        map<int,int>m;              // horizontal distance, node val

        q.push({root,0});

        while(q.size()>0){
            Node * curr = q.front().first;
            int hd = q.front().second;
            q.pop();
            
            if(m.find(hd)==m.end()){
                m[hd] = curr->data;
            }

            if(curr->left != NULL){
                q.push({curr->left,hd-1});
            }
            if(curr->right != NULL){
                q.push({curr->right,hd+1});
            }
        }
        vector<int>ans;
        for(auto it: m){
            ans.push_back(it.second);
        }

        return ans;
        
    }
};