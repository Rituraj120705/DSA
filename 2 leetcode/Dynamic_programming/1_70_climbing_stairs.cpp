70. Climbing Stairs
Attempted
Easy
Topics
premium lock icon
Companies
Hint
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45


// whitout using the dynamic programming so that leetcode do not accept this code and give TIME LIMIT EXCEED

class Solution {
public:
    int climbStairs(int n) {
        
        if (n ==0 || n==1){
            return 1;
        }


        return climbStairs(n-1) + climbStairs(n-2);
    }
};



// now this problem is solving the memoization of dp approach 


class Solution {
public:


    int countWayMem(int n, vector<int>&dp){
        if(n==1 || n==0){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = countWayMem(n-1,dp) + countWayMem(n-2,dp);
            return dp[n];
    }
    int climbStairs(int n) {

        vector<int> dp(n+1,-1);

        return countWayMem(n,dp);
    }
};




// again this question is solved using the tabulation to reduce the time complexity

