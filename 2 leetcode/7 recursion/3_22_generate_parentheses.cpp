/*22. Generate Parentheses
Solved
Medium
Topics
premium lock icon
Companies
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8*/


class Solution {
public:

    void backtrack(int n, int opencount ,int closecount, string current, vector<string>&result){
      

        if(opencount==n && closecount==n){
            result.push_back(current);
            return;
        }
    

    if(opencount<n){
        backtrack(n,opencount+1,closecount,current+"(",result);
    }
    if(closecount<opencount){
        backtrack(n,opencount,closecount+1,current+")",result);
    }
}




    vector<string> generateParenthesis(int n) {
        vector<string> result;

        backtrack(n,0,0,"",result);
        return result;
    }

};