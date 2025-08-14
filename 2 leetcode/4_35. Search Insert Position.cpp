<<<<<<< HEAD
/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int st =0 ;
        int end = n-1;
        //int mid = (st + end)/ 2;

        while(st <= end){
        int mid = (st + end)/ 2;

        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            st = mid + 1;
        }
        else{
            end = mid - 1;
        }
        
        }
       return st;
    }
=======
/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int st =0 ;
        int end = n-1;
        //int mid = (st + end)/ 2;

        while(st <= end){
        int mid = (st + end)/ 2;

        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            st = mid + 1;
        }
        else{
            end = mid - 1;
        }
        
        }
       return st;
    }
>>>>>>> f6accc8fc3ca276ba23c00f0c5e1519773122d76
};