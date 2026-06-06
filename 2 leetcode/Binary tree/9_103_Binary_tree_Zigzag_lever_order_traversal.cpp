/*103. Binary Tree Zigzag Level Order Traversal


Solved
Medium
Topics
premium lock icon
Companies
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
 
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr){
            return result;
        }
        int flag = 0;
        
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int>ans;
            for(int i = 0; i<n; i++){

                TreeNode* curr = q.front();
                q.pop();

                ans.push_back(curr->val);

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            if(flag==1){
                reverse(ans.begin(),ans.end());
            }
            
            result.push_back(ans);

            flag= 1-flag;
        }
        return result;
    }
};