Palindrome String


Solved
Difficulty: EasyAccuracy: 51.21%Submissions: 507K+Points: 2
Given a string s, return true if the string is a palindrome. Otherwise, return false.

A string is considered a palindrome if it reads the same forwards and backwards.

Examples :

Input: s = "abba"
Output: true
Explanation: "abba" reads the same forwards and backwards, so it is a palindrome.
Input: s = "abc" 
Output: false
Explanation: "abc" does not read the same forwards and backwards, so it is not a palindrome.
Constraints:
1 ≤ s.size() ≤ 106
The string s contains only lowercase english letters (a-z).

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
Company Tags
PaytmZohoMorgan StanleyAmazonD-E-ShawFactSetCiscoFacebook
Topic Tags




class Solution {
  public:
    bool isPalindrome(string& s) {
        // code here
        int n = s.length();
        
        string original= s;
        reverse(s.begin(),s.end());
        
        if(original == s){
            return true;
        }
        else{
            return false;
        }
    }
};