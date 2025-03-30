class Solution {
public:
    double findMaxAverage(vector<int>& a, int k) {
        int n = a.size();
        double maxi = INT_MIN, avg , sum=0;
        for( int i = 0 ;  i < n ; i++){
            sum += a[i];

            if( i >= k - 1){
                avg = sum *1.0 / k ;
                if(maxi < avg){
                    maxi = avg;
                }
                sum -=a[ i + 1 - k ];
            }
        }
        return maxi;
    }
};