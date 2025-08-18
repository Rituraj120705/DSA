213. House Robber II
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000



class Solution {
public:

    int maxCount(vector<int>&nums, vector<int>&dp,int idx,int start){
        int n= nums.size();
        if(idx==0){
            return nums[start];
        }

        if(idx<0){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int rob = nums[idx + start] + maxCount(nums,dp,idx-2,start);
        int skip = maxCount(nums,dp,idx-1,start);

        return  dp[idx] = max(rob , skip);
    }

    int rob(vector<int>& nums) {

        int n= nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int>dp(n,-1);
        int ans1= maxCount(nums,dp,n-2,0);
        vector<int>dp2(n,-1);
        int ans2=maxCount(nums,dp2,n-2,1);

        return max(ans1,ans2);
    }
};