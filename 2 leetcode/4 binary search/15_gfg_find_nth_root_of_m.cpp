/*Find nth root of m
Difficulty: MediumAccuracy: 25.06%Submissions: 258K+Points: 4Average Time: 15m
You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then return -1.

Examples :

Input: n = 3, m = 8
Output: 2
Explanation: 23 = 8
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.
Input: n = 4, m = 16
Output: 2
Explanation: 24 = 16
Constraints:
1 ≤ n ≤ 9
0 ≤ m ≤ 20*/

class Solution {
  public:

    int power(int mid, int n){
        int result = 1;
        for(int i = 0; i<n; i++){
            result*=mid;
        }
        return result;
    }

    int nthRoot(int n, int m) {
        int st = 1;
        int end = m;
        if (m==1)return 1;
        if (m==0)return 0;
        while(st<=end){
            int mid = (st+end)/2;

            int value = power(mid,n);

            if(value==m){
                return mid; 
            }
            else if(value>m){
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return -1;
    }
};