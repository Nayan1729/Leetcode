class Solution {
public: 
    int mini = INT_MAX , maxi = -1;
    void bs(vector<int> a , int l , int h , int k ){
        if(l > h ){
            return;
        }
        int mid = (l + h )/2;
        if( k == a[mid] ){
            mini = min(mid , mini);
            maxi = max(mid , maxi);
            bs(a , l , mid - 1 , k ); // Move to the left
            bs( a , mid + 1 , h , k );   // Move to the right 
            return ;
        }else if(k > a[mid]){
            bs( a , mid + 1 , h , k );
            return ; 
        }else{
            bs(a , l , mid - 1 , k );
            return ; 
        }
    }
      vector<int> searchRange(vector<int>& a, int k) {
        int n = a.size() ;
        bs(a , 0 , n - 1 , k);
        mini = mini == INT_MAX ? -1 : mini;
        return {mini , maxi};
    }
};