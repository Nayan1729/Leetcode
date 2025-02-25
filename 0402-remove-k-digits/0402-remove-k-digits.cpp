class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        if(n==k)return "0";
        stack<char> st;
        for(int i = 0 ; i < n ; i++ ){
            while(!st.empty() && k && s[i] < st.top() ){
                st.pop();
                k--;
            }
            if(!(s[i] == '0' && st.empty())){
                st.push(s[i]);
            }
        }
        // Remove remaining `k` digits if needed
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string ans(st.size(), ' ');
        for(int i = st.size()-1 ; i >=0 ; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans == "" ? "0" : ans ;
    }
};