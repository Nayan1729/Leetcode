class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& a) {
        int n = a.size() , i = 0 , odd = 0  ,even = 0;
        vector<int> b(n,0);
        while(i < n){
            while( even < n && a[even] % 2 != 0){
                even++;
            }
            b[i++] = a[even];
            even++;
            while( odd < n && a[odd] % 2 == 0 ){
                odd++;
            }
            b[i++] = a[odd];
            odd++;
        }
        return b;
    }
};