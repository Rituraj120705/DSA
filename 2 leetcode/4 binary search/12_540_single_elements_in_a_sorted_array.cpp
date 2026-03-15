/*540. Single Element in a Sorted Array
Solved
Medium
Topics
premium lock icon
Companies
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105*/

THIS IS THE BEST APPROACH FOR SOLVING THE QUESTIONS 

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int st = 1;
        int end = n-2;

        if(n==1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[n-1] != nums[n-2]){
            return nums[n-1];
        }

        while(st<=end){
            int mid = (st+end)/2;

            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }

            if(mid%2==0 && nums[mid]==nums[mid+1] || mid%2==1 && nums[mid]==nums[mid-1]){
                st = mid+1;
            }

            else{
                end = mid-1;
            }
        }
        return -1;
    }
};





this is not a best approach




class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int st = 0;
        int end = n-1;

        while(st<=end){
           int mid = (st+end)/2; 
           if(mid % 2 == 1)mid--;
            if(nums[mid] == nums[mid+1]){
                st = mid +2;
            }
            else{
                end = mid;
            }
        }
        return nums[st];
    }
};