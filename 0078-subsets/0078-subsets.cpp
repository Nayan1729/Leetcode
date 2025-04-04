class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        int i , j , n  = a.size() ; 
        vector<vector<int>>ans;
        for( i = 0 ; i < ( 1 << n  ) ; i++ ){
            vector<int> v;
            for(j = 0 ; j < n ; j++){
                if( i >> j & 1  ){
                    v.push_back(a[j ]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};