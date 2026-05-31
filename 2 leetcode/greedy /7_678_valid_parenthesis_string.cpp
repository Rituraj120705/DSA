/*678. Valid Parenthesis String



Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.
 
Seen this question in a real interview before?
*/




// class Solution {
// public:
//     bool solve(string s , int idx , int count){
//         if(count<0){
//             return false;
//         }
//         if(idx == s.size()){
//             return count == 0;
//         }
//         if(s[idx]=='('){
//             return solve(s,idx+1,count+1);
//         }
//         if(s[idx]==')'){
//             return solve(s,idx+1,count-1);
//         }
//         return solve(s,idx+1,count) || solve(s,idx+1,count+1) || solve(s,idx+1,count-1);
//     }


//     bool checkValidString(string s) {
//         return solve(s,0,0);
//     }
// };




class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // if '*' acts as ')'
                high++;  // if '*' acts as '('
            }

            if (high < 0)
                return false;

            low = max(low, 0);
        }

        return low == 0;
    }
};