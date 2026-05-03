/*5. Longest Palindromic Substring
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.*/


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        if(n==0) return "";
        int start = 0;
        int maxlen=1;

        for(int i =0; i<n; i++){
            //odd
            int left=i-1;
            int right=i+1;

            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1>maxlen){
                    start = left;
                    maxlen= right-left+1;
                }
                left--;
                right++;
            }
            //even
             left=i;
             right=i+1;

            while(left>=0 &&right<n && s[left]==s[right]){
                if(right-left+1>maxlen){
                    start = left;
                    maxlen= right-left+1;
                }
                left--;
                right++;
            }
        }
        return s.substr(start,maxlen);
    }
};