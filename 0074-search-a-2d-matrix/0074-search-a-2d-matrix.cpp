class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int k) {
        // int i = 0 , n = a.size() , m = a[0].size() ,l = 0 ,r = m - 1;
        // for(;i < n ; i++ ){
        //     if(k < a[i][l]){
        //         return false;
        //     }
        //     if( !(k >= a[i][l] && k <= a[i][r])){
        //         continue;
        //     }
        //     // Binary search to find the array
        //     while(l <= r){
        //         int mid = (l + r)/2;
        //         if(k == a[i][mid]){
        //             return true;
        //         }else if(k > a[i][mid]){
        //             l = mid + 1;
        //         }else{
        //             r = mid - 1;
        //         }
        //     }
        // }
        // return false;
        // Imagine like a 1D array
         int i = 0 , n = a.size() , m = a[0].size() ,l = 0 , r = m *n - 1 , row , col;
         while(l <= r){
                int mid = (l + r)/2;
                 row = mid / m ;
                 col = mid % m;
                if(k == a[row][col]){
                    return true;
                }else if(k > a[row][col]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            return false;
    }
};