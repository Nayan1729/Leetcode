class Solution {
public:
    
    int getCountOfOdd(vector<int> & a , int k ){
                
        int l = 0 , r = 0 , oddCount = 0, n = a.size();
        long long total = 0;
        while( r < n){
            if(a[r] & 1 == 1 ){
                oddCount++;
            }
            while(oddCount > k && l<n){
                if(a[l] & 1 == 1){
                    oddCount--;
                }
                l++;
            }
            total += r - l + 1 ;  
            r++;
        }
        return total;
    }
    int numberOfSubarrays(vector<int>& a, int k) {
        int total1 = getCountOfOdd(a , k);
        int total2 = getCountOfOdd(a , k-1);
        return total1 - total2;
    }
};