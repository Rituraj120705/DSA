/*Q2. Maximum Capacity Within Budget
Medium
4 pt.
You are given two integer arrays costs and capacity, both of length n, where costs[i] represents the purchase cost of the ith machine and capacity[i] represents its performance capacity.

You are also given an integer budget.

You may select at most two distinct machines such that the total cost of the selected machines is strictly less than budget.

Return the maximum achievable total capacity of the selected machines.

 

Example 1:

Input: costs = [4,8,5,3], capacity = [1,5,2,7], budget = 8

Output: 8

Explanation:

Choose two machines with costs[0] = 4 and costs[3] = 3.
The total cost is 4 + 3 = 7, which is strictly less than budget = 8.
The maximum total capacity is capacity[0] + capacity[3] = 1 + 7 = 8.
Example 2:

Input: costs = [3,5,7,4], capacity = [2,4,3,6], budget = 7

Output: 6

Explanation:

Choose one machine with costs[3] = 4.
The total cost is 4, which is strictly less than budget = 7.
The maximum total capacity is capacity[3] = 6.
Example 3:

Input: costs = [2,2,2], capacity = [3,5,4], budget = 5

Output: 9

Explanation:

Choose two machines with costs[1] = 2 and costs[2] = 2.
The total cost is 2 + 2 = 4, which is strictly less than budget = 5.
The maximum total capacity is capacity[1] + capacity[2] = 5 + 4 = 9.
 

Constraints:

1 <= n == costs.length == capacity.length <= 105
1 <= costs[i], capacity[i] <= 105
1 <= budget <= 2 * 105*/









THIS QUESTION IS TOUGH I DONOT UNDERSTAND THIS CODE, AFTER SOME TIME REVIEW THIS QEESTION AGAIN;









class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>> machines;
        
        for(int i = 0; i < n; i++){
            machines.push_back({costs[i], capacity[i]});
        }
        
        sort(machines.begin(), machines.end());
        
        int ans = 0;
        
        // prefix max capacity
        vector<int> prefixMax(n);
        prefixMax[0] = machines[0].second;
        
        for(int i = 1; i < n; i++){
            prefixMax[i] = max(prefixMax[i-1], machines[i].second);
        }
        
        for(int i = 0; i < n; i++){
            
            // Single machine
            if(machines[i].first < budget)
                ans = max(ans, machines[i].second);
            
            // Find partner
            int remaining = budget - machines[i].first - 1;
            int l = 0, r = i - 1;
            int idx = -1;
            
            while(l <= r){
                int mid = (l + r) / 2;
                if(machines[mid].first <= remaining){
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
            if(idx != -1){
                ans = max(ans, machines[i].second + prefixMax[idx]);
            }
        }
        
        return ans;
    }
};