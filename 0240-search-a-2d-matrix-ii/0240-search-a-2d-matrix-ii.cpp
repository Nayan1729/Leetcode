class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int k) {
        int i , j , mid , l , r , m = a.size() , n = a[0].size();
        for(i= 0 ; i < m ; i++){
            l = 0 ,  r = n - 1;
            while(l <=r){
                mid = (l + r)/2;
                if(k == a[i][mid]){
                    return true;
                }else if(k > a[i][mid]){
                    l = mid+1;
                }else{
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};