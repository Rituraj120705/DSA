Reverse a Stack



Difficulty: MediumAccuracy: 80.5%Submissions: 131K+Points: 4Average Time: 20m
You are given a stack st[]. You have to reverse the stack.

Note: The input array represents the stack from bottom to top (last element is the top). The output is displayed by printing elements from top to bottom after reversal.

Examples:

Input: st[] = [1, 2, 3, 4]
Output: [1, 2, 3, 4]
Explanation: After reversing, the elements of stack are in opposite order.

Input: st[] = [3, 2, 1]
Output: [3, 2, 1]
Explanation: After reversing, the elements of stack are in opposite order.

Constraints:
1 ≤ st.size() ≤ 100
0 ≤ stack element ≤ 100

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)

class Solution {
  public:
    void reverseStack(stack<int> &st) {
        vector<int>v;

        while(st.size()>0){
            int topelement=st.top();
            v.push_back(topelement);
            st.pop();
        }

        int n = v.size();
        for(int i = 0; i<n; i++){
            st.push(v[i]);
        }      
        return ;
    }
};