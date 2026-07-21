Palindrome Digit Sum




Solved
Difficulty: BasicAccuracy: 45.75%Submissions: 73K+Points: 1
Given a number n. Return true if the digit sum(or sum of digits) of n is a Palindrome number otherwise false.
A Palindrome number is a number that stays the same when reversed

Examples:

Input: n = 56
Output: true
Explanation: The digit sum of 56 is 5+6 = 11. Since, 11 is a palindrome number.Thus, answer is true.
Input: n = 98
Output: false
Explanation: The digit sum of 98 is 9+8 = 17. Since 17 is not a palindrome,thus, answer is false.
Constraints:
1 ≤ n ≤ 109




class Solution {
  public:
    bool isDigitSumPalindrome(int n) {
        // code here
        string s = to_string(n);
        int m = s.length();
        if (n<0){
            return false;
        }
        
        int sum = 0; 
        for(int i = 0; i<m; i++){
            sum += s[i]-'0';
        }
        
        int original = sum;
        int reverse = 0;
        while(sum > 0){
            int digit = sum % 10;
            
            reverse = reverse * 10 + digit;
            
            sum /= 10;
        }
        return original == reverse;
    }
};