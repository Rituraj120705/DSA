Generate Binary Strings Without Consecutive 1s



Subscribe to TUF+

Hints
Company
Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.



A binary string is a string consisting only of characters '0' and '1'.


Example 1

Input: n = 3

Output: ["000", "001", "010", "100", "101"]

Explanation: All strings are of length 3 and do not contain consecutive 1s.

Example 2

Input: n = 2

Output: ["00", "01", "10"]

Constraints

1 <= n <= 20


class Solution {
public:

    void stringrec(int i , string& s, vector<string>& ans){
        if(i>=s.length()){
            ans.push_back(s);
            return;
        }

        stringrec(i+1,s,ans);

        s[i]='1';

        stringrec(i+2,s,ans);

        s[i]='0';
    }

    vector<string> generateBinaryStrings(int n) {
        string s(n,'0');

        vector<string>ans;

        stringrec(0,s,ans);
        return ans;
    }
};
