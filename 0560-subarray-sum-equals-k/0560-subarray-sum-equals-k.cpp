class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
       int i , count = 0, preSum = 0;
       unordered_map<int , int> mp; // sum , count
       mp[0] = 1; //  Add 0  to the map 
       for(i=0 ; i < a.size() ;i++ ){
            preSum += a[i]; // Find PreSum on the go 
             
            int remainingSum  = preSum - k;
            // Check if the remaining sum exists
            if(mp.find(remainingSum) != mp.end() ){
                count += mp[remainingSum];
            }
            
            // Add prefixSum to the map
            if(mp.find(preSum ) != mp.end() ){
                mp[preSum]++;
            }else{
                mp[preSum] = 1;
            }
       }
       return count;
    }
};