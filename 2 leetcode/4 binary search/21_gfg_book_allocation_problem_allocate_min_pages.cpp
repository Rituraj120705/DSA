/*Allocate Minimum Pages
Difficulty: MediumAccuracy: 35.51%Submissions: 379K+Points: 4Average Time: 35m
Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: If it is not possible to allocate books to all students, return -1.

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i], k ≤ 103

*/

class Solution {
  public:
    bool ispossible(vector<int>&arr,int mid,int k){    // mid here max allocated page 
        int n = arr.size();
        int stu = 1; 
        int page = 0;

        for(int i = 0; i<n; i++){
            if(arr[i]>mid)return false;
            if(page+arr[i]<=mid){
                page+=arr[i];
            }
            else{
                stu++;
                page=arr[i];
            }
        }
        if(stu>k)return false;
        else{
            return true;
        }
    }





    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        int ans = -1;

        int st = 0; 
        int end = accumulate(arr.begin(),arr.end(),0);

        while(st<=end){
            int mid = (st+end)/2;
            if (n<k)return -1;

            if(ispossible(arr,mid,k)){
                ans = mid;
                end= mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
        
    }
};