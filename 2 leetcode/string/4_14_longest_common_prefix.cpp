14. Longest Common Prefix
Solved
Easy
Topics
premium lock icon
Companies
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.empty()){
            return "";
        }

        sort(strs.begin() , strs.end());

        string first = strs[0];
        string last = strs[strs.size()-1];
        int i = 0;

        while(i<first.size() && i<last.size() && first[i] == last[i]){
            i++;
        }

        return first.substr(0,i);
    }
};