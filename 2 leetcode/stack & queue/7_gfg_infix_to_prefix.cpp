/*Infix To Prefix Notation

Difficulty: MediumAccuracy: 37.46%Submissions: 30K+Points: 4Average Time: 15m
You are given a string s representing an infix expression. Convert this infix expression to a prefix expression.

Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
Prefix expression: The expression of the form op a b. When an operator comes before its two operands.

Note: The precedence order is as follows: (^) has the highest precedence and is evaluated from right to left. (* and /) come next with left to right associativity, and (+ and -) have the lowest precedence with left to right associativity.

Examples:

Input: s = "a*(b+c)/d"
Output: /*a+bcd
Explaination: The infix expression is a*(b+c)/d. First, inside the brackets, b + c becomes +bc. Now the expression looks like a*(+bc)/d. Next, multiply a with (+bc), so it becomes *a+bc. Finally, divide this result by d, so it becomes /*a+bcd.
Input: s = "(a-b/c)*(a/k-l)"
Output: *-a/bc-/akl
Explaination: The infix expression is (a-b/c)*(a/k-l). First, inside the brackets, b/c becomes /bc and a/k becomes /ak.Now the expression looks like (a-/bc) * (/ak-l).Next, handle the subtractions: a-/bc becomes -a/bc, and /ak-l becomes -/akl. Finally, multiply the two results: (-a/bc * -/akl) becomes *-a/bc-/akl.
Constraints:
3 ≤ s.length() ≤ 5*103
s[i] can be an operand (a–z, A–Z, 0–9), an operator (+, -, *, /, ^) or a parenthesis ((, ))

Expected Complexities
Topic Tags
Related Articles
*/

1) Reverse the infix and also reverse the only bracket 
2) same code for infix to postfix
3) Reverse the answer 


class Solution {
  public:
    int priority(char ch){
        if(ch == '^') return 3;

        if(ch == '*' || ch == '/') return 2;

        if(ch == '+' || ch == '-') return 1;

        return -1;
    }

    void reve(string &s){
        int n = s.length();
        string rev = "";
        for(int i =n-1; i>=0; i--){
            if(s[i] == '('){
                rev.push_back(')');
            }
            else if(s[i] == ')'){
                rev.push_back('(');
            }
            else{
                rev.push_back(s[i]);
            }
        }
        s = rev;
    }

    string infixToPrefix(string &s) {
        int i = 0;
        stack<char>st;
        string ans = "";

        reve(s);
        
        while(i < s.length()){
            if((s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= '0' && s[i] <= '9')){
                    ans+=s[i];
                }
            
            else if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans+=st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                while(!st.empty() && st.top() != '(' && (priority(s[i]) < priority(st.top()) || (priority(s[i]) == priority(st.top()) && s[i] == '^'))){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};