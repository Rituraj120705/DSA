/*Infix to Postfix


Difficulty: MediumAccuracy: 52.94%Submissions: 174K+Points: 4
You are given a string s representing an infix expression. Convert this infix expression to a postfix expression.

Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The precedence order is as follows: (^) has the highest precedence and is evaluated from right to left, (* and /) come next with left to right associativity, and (+ and -) have the lowest precedence with left to right associativity.

Examples :

Input: s = "a*(b+c)/d"
Output: abc+*d/
Explanation: The expression is a*(b+c)/d. First, inside the brackets, b+c becomes bc+. Now the expression looks like a*(bc+)/d. Next, multiply a with (bc+), so it becomes abc+* . Finally, divide this result by d, so it becomes abc+*d/.
Input: s = "a+b*c+d"
Output: abc*+d+
Explanation: The expression a+b*c+d is converted by first doing b*c -> bc*, then adding a -> abc*+, and finally adding d -> abc*+d+.
Input: s = "(a+b)*(c+d)"
Output: ab+cd+*
Explanation: The expression (a+b)*(c+d) is converted by first doing (a+b) -> ab+, then doing (c+d) -> cd+, and finally the expression ab+*cd+ becomes ab+cd+*. 
Constraints:
1 ≤ s.length ≤ 5*103
s[i] can be an operand (a–z, A–Z, 0–9), an operator (+, -, *, /, ^) or a parenthesis ((, ))

Expected Complexities
Company Tags
PaytmVMWareMicrosoft*/


class Solution {
  public:
    int priority(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return -1;
}
    string infixToPostfix(string& s) {
        int i = 0;
        stack<char>st;
        string ans = "";

        while(i<s.length()){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                ans = ans + s[i];
            }
            else if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                } 
                if(!st.empty()){

                    st.pop();
                }
            }

            else{
                while(!st.empty() && st.top() != '(' && (priority(s[i]) < priority(st.top()) || (priority(s[i]) == priority(st.top()) && s[i] != '^'))){
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
        return ans;

        
    }
};
