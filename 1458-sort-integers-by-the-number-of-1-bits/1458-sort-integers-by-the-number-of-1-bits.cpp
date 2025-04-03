class Solution {
public:
    vector<int> sortByBits(vector<int>& a) {
        int i , n = a.size() , count , num;
        vector<pair<int , int>>s;
        vector<int>ans;
        for( i = 0 ; i < n ; i++){
            count = 0 , num = a[i] ;
            while(num != 0 ){
                if( num & 1){
                    count++;
                }
                num = num >> 1;
            }
            s.push_back({count , a[i]});
        }
        sort(s.begin() , s.end());
        for( i = 0 ; i < n ; i++ ){
            ans.push_back(s[i].second);
        }
        return ans;
    }
};