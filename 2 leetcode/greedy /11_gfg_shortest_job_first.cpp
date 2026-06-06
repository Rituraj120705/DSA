/*Shortest Job first

Difficulty: MediumAccuracy: 68.79%Submissions: 48K+Points: 4Average Time: 30m
The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next. Given an array of integers bt[] of size n. Array bt[] denotes the burst time of each process. Calculate the average waiting time of all the processes and return the nearest integer which is smaller or equal to the output.

Note: Consider all process are available at time 0.

Examples:

Input: bt[] = [4,3,7,1,2]
Output: 4
Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 4.
Input: bt[] = [1,2,3,4]
Output: 2
Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 2.
Constraints:
1 <= n <= 105
1 <= arr[i] <= 105*/


class Solution {
  public:
    int solve(vector<int>& bt) {
        int n = bt.size();

        int t = 0;
        int wt = 0;

        sort(bt.begin(),bt.end());
        for(int i =0; i<n; i++){
            wt += t;
            t += bt[i];
        }
        return wt/n;
        
    }
};