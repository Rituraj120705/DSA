106. Construct Binary Tree from Inorder and Postorder Traversal



Solved
Medium
Topics
premium lock icon
Companies
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.



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

    int search(vector<int>& inorder,int left, int right,int val){
        for(int i = left; i<=right; i++){
            if(inorder[i] == val){
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& inorder,vector<int>& postorder, int & postidx, int left, int right){

        if(left>right){
            return NULL;
        }
        int rootval = postorder[postidx];
        TreeNode* root = new TreeNode(rootval);
        postidx--;

        int inidx = search(inorder,left,right,rootval);
        root->right = helper(inorder,postorder,postidx,inidx+1,right);
        root->left = helper(inorder,postorder,postidx,left,inidx-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postidx = postorder.size()-1;

        return helper(inorder,postorder,postidx,0,inorder.size()-1);
    }
};