class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int i,j,k,n=a.size();
        for(i=0;i<n;i++){
            for(j=i;j<a[0].size();j++){
                swap(a[i][j],a[j][i]);
            }
        }
        for(j=0;j<(a[0].size())/2;j++){
            for(i=0;i<a.size();i++){
                swap(a[i][j],a[i][n-1-j]);
            }
        }
    }
};