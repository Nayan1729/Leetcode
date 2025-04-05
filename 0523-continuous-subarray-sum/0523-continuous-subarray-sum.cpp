class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        // Gives TLE
        // int i  , j , sum , prefixSum  = 0 ,n = a.size() ;
        // unordered_map<int , int >mp; // sum , index
        // mp[0] = -1;
        // for( i = 0 ; i < n ; i++ ){
        //     prefixSum += a[i];
        //     sum = prefixSum ;
        //     while(sum >= 0 ){
        //         if(mp.find(sum) != mp.end() ){
        //             if( i - mp[sum]>1)
        //             return true;
        //         }
        //         sum -= k;
        //     }
        //     if(mp.find(prefixSum) == mp.end()){
        //         mp[prefixSum] = i;
        //     }
        // }
        // return false;

        int i  , j , sum , prefix  = 0 ,n = a.size() , mod  ;
        unordered_map<int , int >mp; // sum % k , index
        mp[0] = -1;
        for( i = 0 ; i < n ; i++){
            prefix += a[i];
            mod = prefix % k;
            if(mp.find(mod) != mp.end()){
                if(i - mp[mod] >=2){
                    return true;
                }else{
                    continue;
                }
            }
            mp[mod] = i;
        }
        return false;
    }   
};