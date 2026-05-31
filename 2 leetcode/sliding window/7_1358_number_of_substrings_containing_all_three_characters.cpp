/*1358. Number of Substrings Containing All Three Characters


Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.*/


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left =0;
        int right =0;
        int count = 0;

        vector<int>freq(3,0);


        while(right<n){
            freq[s[right]-'a']++;

            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                count = count + (n-right);

                freq[s[left]-'a']--;
                left++;
            }
            right++;
        }
        return count;
    }
};