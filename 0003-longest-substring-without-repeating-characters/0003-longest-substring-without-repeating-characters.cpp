class Solution {
public:
    int lengthOfLongestSubstring(string a) {
        unordered_map< int , int> mp ;
        int l = 0 , r = 0 , n = a.size() , maxi = 0 ;
        while(r < n){
            while(mp.find(a[r]) != mp.end() && mp[a[r]] == 1 ){
                mp[a[l]]--;
                l++;
            }
            mp[a[r]] = 1;
            maxi = max(maxi , r - l + 1);
            r++;
        }
        return maxi;
    }
};