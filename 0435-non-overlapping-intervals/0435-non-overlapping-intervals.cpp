class Solution {
public:
static bool cmp (vector<int>a , vector<int>b){
            return a[1] < b[1]; // then only swap
        }
    int eraseOverlapIntervals(vector<vector<int>>& a ) {
        
        int i , j , count = 0 , curr = 1 , prev = 0 , n = a.size();
        sort( a.begin(),a.end() , cmp );
        for( ; curr < n ; curr++ ){
            if( a[prev][1] > a[curr][0] ){
                count++;
            }else{
                prev = curr;
            }
        }
        return count;
    }
};