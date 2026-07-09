Number of greater elements to the right

Difficulty: MediumAccuracy: 56.74%Submissions: 53K+Points: 4Average Time: 10m
Given an array of arr[] and Q queries of indices. For each query indices[i], determine the count of elements in arr that are strictly greater than arr[indices[i]] to its right (after the position indices[i]).

Examples :

Input: arr[] = [3, 4, 2, 7, 5, 8, 10, 6], queries = 2, indices[] = [0, 5]
Output:  [6, 1]
Explanation: The next greater elements to the right of 3(index 0) are 4,7,5,8,10,6. The next greater elements to the right of 8(index 5) is only 10.
Input: arr[] = [1, 2, 3, 4, 1], queries = 2, indices[] = [0, 3]
Output:  [3, 0]
Explanation: The count of numbers to the right of index 0 which are greater than arr[0] is 3 i.e. (2, 3, 4). Similarly, the count of numbers to the right of index 3 which are greater than arr[3] is 0, since there are no greater elements than 4 to the right of the array.
Constraints:
1 ≤ N ≤ 104
1 ≤ arr[i] ≤ 105
1 ≤ queries ≤ 100
0 ≤ indices[i] ≤ N - 1

Expected Complexities
Time Complexity: O(N * queries)
Auxiliary Space: O(queries)


class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        vector<int> ans;

        for(int i : indices){
            int count = 0;

            for(int j = i+1; j<n; j++){
                if(arr[j] > arr[i]){
                    count++;
                }
            }

            ans.push_back(count);
        }

        return ans;
        
    }
};