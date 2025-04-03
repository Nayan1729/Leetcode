class Solution {
public: 
    // int mini = INT_MAX , maxi = -1;
    // void bs(vector<int> a , int l , int h , int k ){
    //     if(l > h ){
    //         return;
    //     }
    //     int mid = (l + h )/2;
    //     if( k == a[mid] ){
    //         mini = min(mid , mini);
    //         maxi = max(mid , maxi);
    //         bs(a , l , mid - 1 , k ); // Move to the left
    //         bs( a , mid + 1 , h , k );   // Move to the right 
    //         return ;
    //     }else if(k > a[mid]){
    //         bs( a , mid + 1 , h , k );
    //         return ; 
    //     }else{
    //         bs(a , l , mid - 1 , k );
    //         return ; 
    //     }
    // }
    //   vector<int> searchRange(vector<int>& a, int k) {
    //     int n = a.size() ;
    //     bs(a , 0 , n - 1 , k);
    //     mini = mini == INT_MAX ? -1 : mini;
    //     return {mini , maxi};
    // }

    // Optimised
    
    
    int firstOccurrence(vector<int>& a, int k) {
        int l = 0, h = a.size() - 1, first = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (a[mid] == k) {
                first = mid;
                h = mid - 1; // Move left to find earlier occurrence
            } else if (a[mid] < k) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return first;
    }
    
    int lastOccurrence(vector<int>& a, int k) {
        int l = 0, h = a.size() - 1, last = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (a[mid] == k) {
                last = mid;
                l = mid + 1; // Move right to find later occurrence
            } else if (a[mid] < k) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return last;
    }
    
    vector<int> searchRange(vector<int>& a, int k) {
        return {firstOccurrence(a, k), lastOccurrence(a, k)};
    }
};