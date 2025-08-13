/*40. Combination Sum II
Solved
Medium
Topics
premium lock icon
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30*/


class Solution {
public:
    void combisum(vector<int>& candidates, int start, vector<int>& combin,
                  vector<vector<int>>& result, int target) {
        if (target == 0) {
            result.push_back(combin);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates at same recursion depth
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break; // No point continuing

            combin.push_back(candidates[i]);
            combisum(candidates, i + 1, combin, result, target - candidates[i]); // i+1: use once
            combin.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Important for duplicate skipping
        vector<vector<int>> result;
        vector<int> combin;
        combisum(candidates, 0, combin, result, target);
        return result;
    }
};
