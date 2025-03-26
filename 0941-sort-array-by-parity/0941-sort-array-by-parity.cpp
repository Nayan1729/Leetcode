class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size() , i, j=0;
        vector<int>  a;
        for(i=0 ; i<n ; i++){
            if(nums[i]%2 == 0){
                a.push_back(nums[i]);
            }
        }
        for(i=0 ; i<n ; i++){
            if(nums[i]%2 == 1){
                a.push_back(nums[i]);
            }
        }
        return a;
    }
};