class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int i , j;
        int m = a.size() , n = b.size();
        set<int> s;
        vector <int> res;
        for(i = 0 ; i < m ; i++){
            for(j=0;j<n;j++){
                if(a[i]==b[j]){
                    s.insert(a[i]);
                }
            }
        }
        for(auto it = s.begin(); it != s.end(); it++){
            res.push_back(*it);
        }
        return res;
    }
};