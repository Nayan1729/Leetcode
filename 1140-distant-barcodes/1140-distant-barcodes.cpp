class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int i , j ,  maxi = 0 , n = barcodes.size() ;
        int maxNum ;
        if(n == 1 )return barcodes;
        map<int,int>mp;
        for( i = 0 ; i < n ; i++ ){
            int currChar = barcodes[i];
            mp[currChar]++;
            if(mp[currChar] > maxi){
                maxi = mp[currChar];
                maxNum = currChar;
            }
        }
        cout<<maxi;
        int index = 0;
        // Arrange max in alternating postions
        while(maxi--){
            barcodes[index] = maxNum;
            index+=2;
            // If value exists then the maximum will be less than n / 2 
        }
        mp.erase(maxNum);
        for( auto itr = mp.begin() ; itr != mp.end() ; itr++ ){
            
            int count = itr->second , val = itr->first ;
            while(count--){
                if(index  >= n ){ // all odd alternate places are filled 
                    index = 1;
                }
                barcodes[index] = val ;
                index+=2;
            }
        }
    return barcodes;
    }
};