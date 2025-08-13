/*90. Subsets II
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10*/



class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        set<vector<int>>s;
        for(int i=0; i<(1<<n); i++){
            
            vector<int>subset;

            for(int j=0; j<n; j++){

                if(i & (1<<j)){
                   subset.push_back(nums[j]);
                   
                }
            }
            s.insert(subset);
            
        }
        
        ans.assign(s.begin(), s.end());
        return ans;
    }
};