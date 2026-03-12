/*Count Inversions
Difficulty: MediumAccuracy: 16.93%Submissions: 760K+Points: 4
Given an array of integers arr[]. You have to find the Inversion Count of the array. 
Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104*/

//brute force approach

class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        int count =0;
        for(int i =0; i<n; i++){
            for(int j=1; j<n; j++){
                if(arr[i]>arr[j]){
                    count++;
                }
            }
        }
    return count;
    }
};





//apna college approach 

int merge(vector<int>&arr,int st,int mid,int end){
    vector<int>temp;
    int i = st,j=mid+1;
    int invCount = 0;

    while(i<=mid && j<= end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
            intCount += (mid-i+1);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int  idx=0; idx<temp.size(); idx++){
        arr[idx+st] = temp[idx];
    }

    retutn invCount;
}

int mergeSort(vector<int>&arr,int st, int end){
    if(st<end){
        int mid = st + (end-st)/2;

        int leftInvCount = mergeSort(arr,st,mid);
        int rightInvCount= mergeSort(arr,mid+1,end);

        int invCount = merge(arr,st,mid,end);

        return leftInvCount + rightInvCount + invCount;
    }
}





// runnable approach in gfg
class Solution {
  public:

    int merge(vector<int>&arr,int st,int mid,int end){
        vector<int>temp;
        int i = st, j = mid + 1;
        int invCount = 0;

        while(i <= mid && j <= end){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                temp.push_back(arr[j]);
                j++;
                invCount += (mid - i + 1);
            }
        }

        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }

        while(j <= end){
            temp.push_back(arr[j]);
            j++;
        }

        for(int idx = 0; idx < temp.size(); idx++){
            arr[idx + st] = temp[idx];
        }

        return invCount;
    }

    int mergeSort(vector<int>&arr,int st,int end){
        if(st >= end)
            return 0;

        int mid = st + (end - st) / 2;

        int leftInvCount = mergeSort(arr, st, mid);
        int rightInvCount = mergeSort(arr, mid + 1, end);

        int invCount = merge(arr, st, mid, end);

        return leftInvCount + rightInvCount + invCount;
    }

    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return mergeSort(arr,0,n-1);
    }
};