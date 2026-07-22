Kth Largest


Solved
Difficulty: MediumAccuracy: 64.92%Submissions: 35K+Points: 4
Given an array arr[] and a number k. The task is to find the kth largest element in the array.

Examples:

Input: arr[] = [3, 5, 4, 2, 9], k = 3
Output: 4
Explanation: Third largest element in the array is 4.
Input: arr[] = [4, 3, 7, 6, 5], k = 5
Output: 3
Explanation: Fifth largest element in the array is 3.
Constraints:
1 <= k <= arr.size<= 106
-104 <= arr[i] <= 104

Expected Complexities
Topic Tags
HeapSTL


class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;         // min heap  
        
        for(int i = 0; i<arr.size(); i++){
            pq.push(arr[i]);

            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};







class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int ans = n-k;
        return arr[ans];
    }
};