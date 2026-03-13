/*34. Find First and Last Position of Element in Sorted Array
Solved
Medium
Topics
premium lock icon
Companies
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
 
*/


class Solution {
public:

    int lowerBound(vector<int>&arr,int target ){
        int n = arr.size();
        int low = 0; 
        int high = n-1;
        int ans = n;

        while(low<=high){
            int mid = (low+high)/2;

            if(arr[mid] >= target){
                ans= mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }


        }
        return ans;
    }

    int upperbound(vector<int>&arr, int target){
         int n = arr.size();
         int st = 0;
         int end = n-1;
         int ans= n;

         while(st<=end){
            int mid = (st+end)/2;

            if(arr[mid]> target){
                ans = mid;
                end = mid-1;
            }
            else{
                st = mid+1;
            }
         }
         return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums,target);
        if(lb==n || nums[lb] != target ) return {-1,-1};
        return {lb,upperbound(nums,target)-1};
    }
};