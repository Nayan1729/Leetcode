class Solution {
public:
    int strStr(string a, string b) {
       int m = a.size() , n = b.size() , i , j , k;
       for(i = 0 ; i < m ; i++){
            k = i;
            for(j = 0 ; j < n ; j++){
                if(a[k]!=b[j]){
                    break;
                }
                k++;
            }
            if(j == n){
                return i;
            }
       }
       return -1;
    }
};