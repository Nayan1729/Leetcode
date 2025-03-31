class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        int n = a.size() , count = 0 ;
        unordered_set<int> s;
        sort(a.begin() , a.end());
        for ( int i = 0 ; i < n ; i++){
            if( i > 0 && k == 0 && i < n - 1 && a[i] == a[i-1] && a[i] == a[i+1] ){
                cout<<"Ignored : "<< i ;
                continue;
            }
            if( i > 0 && a[ i ] == a[i-1] && k != 0){
                continue;
            }
           
            int absVal1 = a[i] - k , absVal2 = a[i] + k;
            if(s.find(absVal1) != s.end()){
                cout << "val1 : " << a[i] <<" ";
                count++;
            }
            if(s.find(absVal2) != s.end() && absVal1 != absVal2){
                cout << "val2 : " << a[i] <<" ";
                count++;
            }
            s.insert(a[i]);
        }
        return count;
    }
};