class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int i,j,k,m=a.size() , n = a[0].size() ;
        for(i=0;i<m;i++){
            for(j=i;j<n;j++){
                swap(a[i][j],a[j][i]);
            }
        }
        for(j=0;j<n/2;j++){
            for(i=0;i<a.size();i++){
                swap(a[i][j],a[i][m-1-j]);
            }
        }
    }
};