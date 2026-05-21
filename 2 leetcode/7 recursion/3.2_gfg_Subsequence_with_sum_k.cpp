/*Subsequence with Sum K



Difficulty: MediumAccuracy: 40.26%Submissions: 74K+Points: 4Average Time: 30m
Given an array arr and target sum k, check whether there exists a subsequence such that the sum of all elements in the subsequence equals to k.

Examples:

Input: arr = [10, 1, 2, 7, 6, 1, 5], k = 8.
Output: true
Explanation: Subsequences like [2, 6], [1, 7] sum upto 8
Input: arr = [2, 3, 5, 7, 9], k = 100. 
Output: false
Explanation: No subsequence can sum upto 100
Constraints:
1 ≤ arr.length ≤ 2000
1 ≤ arr[i] ≤ 1000
1 ≤ target ≤ 2000*/


this answer is correct by the recursion method but it gives the time limit exceed and this question solved using the dp concept
then gives the correct answer 

Time complexity = 2^n of this answer 



class Solution {
  public:

    bool backtrack(int i, int n, vector<int>& arr, int tar, int curr){

        if(curr==tar){
            return true;
        }
        if(i==n){
            return false;
        }
        
           bool take=  backtrack(i+1,n,arr,tar,curr+arr[i]);
        
           bool nontake= backtrack(i+1,n,arr,tar,curr);

           return take || nontake;
    }

    bool checkSubsequenceSum(vector<int>& arr, int k) {
        
        int n = arr.size();

       return  backtrack(0,n,arr,k,0);

        
        
    }
};