Prefix to Infix Conversion


Difficulty: MediumAccuracy: 69.51%Submissions: 40K+Points: 4Average Time: 30m
You are given a string S of size N that represents the prefix form of a valid mathematical expression. The string S contains only lowercase and uppercase alphabets as operands and the operators are +, -, *, /, %, and ^.Convert it to its infix form.

Example 1:

Input: 
*-A/BC-/AKL
Output: 
((A-(B/C))*((A/K)-L))
Explanation: 
The above output is its valid infix form.
Your Task:

Your task is to complete the function string preToInfix(string pre_exp), which takes a prefix string as input and return its infix form.

Expected Time Complexity: O(N).

Expected Auxiliary Space: O(N).

Constraints:

3<=|S|<=104


// User function Template for C++

class Solution {
  public:
    void reverse(string &pre_exp){    // you have to use directly reverse function to reverse the string no to write the entire function only use the STL function of reverse;
        int n = pre_exp.length();
        string rev = "";
        for(int i = n-1; i>=0;  i--){
            rev.push_back(pre_exp[i]);
        }
        pre_exp = rev;
    }

    string preToInfix(string pre_exp) {
        int n = pre_exp.length();
        int i = 0;
        stack<string>st;

        reverse(pre_exp);

        while(i<n){
            if((pre_exp[i] >= 'A' && pre_exp[i] <= 'Z') ||
                (pre_exp[i] >= 'a' && pre_exp[i] <= 'z') ||
                    (pre_exp[i] >= '0' && pre_exp[i] <= '9')){
                        st.push(string(1,pre_exp[i]));
                    }

            else{
                string t1 = st.top();
                st.pop();

                string t2 = st.top();
                st.pop();

                string s = "(" + t1 + pre_exp[i] + t2 + ")";
                st.push(s);
            }
            i++;
        }
        return st.top();
    }
};