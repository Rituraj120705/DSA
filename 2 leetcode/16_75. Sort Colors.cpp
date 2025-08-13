/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

*/



//first method 0(N)  but 2 passes means 2 loop

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count0=0,count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) count0++;
            else if(nums[i]==1) count1++;
            else
            count2++;
        }
        int idx=0;
        for(int i=0;i<count0;i++){
            nums[idx]=0;
            idx++;
        }
        for(int i=0;i<count1;i++){
            nums[idx]=1;
            idx++;
        }
        for(int i=0;i<count2;i++){
            nums[idx]=2;
            idx++;
        }
    }
};




//second method at also O(N) but single passes means single loop 
//THIS ALGORITHM IS ALSO KNOWN AS DUTCH NATIONAL FLAG ALGORITHM


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int low =0,mid=0,high=n-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }
};