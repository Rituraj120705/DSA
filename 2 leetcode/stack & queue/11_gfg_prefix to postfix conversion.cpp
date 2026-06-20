Prefix to Postfix Conversion


Difficulty: MediumAccuracy: 75.66%Submissions: 35K+Points: 4Average Time: 30m
You are given a string s that represents the prefix form of a valid mathematical expression. Convert it to its postfix form.

Examples:

Input: s = "+AB"
Output: "AB+"
Explanation: In postfix form, operands come first followed by operator.
Prefix to Infix: +AB becomes A + B
Infix to Postfix: A + B becomes AB+
Input: s = "*+ABC"
Output: AB+C*
Explanation: 
Prefix to Infix: *+ABC becomes (A + B)*C
Infix to Postfix: (A + B)*C becomes AB+C* 
Input: s = "*-A/BC-/AKL"
Output: "ABC/-AK/L-*"
Explanation:
Prefix to infix: *-A/BC-/AKL becomes (A - (B / C)) * ((A / K) - L)
Convert left part to Postfix: (A - (B / C)) becomes ABC/-
Convert right part to Postfix: ((A / K) - L) becomes AK/L-
Combine both with * to get ABC/-AK/L-*
Constraints:
3 ≤ s.size() ≤ 100

Expected Complexities
Topic Tags
Related Articles



class Solution {
  public:
    string preToPost(string &s) {
        int n = s.length();
        stack<string>st;
        reverse(s.begin(),s.end());
        int i = 0;
        while(i<n){
            if((s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= 'a' && s[i] <= 'z') ||
                    (s[i] >= '0' && s[i] <= '9')){
                        st.push(string(1,s[i]));
                    }

            else{
                string t1 = st.top();
                st.pop();

                string t2 = st.top();
                st.pop();

                string temp = t1 + t2 + s[i];
                st.push(temp);
            }
            i++;
        }
        return st.top();
        
    }
};