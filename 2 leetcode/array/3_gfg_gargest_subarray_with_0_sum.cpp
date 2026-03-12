/*Largest subarray with 0 sum
Difficulty: MediumAccuracy: 41.84%Submissions: 457K+Points: 4Average Time: 20m
Given an array arr[] containing both positive and negative integers, the task is to find the length of the longest subarray with a sum equals to 0.

Note: A subarray is a contiguous part of an array, formed by selecting one or more consecutive elements while maintaining their original order.

Examples:

Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7].
Input: arr[] = [2, 10, 4]
Output: 0
Explanation: There is no subarray with a sum of 0.
Input: arr[] = [1, 0, -4, 3, 1, 0]
Output: 5
Explanation: The longest subarray with sum equals to 0 is [0, -4, 3, 1, 0]
Constraints:
1 ≤ arr.size() ≤ 106
−103 ≤ arr[i] ≤ 103

*/


// this code is O(n^2)

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        int longest=0;
        for(int st=0; st<n; st++){
            int currsum=0;
            for(int end=st; end<n; end++){
                currsum += arr[end];

                if(currsum==0){
                    longest=max(end-st+1,longest);
                }
            }
        }
        return longest;
        
    }
};





//optimezed code 



class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>m;
        int sum=0; 
        int longest=0;
        for(int i =0; i<n; i++){
            sum += arr[i];

            if(sum==0){
                longest = i+1;
            }
            
            if(m.find(sum)!=m.end()){      // if sum is exist in m then true
                longest = max(longest,i-m[sum]);
            }   
            else{
                m[sum]=i;
            }
        }
        return longest;
    }
};