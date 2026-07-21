/*First and Second Smallests
Difficulty: EasyAccuracy: 24.44%Submissions: 184K+Points: 2
Given an array, arr[] of integers, your task is to return the smallest and second smallest element in the array. If the smallest and second smallest do not exist, return -1.

Examples:

Input: arr[] = [2, 4, 3, 5, 6]
Output: [2, 3] 
Explanation: 2 and 3 are respectively the smallest and second smallest elements in the array.
Input: arr[] = [1, 1, 1]
Output: [-1]
Explanation: Only element is 1 which is smallest, so there is no second smallest element.
Constraints:
1 ≤ arr.size ≤105
1 ≤ arr[i] ≤ 105

Expected Complexities
Company Tags
AmazonGoldman SachsNPCI
Topic Tags
Related Articles
*/



class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        // code here
        int n = arr.size();
        int min = INT_MAX;
        int secondmin = INT_MAX;
        
        for(int i =0; i<n; i++){
            if(arr[i] < min){
                secondmin = min;
                min = arr[i];
            }
            
            else if(arr[i] > min && arr[i] < secondmin){
                secondmin = arr[i];
            }
        }
        if(secondmin == INT_MAX){
            return {-1};
        }
        
        return {min,secondmin};
    }
};