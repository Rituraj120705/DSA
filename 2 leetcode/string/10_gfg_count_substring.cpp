/*Count Substring
Difficulty: MediumAccuracy: 51.61%Submissions: 15K+Points: 4Average Time: 20m
Given string s consisting only a,b,c. return the number of substrings containing at least one occurrence of all these characters a, b, and c.

Example 1:

Input:
abcabc
Output:
10
Explanation:
The required substrings  are "abc", "abca", "abcab", "abcabc",
"bca", "bcab", "bcabc", "cab", "cabc" and "abc".

Example 2:

Input:
aaacb
Output:
3
Your Task:
You don't have to read input or print anything. Your task is to complete the function countSubstring() which takes the string s and returns the count of substring having at least a,b,c.

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraint:
3<=s.length<=5 x 104  
S only contains a,b,c.

*/

class Solution {
  public:
    int countSubstring(string s) {
         int n = s.length();
         int lasta=-1;
         int lastb=-1;
         int lastc=-1;
         int ans = 0;

         for(int i =0; i<n; i++){
            if(s[i]=='a') lasta=i;
            else if(s[i]=='b') lastb=i;
            else lastc = i;

            if(lasta!=-1 && lastb!=-1 && lastc!=-1){
                ans+=min(lasta,min(lastb,lastc))+1;
            }
         }
         return ans;
        
    }
};