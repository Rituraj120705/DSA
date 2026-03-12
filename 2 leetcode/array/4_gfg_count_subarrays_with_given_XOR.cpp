/*Count Subarrays with given XOR
Difficulty: MediumAccuracy: 58.86%Submissions: 86K+Points: 4
Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

Note: It is guranteed that the total count will fit within a 32-bit integer.

Examples: 

Input: arr[] = [4, 2, 2, 6, 4], k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.
Input: arr[] = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. Hence, the answer is 2.
Input: arr[] = [1, 1, 1, 1], k = 0
Output: 4
Explanation: The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105
0 ≤ k ≤ 105*/
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int,int>m;
        m[0]=1;

        int count=0;
        int xr=0;
        for(int i =0; i<n; i++){
            xr = xr ^ arr[i];
            int x = xr ^ k;

            if(m.find(x)!=m.end()){
                count += m[x];
            }
            
            m[xr]++;
        }
        return count;
        
    }
};


// best method 

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int,int>m;
        
        int count =0;
        int xr=0;
        m[xr]++;
        for(int i =0; i<n; i++){
            xr= xr^arr[i];
            int x = xr ^ k;

            count += m[x];
            m[xr]++;
        }
        return count;
    }
};
