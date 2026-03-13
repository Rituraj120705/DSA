class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int n = nums.size();
       
       int st=0;
       int end=n-1;
       
       while(st<=end){
          int mid = (st+end)/2;
          if(nums[mid]==target)return true;

          if(nums[st]<=nums[mid]){
            if(target>=nums[st] && target<=nums[mid]){
                end = mid-1;
            }
            else{
                st = mid +1;
            }
          }
          else{
            if(target>=nums[mid] && target<= nums[end]){
                st = mid +  1;
            }
            else{
                end = mid-1;
            }
          }
       }
       return false;
    }
};
