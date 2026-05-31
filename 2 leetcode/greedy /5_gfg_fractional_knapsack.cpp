/*Fractional Knapsack



Difficulty: MediumAccuracy: 32.46%Submissions: 397K+Points: 4Average Time: 20m
Given two arrays, val[] and wt[] , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

Examples :

Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240
Input: val[] = [500], wt[] = [30], capacity = 10
Output: 166.670000
Explanation: Since the item’s weight exceeds capacity, we take a fraction 10/30 of it, yielding value 166.670000.
Constraints:
1 ≤ val.size = wt.size ≤ 105
1 ≤ capacity ≤ 109
1 ≤ val[i], wt[i] ≤ 104*/ 
    
    
    class Solution {
  public:

        static bool compare(pair<double,int>p1,pair<double,int>p2){
            return p1.first > p2.first;
        }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        int m = wt.size();
        double ans = 0;

        vector<pair<double,int>> ratio(n,make_pair(0.0,0));

        for(int i =0; i<n; i++){
            double r = val[i] / (double) wt[i];
            ratio[i] = make_pair(r,i);
        }

        sort(ratio.begin(),ratio.end(),compare);

        for(int i = 0; i<n; i++){
            int idx = ratio[i].second;

            if(wt[idx] <= capacity){
                ans+=val[idx];
                capacity-=wt[idx];
            }
            else{
                ans+=ratio[i].first * capacity;
                capacity = 0;
                break;
            }
        }
        return ans;
    }
};
