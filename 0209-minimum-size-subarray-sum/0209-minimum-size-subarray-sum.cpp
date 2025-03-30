class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int l = 0 , r = 0 , mini  = INT_MAX , n = a.size() , sum = 0;
        while( r < n ){
            sum += a[r] ;
            while (sum >= target){
                mini = min(mini , r-l+1 );
                sum -= a[l];
                l++;
            }
            r++;
        }
        return mini == INT_MAX ? 0 : mini ;
    }
};