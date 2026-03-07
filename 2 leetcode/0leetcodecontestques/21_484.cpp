/*Q2. Number of Centered Subarrays
Medium
4 pt.
You are given an integer array nums.

A subarray of nums is called centered if the sum of its elements is equal to at least one element within that same subarray.

Return the number of centered subarrays of nums.

 

Example 1:

Input: nums = [-1,1,0]

Output: 5

Explanation:

All single-element subarrays ([-1], [1], [0]) are centered.
The subarray [1, 0] has a sum of 1, which is present in the subarray.
The subarray [-1, 1, 0] has a sum of 0, which is present in the subarray.
Thus, the answer is 5.
Example 2:

Input: nums = [2,-3]

Output: 2

Explanation:

Only single-element subarrays ([2], [-3]) are centered.

 

Constraints:

1 <= nums.length <= 500
-105 <= nums[i] <= 105*/

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
       int n = nums.size();
       
       int count = 0;
       if(n==0)return 0;


       for(int st=0; st<n; st++){
            unordered_set<int>s;
            int sum = 0;
        for(int end = st; end<n; end++){
             sum += nums[end];
            s.insert(nums[end]);

            if(s.count(sum)){
                count++;
            }
            
        }
       }
       return count;
    }
};








another methods

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        if(n == 0) return 0;

        for(int st = 0; st < n; st++){
            
            long long sum = 0;  // running sum
            
            for(int end = st; end < n; end++){
                
                sum += nums[end];  // correct sum
                
                // check if sum exists inside subarray [st, end]
                for(int k = st; k <= end; k++){
                    if(nums[k] == sum){
                        count++;
                        break;   // no need to check further
                    }
                }
            }
        }
        
        return count;
    }
};