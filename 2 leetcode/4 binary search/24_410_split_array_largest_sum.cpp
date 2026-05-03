/*410. Split Array Largest Sum
Solved
Hard
Topics
premium lock icon
Companies
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)
 
*/

class Solution {
public:

    bool ispossible(vector<int>&nums,int mid,int k){
        int n = nums.size();
        int count =1;
        int sum =0;

        for(int i = 0;i<n; i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                count++;
                sum = nums[i];
            }

        }
        if(count<=k)return true;
        else{
            return false;
        }
    }


    int splitArray(vector<int>& nums, int k) {
       int n = nums.size();
       int st = *max_element(nums.begin(),nums.end());
       int end = accumulate(nums.begin(),nums.end(),0);
       int ans = -1;
       
       while(st<=end){
        int mid= (st+end)/2;

        if(ispossible(nums,mid,k)){
            ans = mid;
            end = mid-1;
        }
        else{
            st = mid+1;
        }
       }
       return ans;
    }
};