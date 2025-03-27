class Solution {
public:
    bool canJump(vector<int>& nums) {
       int i  , maxi , sum ,n = nums.size() ;
       for( i = 0 ; i < n ; i++ ){
            if(i > maxi ){
                return false;
            }
            sum = i + nums[i];
            maxi = max (maxi , sum);
       } 
       return true;
    }
};