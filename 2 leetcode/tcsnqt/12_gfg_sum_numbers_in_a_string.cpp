Sum Numbers in a String


Solved
Difficulty: EasyAccuracy: 63.01%Submissions: 74K+Points: 2Average Time: 30m
Given a string s containing alphanumeric characters. You have to calculate the sum of all the numbers present in the string.

Examples:

Input: s = "1abc23"
Output: 24
Explanation: 1 and 23 are numbers in the string which is added to get the sum as 24.
Input: s = "geeks4geeks"
Output: 4
Explanation: 4 is the only number, so the sum is 4.
Constraints:
1 ≤ |s|≤ 105
The sum of Numbers ≤ 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
Topic Tags
Strings
Related Articles



class Solution {
  public:
    int findSum(string& s) {
        // code here
        int sum = 0;
        int num = 0;
        
        for(char ch : s){
            
            if(ch>='0' && ch<='9'){
                num = num * 10 + (ch - '0');
            }
            else{
                sum += num;
                num = 0;
            }
        }
        sum += num;
        return sum;
    }
};