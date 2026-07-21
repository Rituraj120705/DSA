Sort Elements by Decreasing Frequency




Solved
Difficulty: MediumAccuracy: 44.93%Submissions: 166K+Points: 4Average Time: 60m
Given an array of integers arr[], sort the array according to the frequency of elements, i.e. elements that have higher frequency comes first. If the frequencies of two elements are the same, then the smaller number comes first.

Examples :

Input: arr[] = [5, 5, 4, 6, 4]
Output: [4, 4, 5, 5, 6]
Explanation: The highest frequency here is 2. Both 5 and 4 have that frequency. Now since the frequencies are the same the smaller element comes first. So 4 4 comes first then comes 5 5. Finally comes 6. The output is 4 4 5 5 6.
Input: arr[] = [9, 9, 9, 2, 5]
Output: [9, 9, 9, 2, 5]
Explanation: The highest frequency here is 3. Element 9 has the highest frequency So 9 9 9 comes first. Now both 2 and 5 have the same frequency. So we print smaller elements first. The output is 9 9 9 2 5.

Constraints:

1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
Expected Complexities
Company Tags
OracleZycus
Topic Tags
Related Interview Experiences
Related Articles




class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        unordered_map<int,int>freq;
        
        for(auto num : arr){
            freq[num]++;
        }
        
        auto cmp = [&](int a , int b){
            if(freq[a] != freq[b]){
                return freq[a] > freq[b];
            }
            
            return a < b;
        };
        
        sort(arr.begin(),arr.end(),cmp);
        
        return arr;
    }
};


