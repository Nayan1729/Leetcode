class Solution {
public:
    bool isSubsequence(string s, string t) {
        
            if(s=="")return true;
            if(t=="")return false;
            int i,j,k;
            for ( i = 0 ; i < s.size() ; i++ ){
              k=i;
              j=0;
              while(j<s.size() && k<t.size() ){
                if (s[j]==t[k]){
                    j++;
                    if(j==s.size()){
                        return true;
                    }
                }
                k++;
              }
            }
        
        return false;
    }
};