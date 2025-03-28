class Solution {
public:
    int maxOperations(vector<int>& a, int k) {
        unordered_map<int , int> mp;
        int i , count = 0 , n = a.size() ;
        for( i = 0 ; i < n ; i++){
            int curr = a[i];
            if( mp.find(k - curr) != mp.end() && mp[k-curr] > 0  ){
                mp[k - curr]--;
                count++;
            }else{
                if(mp.find(curr) != mp.end() ){
                    mp[curr]++;
                }else{
                    mp[curr] = 1;
                }
            }
        }
        return count;
    }
};