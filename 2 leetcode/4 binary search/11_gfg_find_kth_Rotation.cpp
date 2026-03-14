/*Find Kth Rotation
Difficulty: EasyAccuracy: 23.16%Submissions: 348K+Points: 2Average Time: 20m
Given an increasing sorted rotated array arr[] of distinct integers. The array is right-rotated k times. Find the value of k.
Let's suppose we have an array arr[] = [2, 4, 6, 9], if we rotate it by 2 times it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]

Examples:

Input: arr[] = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see that the array was rotated 1 times to the right.
Input: arr = [1, 2, 3, 4, 5]
Output: 0
Explanation: The given array is not rotated.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 107*/


class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();

        int st = 0;
        int end = n-1;
        int ans = INT_MAX;
        int index = -1;

        while(st<=end){
            int mid = (st+end)/2;

            if(arr[st]<=arr[end]){
                if(arr[st]<ans){
                    ans = arr[st];
                    index=st;
                }
                break;
            }

            if(arr[st]<=arr[mid]){
                if(arr[st]<ans){
                    ans=arr[st];
                    index = st;
                }
                st = mid+1;
            }

            if(arr[mid]<=arr[end]){
                if(arr[mid]<ans){
                    ans = arr[mid];
                    index = mid;
                }
                end = mid-1;
            }
        }
        return index;
        
    }
};
