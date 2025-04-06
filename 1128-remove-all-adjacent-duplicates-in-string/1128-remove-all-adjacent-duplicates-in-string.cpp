class Solution {
public:
    string removeDuplicates(string s) {
        int i , n = s.size() ;
        stack<char> st;
        for( i = 0 ; i < n ; i++){
            if(!st.empty() && st.top() == s[i] ){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        int k = st.size();
        string str =  string(k , ' ');
        k--;
        while(!st.empty()){
            str[k] = st.top();
            st.pop();
            k--;
        }
        return str;
    }
};