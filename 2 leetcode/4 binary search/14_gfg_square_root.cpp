/*Square Root
Difficulty: EasyAccuracy: 54.03%Submissions: 367K+Points: 2Average Time: 20m
Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number.

Examples:

Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.
Input: n = 11
Output: 3
Explanation: Since, 11 is not a perfect square, floor of square root of 11 is 3.
Input: n = 1
Output: 1
Explanation: 1 is a perfect sqaure, so its square root is 1.
Constraints:
1 ≤ n ≤ 3*104

*/

class Solution {
  public:
    int floorSqrt(int n) {
        int st = 1;
        int end = n;
        int ans = 1;

        while(st<=end){
            int mid = (st+end)/2;

            if(mid * mid == n){
                ans = mid;
                return ans;
            }
            else if(mid * mid > n){

                end = mid-1;
            }
            else{
                ans = mid;
                st = mid + 1;
            }
        }
        return ans ;
    }
};