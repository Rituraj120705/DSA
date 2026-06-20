Postfix to Prefix Conversion


Difficulty: MediumAccuracy: 76.83%Submissions: 34K+Points: 4Average Time: 30m
You are given a string s that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.

Examples :

Input: s = "ab+"
Output: "+ab"
Explanation: In prefix form, operator comes before operands.
Postfix to Infix: ab+ becomes a + b 
Infix to Prefix: a + b becomes +ab 
Input: s = "ab+c*"
Output: "*+abc"
Explanation:
Postfix to Infix: ab+ becomes (a + b), then with c gives (a + b)*c
Infix to Prefix: (a + b) becomes +ab, then with c gives *+abc
Input: s = "ABC/-AK/L-*"
Output: "*-A/BC-/AKL"
Explanation: 
Postfix to infix: ABC/-AK/L-* becomes (A - (B / C)) * ((A / K) - L)
Convert left part to Prefix: (A - (B / C)) becomes -A/BC
Convert right part to Prefix: ((A / K) - L) becomes -/AKL
Combine both with * to get *-A/BC-/AKL
Constraints:

3 ≤ s.size() ≤ 1.6*104

Expected Complexities
Topic Tags
Related Articles





class Solution {
  public:
    string postToPre(string s) {
        int n = s.length();
        int i = 0; 
        stack<string>st;

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

                string ans = s[i] + t2 + t1;
                st.push(ans);
            }
            i++;
            
        }

        return st.top();
        
    }
};