class Solution {
public:
    long long subArrayRanges(vector<int>& a) {
        int n = a.size() , sum=0; 
        for(int i=0;i<n;i++){
            int maxx = a[i] , minn  = a[i];
            for(int j = i ; j < n ;j++){
                    maxx = max(maxx , a[j]);
                    minn = min(minn , a[j]);
                    sum += (maxx - minn);
            }
        }
        return sum;
    }
};