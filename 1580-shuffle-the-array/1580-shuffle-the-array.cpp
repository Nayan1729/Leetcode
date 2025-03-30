class Solution {
public:
    vector<int> shuffle(vector<int>& a, int n) {
        int l = 0 , r = n;
        vector<int> v;
        while(l < n){
            v.push_back(a[l]);
            v.push_back(a[r]);
            l++;
            r++;
        }
        return v;
    }
};