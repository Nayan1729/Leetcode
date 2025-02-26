class Solution {
public:
    int getSubArrayLessCount(vector<int>& a , int goal){
        if(goal <0 ) return 0;

        int l=0 , r=0 , ans = 0,sum=0;
        while( r < a.size()){
            sum += a[r];
            while(sum > goal && l < a.size() ){
                sum -= a[l];
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int c1 = getSubArrayLessCount(nums , goal);
        int c2 = getSubArrayLessCount(nums , goal - 1);
        return c1 - c2;
    }   
};