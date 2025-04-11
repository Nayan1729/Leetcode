class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int i , n = a.size();
        vector<int>ans(n,0);
        stack<pair<int,int>>st;
        for( int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && a[i] >= st.top().first ){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top().second - i ;
            }
            st.push({a[i],i});
        }
        return ans;
    }
};