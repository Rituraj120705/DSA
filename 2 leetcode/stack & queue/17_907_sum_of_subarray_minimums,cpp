907. Sum of Subarray Minimums


Solved
Medium
Topics
premium lock icon
Companies
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
 



// this code is burte force approach so this code is not submit on the leetcode and geeksforgeeks because time limit exceed occurs so we have optimized the code.
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int mod = (int) (1e9 + 7); 
        
        for(int i = 0; i<n; i++){
            int minimum = arr[i];

            for(int j = i; j<n; i++){

                minimum = min(minimum,arr[j]);
                sum = (sum + minimum) % mod; 
            }
        }
        return sum; 
    }
};


// now we have to write the optimized code 



class Solution {
public:
    vector<int> findnse(vector<int>&arr){
        int n = arr.size();
        vector<int>ans(n);
        stack<int>s;
        
        for(int i = n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i] = n;
            }
            else{
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }



    vector<int> findpse(vector<int>&arr){
        int n = arr.size();
        vector<int>ans(n);
        stack<int>s;

        for(int i = 0; i<n; i++){
            while(!s.empty() && arr[s.top()] > arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }



    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findnse(arr);
        vector<int> pse = findpse(arr);
        int total = 0;
        int mod = (int) (1e9 + 7);

        for(int i =0; i<n; i++){
            int  left = i - pse[i];
            int right = nse[i] - i; 

            total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
        }
        return total; 
    }
};