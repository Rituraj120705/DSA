Subsets




Difficulty: MediumAccuracy: 44.3%Submissions: 46K+Points: 4Average Time: 10m
Given an array arr[] of distinct positive integers, your task is to find all its subsets.

Note: You can return the subsets in any order, the driver code will print them in sorted order.

Examples:

Input: arr[] = [1, 2, 3]
Output: [[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]
Explanation: 
The subsets of [1, 2, 3] in lexicographical order are:
[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]
Input: arr[] = [2, 4]
Output: [[], [2], [2, 4], [4]]
Explanation:
The subsets of [2, 4] in lexicographical order are:
[], [2], [2, 4], [4]
Constraints :
1 ≤ arr.size() ≤ 10
1 ≤ arr[i] ≤ 103
Expected Complexities
Company Tags
MicrosoftNPCI



class Solution {
  public:

    void backtrack(int i, int n, vector<vector<int>>& result, vector<int>& combine,vector<int>& arr){
        if(i==n){
            result.push_back(combine);
            return;
        }

        combine.push_back(arr[i]);

        backtrack(i+1,n,result,combine,arr);

        combine.pop_back();

        backtrack(i+1,n,result,combine,arr);
    }


    vector<vector<int>> subsets(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> result;
        vector<int>combine;

        backtrack(0,n,result,combine,arr);

        return result;
        
    }
};