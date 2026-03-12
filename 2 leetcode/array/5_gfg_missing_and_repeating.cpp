/*Missing And Repeating
Difficulty: EasyAccuracy: 24.83%Submissions: 688K+Points: 2Average Time: 30m
Given an unsorted array arr[] of size n, containing elements from the range 1 to n, it is known that one number in this range is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.

Examples:

Input: arr[] = [2, 2]
Output: [2, 1]
Explanation: Repeating number is 2 and the missing number is 1.
Input: arr[] = [1, 3, 3] 
Output: [3, 2]
Explanation: Repeating number is 3 and the missing number is 2.
Input: arr[] = [4, 3, 6, 2, 1, 1]
Output: [1, 5]
Explanation: Repeating number is 1 and the missing number is 5.
Constraints:
2 ≤ n ≤ 106
1 ≤ arr[i] ≤ n*/


class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int>result(2);

        sort(arr.begin(),arr.end());
        

        if(arr[0]!=1){
            result[1] = 1;
        }
        if(arr[n-1] != n){
            result[1]=n;
        }

        for(int i =1; i<n; i++){
            int dif = arr[i]-arr[i-1];

            if(dif==0){
                result[0]=arr[i];
            }
            if(dif > 1){
                result[1]=arr[i]-1;
            }
        }
        return result;
        
    }
};