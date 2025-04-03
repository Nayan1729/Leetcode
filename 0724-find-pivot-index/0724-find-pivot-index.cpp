class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int i = 1 , n = a.size() , j = n - 2;
        vector<int>prefixSum(n , 0 ), suffixSum(n , 0 );
        while(i < n ){
            prefixSum[i] = prefixSum[i-1] + a[ i - 1];
            suffixSum[j] = suffixSum[j+1] + a[j+1];
            j--; i++;
        }
        for(i= 0 ; i < n ; i++){
            if(prefixSum[i]==suffixSum[i]){
                return i;
            }
        }
        return -1;
    }
};