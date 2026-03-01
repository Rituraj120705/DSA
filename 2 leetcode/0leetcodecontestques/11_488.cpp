class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        
        vector<long long>result;

        for(auto num : nums){
            result.push_back(num);
        

        while(result.size()>=2){
            int n = result.size();

            if(result[n-1] == result[n-2]){
                long long add = result[n-1] + result[n-2];

                result.pop_back();
                result.pop_back();

                result.push_back(add);
            }
            else{
                break;
            }
        }
    }
        return result;
    }
};