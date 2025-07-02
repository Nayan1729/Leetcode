class Solution {
public:
    int leastBricks(vector<vector<int>>& a){
        int maxi = 0;
        int m = a.size() ;
        unordered_map<long long , int > mp;
        for( int i = 0 ; i < m ; i++ ){
            long long prefixSum = 0;
            int n = a[i].size();
            for ( int j = 0 ; j < n - 1 ; j++){
                prefixSum += a[i][j]; // Idea is to find the prefixSum so that u can very easily get the 
                maxi = max(maxi , ++mp[prefixSum]);
            }
        }
        return m - maxi;
    }
};