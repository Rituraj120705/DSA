/*1248. Count Number of Nice Subarrays
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
 
*/



class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        int left=0;
        int right=0;
        int count=0;
        int odd=0;

        while(right<n){
            if(nums[right]%2==1){
                odd++;
            }
            while(odd>k){
                if(nums[left]%2==1){
                    odd--;
                }
                left++;
            }
            count = count + right-left+1;
            right++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k){
        return solve(nums,k)- solve(nums,k-1);
    }
};