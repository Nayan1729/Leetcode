class Solution {
public:
    double myPow(double x, int n) {
        if(n==1)return x;
        if(x==1 || n == 0 )return 1;
        long long nn = n;
        double ans = 1;
        if(nn<0){
            x = 1/x;
            nn= -1 * nn;
        }
        while(nn){
            if(nn%2==0){
                x = x * x;
                nn = nn/2;
            }else{
                ans = x * ans ;
                nn = nn-1;
            }
        }
        return ans;

    //    if(n==0){
    //     return ans;
    }
};