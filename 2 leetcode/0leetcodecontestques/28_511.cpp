Q3. Transform Binary String Using Subsequence Sort


Medium
5 pt.
You are given a binary string s.

You are also given an array of strings strs, where each strs[i] has the same length as s and consists of characters '0', '1', and '?'. Each '?' can be replaced by either '0' or '1'.

You may perform the following operation any number of times (including zero):

Choose any subsequence sub of s.
Sort sub in non-decreasing order.
Replace the chosen subsequence in s with the sorted sub, keeping all other characters unchanged.
Return a boolean array ans, where ans[i] is true if it's possible to replace all '?' in strs[i] with '0' or '1' and transform s into the resulting string using the allowed operation above, otherwise return false.

 

Example 1:

Input: s = "101", strs = ["1?1","0?1","0?0"]

Output: [true,true,false]

Explanation:

i	strs[i]	Replacement	Result strs[i]	Operation(s)	Result
0	"1?1"	? → 0	"101"	Matches s.	true
1	"0?1"	? → 1	"011"	Select the subsequence at indices [0..2] of s → "101".
Sort "101" to get "011" = strs[i].	true
2	"0?0"	? → 0 or 1	"000" or "010"	Not feasible.	false
Thus, ans = [true, true, false].

Example 2:

Input: s = "1100", strs = ["0011","11?1","1?1?"]

Output: [true,false,true]

Explanation:

i	strs[i]	Replacement	Result strs[i]	Operation(s)	Result
0	"0011"	-	"0011"	Select the subsequence at indices [0..3] of s → "1100".
Sort "1100" to get "0011" = strs[i].	true
1	"11?1"	? → 0	"1101"	Not feasible.	false
2	"1?1?"	First ? → 0
Second ? → 0	"1010"	Select the subsequence at indices [1, 2] of s → "10".
Sort "10" to get "01", so s = "1010".	true
Thus, ans = [true, false, true].

Example 3:

Input: s = "1010", strs = ["0011"]

Output: [true]

Explanation:

i	strs[i]	Replacement	Result strs[i]	Operation(s)	Result
0	"0011"	-	"0011"	Select the subsequence at indices [0, 2, 3] of s → "110".
Sort "110" to get "011", so s = "0011" = strs[i].	true
Thus, ans = [true].

 

Constraints:

1 <= n == s.length <= 2000
s[i] is either '0' or '1'.
1 <= strs.length <= 2000
strs[i].length == n
strs[i] is either '0', '1', or '?'​​​​​​​.





class Solution {
public:
    bool check(string &s , string &t){
        int n = s.length();
        vector<int>original;

        for(int i = 0; i<n; i++){
            if(s[i] == '1'){
                original.push_back(i);
            }
        }
        int ones = original.size();

        int fixedone = 0;
        int question = 0;

        for(int c : t){
            if(c == '1'){
                fixedone++;
            }
            else if(c == '?'){
                question++;
            }
        }

        if(fixedone > ones || fixedone + question < ones){
            return false;
        }

        vector<int>target;

        for(int i = 0; i<n; i++){
            if(t[i] == '1'){
                target.push_back(i);
            }
        }

        int need = ones-fixedone;

        for(int i = n-1; i>=0 && need>0; i--){
            if(t[i] == '?'){
                target.push_back(i);
                need--;
            }
        }

        sort(target.begin(),target.end());
        for(int i = 0; i<ones; i++){
            if(original[i] > target[i])
            return false;
        }

        return true;

    }



    vector<bool> transformStr(string s, vector<string>& strs) {
        vector<bool>ans;
        for(auto x : strs){
            ans.push_back(check(s,x));
        }
        return ans;
    }
};