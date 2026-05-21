Sort a stack



Difficulty: MediumAccuracy: 69.19%Submissions: 176K+Points: 4Average Time: 20m
Given a stack of integers st[]. Sort the stack in ascending order (smallest element at the bottom and largest at the top).

Examples:

Input: st[] = [41, 3, 32, 2, 11]
Output: [41, 32, 11, 3, 2]
Explanation: After sorting, the smallest element (2) is at the bottom and the largest element (41) is at the top.

Input: st[] = [3, 2, 1]
Output: [3, 2, 1]
Explanation: The stack is already sorted in ascending order.

Constraints:
1 ≤ st.size() ≤ 103
0 ≤ stack element ≤ 103 

Expected Complexities
Company Tags
AmazonMicrosoftGoldman SachsIntuitYahooIBMKuliza



class Solution {
  public:

    void insertelement(stack<int>&st,int x){
        if(st.size()<=0 || st.top()<=x){
            st.push(x);
            return ;
        }
        int temp = st.top();
        st.pop();

        insertelement(st,x);
        st.push(temp);
    }

    void sortStack(stack<int> &st) {
        
        if(st.size()<=0){
            return;
        }

        int topelement = st.top();
        st.pop();

        sortStack(st);

        insertelement(st,topelement);

        
    }
};
