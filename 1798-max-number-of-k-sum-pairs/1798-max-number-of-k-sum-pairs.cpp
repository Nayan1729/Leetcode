class Solution {
public:
    int maxOperations(vector<int>& a, int k) {
        // unordered_map<int , int> mp;
        // int i , count = 0 , n = a.size() ;
        // for( i = 0 ; i < n ; i++){
        //     int curr = a[i];
        //     // If u find the better half and its count is also more than 0
        //     if( mp.find(k - curr) != mp.end() && mp[k-curr] > 0 ){ 
        //         mp[k - curr]--;
        //         count++;       
        //     }// If u cant find then increase the count 
        //     else{
        //             mp[curr]++;
        //     }
        // }
        // return count;

        int left = 0 , n = a.size() , right = n - 1 , count = 0 ;
        sort(a.begin(),a.end());
        while ( left < right ){
            if(a[left]+ a[right] == k ){
                left++;
                right--;
                count++;
            }else if(a[left]+ a[right] > k ){
                right--;
            }else{
                left++;
            }
        }
        return count;
    }
};