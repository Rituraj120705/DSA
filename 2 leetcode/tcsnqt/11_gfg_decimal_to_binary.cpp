Decimal to binary


Solved
Difficulty: EasyAccuracy: 55.75%Submissions: 56K+Points: 2
Given a decimal integer n, convert it and return its binary equivalent as a string.

Examples :

Input: n = 12
Output: 1100
Explanation: The binary representation of 12 is "1100", since 12 = 1×23 + 1×22 + 0×21 + 0×20
Input: n = 33
Output: 100001
Explanation: The binary representation of 33 is "100001", since 33 = 1×25 + 0×24 + 0×23 + 0×22 + 0×21 + 1×20
Constraints:
1 ≤ n ≤ 231 - 1

Expected Complexities
Company Tags
Adobe
Topic Tags
Related Interview Experiences
Related Articles
If you are f


class Solution {
  public:
    string decToBinary(int n) {
        // code here
        if(n==0){
            return "0";
        }
      string ans ="";
            while(n>0){
               ans += (n%2)+'0';
               n/=2;
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};