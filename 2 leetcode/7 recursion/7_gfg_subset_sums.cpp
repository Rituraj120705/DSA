/*Subset Sums
Difficulty: MediumAccuracy: 72.55%Submissions: 170K+Points: 4
Given a array arr of integers, return the sums of all subsets in the list.  Return the sums in any order.

Examples:

Input: arr[] = [2, 3]
Output: [0, 2, 3, 5]
Explanation: When no elements are taken then Sum = 0. When only 2 is taken then Sum = 2. When only 3 is taken then Sum = 3. When elements 2 and 3 are taken then Sum = 2+3 = 5.
Input: arr[] = [1, 2, 1]
Output: [0, 1, 1, 2, 2, 3, 3, 4]
Explanation: The possible subset sums are 0 (no elements), 1 (either of the 1's), 2 (the element 2), and their combinations.
Input: arr[] = [5, 6, 7]
Output: [0, 5, 6, 7, 11, 12, 13, 18]
Explanation: The possible subset sums are 0 (no elements), 5, 6, 7, and their combinations.
Constraints:
1 ≤ arr.size() ≤ 15
0 ≤ arr[i] ≤ 104

Expected Complexities
Topic Tags
Related Articles
*/


class Solution {
  public:
     void func(int idx , int sum , vector<int>&arr, int n , vector<int>&subsets){
        if(idx == n){

            subsets.push_back(sum);
            return;
        }

        func(idx+1,sum + arr[idx] ,arr , n, subsets);

        func(idx+1,sum,arr,n,subsets);
    }


    vector<int> subsetSums(vector<int>& arr) {
        vector<int>subsets;

        int n= arr.size();

        func(0,0,arr,n,subsets);
        return subsets;
    }
};