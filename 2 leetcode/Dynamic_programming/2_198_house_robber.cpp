198. House Robber
Solved
Medium
Topics
premium lock icon
Companies
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400




class Solution {
public:

    int maxCount(vector<int>&nums, vector<int>&dp,int idx){
        int n= nums.size();
        if(idx==0){
            return nums[idx];
        }

        if(idx<0){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int rob = nums[idx] + maxCount(nums,dp,idx-2);
        int skip = maxCount(nums,dp,idx-1);

        return  dp[idx] = max(rob , skip);
    }

    int rob(vector<int>& nums) {

        int n= nums.size();
        vector<int>dp(n+1,-1);

        return maxCount(nums,dp,n-1);
       
    }
};