class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size() , i= n-1 , j , k , nextMax;
        if(n == 1)return ;
        while(i >= 1 && a[i] <= a[i-1] ){
            i--;
        }
        if(i==0){
            sort(a.begin() , a.end());
            return ;
        }
        i--;
        j = i + 1 , k=j;
        nextMax = a[j];
        while( j < n ){
            if(a[j] > a[i] && a[j] < nextMax ){
                nextMax = a[j];
                k = j;
            }
            j++;
        }
        swap( a[k] , a[i] );
        sort(a.begin() + i + 1 , a.end());
    }
};