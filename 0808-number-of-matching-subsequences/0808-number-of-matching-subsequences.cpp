class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& a) {
        // Correct but gives TLE

        // int i , j , k , currSize , m = s.size() , n = a.size() , count = 0 ;
        // for( i = 0 ; i < n ; i++ ){
        //     k = 0 ; currSize = a[i].size();
        //     for( j = 0 ; j < m ; j++){
        //         if(a[i][k] == s[j]){
        //             k++;
        //             if(k == currSize){
        //                 cout<< a[i];
        //                 count++;
        //                 break; 
        //             }
        //         }
        //     }
        // }
        // return count;
        
        int i , j , k , currSize , m = s.size() , n = a.size() , count = 0 , last;
        unordered_map< char , vector<int>> mp;
        // Push elements of the string in the map
        for( i = 0 ; i < m ; i ++){
            mp[s[i]].push_back(i);
        }
        for( i = 0 ; i < n ; i++ ){
            string curr = a[i]; // Current string vector
            currSize = curr.size();
            last = -1;
            for(j = 0 ; j < currSize ; j++){
                auto itr = upper_bound(mp[curr[j]].begin() , mp[curr[j]].end() , last );
                if(itr == mp[curr[j]].end() )break;
                last = *itr;
                if(j == curr.size()-1)count++;
            }
        }
        return count;
    }
};