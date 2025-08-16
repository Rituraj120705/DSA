17. Letter Combinations of a Phone Number
Solved
Medium
Topics
premium lock icon
Companies
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].



class Solution {
public:

   void backtrack(string digits, int index, string current,vector<string>&result,vector<string>mapping){


            if(index==digits.size()){
                result.push_back(current);          //
                return;
            }

            string letter = mapping[digits[index]-'0'];

            for(char c : letter){
                backtrack(digits,index+1,current+c,result,mapping);
            }
    
   }


    vector<string> letterCombinations(string digits) {
        vector<string>result;
        vector<string> mapping= {"","","abc","def","ghi","jkl","mno","pqrs",     "tuv","wxyz"};
        if(digits.empty()){
            return {};
        }

        backtrack(digits,0,"",result,mapping);
        return result;
        
    }
};







digits[index] - '0'  ------>  meaning of this line 

In C++ characters are stored using ASCII values (integers).

'0' is the character '0' with ASCII code 48.

'2' has ASCII code 50.

So '2' - '0' = 50 - 48 = 2.

In general, subtracting '0' converts a digit character into its integer value.

'3' - '0' = 3

'7' - '0' = 7