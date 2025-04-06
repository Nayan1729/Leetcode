class Solution {
public:
    string longestPalindrome(string s) {
          int i , j , maxi = INT_MIN , k , n = s.size();
          string str="";
          if(n == 1)return s;
          for( i = 0 ; i < n ; i++){
                // Odd
                k = 1; 
                while(i - k >= 0  && i + k < n ){
                    if(s[i- k] != s[i+k]){
                        break;
                    }
                    if(maxi < 2*k + 1){
                        maxi = 2*k + 1;
                        str = s.substr(i - k , 2*k +1 );
                        cout << i;
                    }
                    k++;
                }

                // Even 
                
                if( i < n - 1 && s[i] == s[i+1] ){
                    k = 0 ;
                    while(i - k >= 0 &&  (i + 1) + k < n){
                        if(s[i - k ] != s[i + 1 + k ]){
                            break;
                        }
                        if(maxi < 2*k + 2){
                            maxi = 2*k + 2;
                            str = s.substr( i - k , 2*k + 2 );
                        }
                        k++;
                    }
                }
          }
          return str == "" ? string(1 , s[0]) : str ;
    }
};