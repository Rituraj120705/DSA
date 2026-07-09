42. Trapping Rain Water

Solved
Hard
Topics
premium lock icon
Companies
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
 






//this problem solved in the brute force approach in O(n^2);
class Solution {
public:
    int trap(vector<int>& height) {
      int n = height.size();       
      int totalwater = 0;


      for(int i =0; i<n; i++){

        int leftheight= height[i];
        for(int j= 0; j<=i; j++){
            leftheight= max(leftheight,height[j]);
        }

        int rightheight = height[i];
        for(int j=i; j<n; j++){
            rightheight = max(rightheight,height[j]);
        }

        totalwater += min(leftheight,rightheight) - height[i];
      }

      return totalwater;

    }
};




//optimized code
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans=0;
        vector<int>leftheight(n,0);
        vector<int>rightheight(n,0);

        leftheight[0] = height[0];
        rightheight[n-1]= height[n-1];

        for(int i = 1; i<n; i++){
            leftheight[i] = max(leftheight[i-1],height[i]);
        }

        for(int i = n-2; i>=0; i--){
            rightheight[i] = max(rightheight[i+1],height[i]);
        }

        for(int i = 0; i<n; i++){
            ans += min(leftheight[i] , rightheight[i]) - height[i];
        }
        return ans;
    }
};