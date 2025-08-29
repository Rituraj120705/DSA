/*435. Non-overlapping Intervals
Solved
Medium
Topics
premium lock icon
Companies
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104
 
*/




class Solution {
public:
    bool compare(pair<int,int>p1,pair<int,int>p2){
        return p1.second < p2.second;
    }


   int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0){
            return 0;
        }

       // int count = 1;
        sort(intervals.begin() ,     intervals.end() , compare);
        int count = 1;
        int currEndtime = intervals[0][1];

        for(int i = 1; i<n; i++){
            if(intervals[i][0] >= currEndtime){
                count = count+1;
                currEndtime = intervals[i][1];
            }
        }
        return n-count;


    }
};












class Solution {
public:
   static bool compare(const vector<int>&p1,const vector<int>&p2){
        return p1[1]< p2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0){
            return 0;
        }

       // int count = 1;
        sort(intervals.begin() , intervals.end() , compare);
        int count = 1;
        int currEndtime = intervals[0][1];

        for(int i = 1; i<n; i++){
            if(intervals[i][0] >= currEndtime){
                count = count+1;
                currEndtime = intervals[i][1];
            }
        }
        return n-count;

    }
};