Postfix to Infix Conversion



Difficulty: MediumAccuracy: 49.41%Submissions: 56K+Points: 4Average Time: 30m
You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its infix form.

Example:

Input:
ab*c+ 
Output: 
((a*b)+c)
Explanation: 
The above output is its valid infix form.
Your Task:

Complete the function string postToInfix(string post_exp), which takes a postfix string as input and returns its infix form.

 

Expected Time Complexity: O(N).

Expected Auxiliary Space: O(N).

Constraints:

3<=post_exp.length()<=104

Topic Tags
Related Articles




// User function Template for C++

class Solution {
  public:
    string postToInfix(string &exp) {
        int n = exp.length();
        int i = 0;
        stack<string>st;
        
        while(i<n){
            if((exp[i] >= 'A' && exp[i] <= 'Z') ||
                (exp[i] >= 'a' && exp[i] <= 'z') ||
                (exp[i] >= '0' && exp[i] <= '9')){
                    st.push(string(1,exp[i]));
                }

            else{
                string t1 = st.top();
                st.pop();

                string t2 = st.top();
                st.pop();

                string s = "(" + t2 + exp[i] + t1 + ")" ;
                st.push(s);

            }
            i++;
        }
        return st.top();
    }
};