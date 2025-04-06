class Solution {
public:
    int maxSatisfied(vector<int>& a, vector<int>& grumpy, int k) {
        int i , n = a.size() , total = 0 , grumpyTotal = 0 , windowTotal = 0 , maxi = 0;
        for( i = 0 ; i < n ; i++){
            total += grumpy[i] == 0 ? a[i] : 0;
            grumpyTotal += grumpy[i] == 0 ? a[i] : 0;
            windowTotal += a[i];

            if(i >= k - 1){
                maxi = max(maxi , windowTotal - grumpyTotal);
                grumpyTotal  -= grumpy[i + 1 - k] == 0 ? a[ i + 1 - k] : 0; 
                windowTotal -= a[i+1 - k];
            }
        }
        return total + maxi;
    }
};