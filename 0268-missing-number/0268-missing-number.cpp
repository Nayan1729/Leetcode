class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Sorting method
        // sort(nums.begin(),nums.end());
        // int i=0;
        // while(i<nums.size()){
        //     if(nums[i]!=i){
        //         return i;
        //     }
        //     i++;
        // }
        // return i;
        int n = nums.size() , xorNum = 0;
        for( int i = 0 ; i < n + 1  ; i++){
            if(i == n){
                xorNum ^= n;
                continue;
            }
            xorNum ^= nums[i] ^ i;
        }
        return xorNum;
    }
};