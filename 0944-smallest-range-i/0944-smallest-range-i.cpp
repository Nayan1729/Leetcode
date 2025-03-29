class Solution {
public:
    int smallestRangeI(vector<int>& a, int k) {
        // we want to minimise max - min by performing the operation . THis is what the question is saying
        int n = a.size() , maxi =INT_MIN , mini = INT_MAX;
        for(int i=0;i<n;i++){
            maxi  = max( a[i] , maxi );
            mini  = min( a[i] , mini );
        }
        while(k--){
            mini +=1;
            maxi -=1;
            if(mini >= maxi){
                return 0;
            }
        }
        return maxi - mini;
    }
};