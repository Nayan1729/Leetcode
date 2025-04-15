class Solution {
public:
bool isPossible(vector<int> a , int dayCount , int m , int k){
            int count = 0;
            int bouquetCount = 0;

            for (int i = 0; i < a.size(); i++) {
                if (a[i] <= dayCount){
                    count++;
                    if (count == k) { // Counting consecutive bloomed flowers
                        bouquetCount++;
                        count = 0;  // reset after one bouquet completed
                    }
                } else {
                    count = 0;  // reset if not bloomed and try the next one
                }
            }
            if (bouquetCount >= m) return true;
            return false;
    }
    int minDays(vector<int>& a, int m, int k) {
       // Gives TLE
      /*  int n = a.size();
        if (m * k > n) return -1;

        int dayCount = 1;

        while (true) {
            int count = 0;
            int bouquetCount = 0;

            for (int i = 0; i < n; i++) {
                if (a[i] <= dayCount) {
                    count++;
                    if (count == k) {
                        bouquetCount++;
                        count = 0;  // reset after one bouquet completed
                    }
                } else {
                    count = 0;  // reset if not bloomed and try the next one
                }
            }

            if (bouquetCount >= m) return true;

            dayCount++;
        }

        return -1;
      */
        if ( m * 1LL * k * 1LL > a.size()) return -1;
        int minDay = a[0] , maxDay = a[0]; 
        for(int i = 0 ; i < a.size(); i++){
            maxDay = max(maxDay , a[i]);
            minDay = min(minDay , a[i]);
        }
        // B.S
        int l = minDay , h = maxDay;
        while( l <= h ){
            int mid = (l + h)/2;
            if(isPossible(a,mid, m , k)){
                h = mid - 1;
            }else{
                l = mid + 1 ;
            }
        }
        return l;
    }
};
