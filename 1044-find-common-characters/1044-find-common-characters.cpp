class Solution {
public:
    vector<string> commonChars(vector<string>& a) {
        int i , j , n = a.size();
        vector<int> common(26,INT_MAX);
        vector<string> ans;
        for(i = 0 ; i < n ;i++ ){
            int m = a[i].size();
            vector<int>current(26 , 0);
            for(j = 0 ; j < m ; j++){
                current[a[i][j] - 'a']++;
            }
            for( int k = 0 ; k < 26 ; k++){
                common[k] = min(common[k] , current[k]);
            }
        }
        for( i = 0 ; i < 26 ; i++){
            if(common[i]){
                for(j = 0 ; j < common[i];j++){
                    ans.push_back (string(1, i + 'a'));
                }
            }
        } 
        return ans;
    }
};