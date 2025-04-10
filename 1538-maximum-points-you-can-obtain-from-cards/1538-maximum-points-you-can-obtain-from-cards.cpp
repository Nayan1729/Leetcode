class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int i , n = a.size()  , sum = 0 , maxi , m = k - 1;
        for( i = 0 ; i < k ; i++){
            sum += a[i];
        }
        maxi = sum;
        // m is the index to remove from the left and i the index to add from the right
        for( i = 0 ; i < k ; i++ ){
            sum = sum - a[m] + a[n - 1 - i ];
            maxi = max(sum , maxi);
            cout << i << ": " << sum <<endl;
            m--;
        }
        return maxi;
    }
};