/*131. Palindrome Partitioning



Solved
Medium
Topics
premium lock icon
Companies
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.*/



class Solution {
public:


    bool ispalin(string s1){
        string s2=s1;
        reverse(s2.begin(),s2.end());
        
        return s1 == s2;
    }

    void backtrack(string s, vector<string>& partitions, vector<vector<string>>& result){
        if(s.size()==0){
            result.push_back(partitions);
            return;
        }

        for(int i =0; i<s.size(); i++){
            string part = s.substr(0,i+1);

            if(ispalin(part)){
                partitions.push_back(part);

                backtrack(s.substr(i+1),partitions,result);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> result;

        vector<string>partitions;

        backtrack(s,partitions,result);

        return result;
    }
};