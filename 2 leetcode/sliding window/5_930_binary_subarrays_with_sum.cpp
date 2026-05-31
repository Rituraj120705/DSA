/*930. Binary Subarrays With Sum


Solved
Medium
Topics
premium lock icon
Companies
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length*/


class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        int n = nums.size();
        if(goal<0){
            return 0;
        }
        int left = 0;
        int right = 0;
        int count = 0;
        int sum = 0;

        while(right<n){
            sum = sum + nums[right];

            while(sum > goal){
                sum = sum - nums[left];
                left++;
            }
            count = count + (right-left+1);
            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal){
        return solve(nums,goal) - solve(nums,goal-1);
    }
};