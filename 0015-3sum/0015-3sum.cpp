class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        // This will give TLE for 1 case
        // set <vector<int>> hashset ;
        // unordered_set <int> st;
        // int n = a.size();
        // for(int i = 0 ; i < n ; i++ ){
        //     st.erase(st.begin(),st.end());
        //     for(int j = i+1 ; j < n ; j++){
        //         int sum = -(a[i] + a[j]);
        //         if(st.find(sum) != st.end()){
        //             vector<int>temp = {a[i] , a[j] , sum };
        //             sort(temp.begin(),temp.end()); // Sort to avoid duplication
        //             hashset.insert(temp);
        //         }else{
        //             st.insert(a[j]);
        //         }
        //     }
        // }
        // vector<vector<int>> ans (hashset.begin(),hashset.end());
        // return ans;

        // Sorting solution
        int i = 0 , j  , n = a.size(), k ;
        vector<vector<int>> ans;
        sort(a.begin(),a.end());
        while(i < n-2){
             
            j = i+1;
            k = n-1;
            while(j < k){
                int sum = a[i] + a[j] + a[k] ;
                if(sum == 0){
                    ans.push_back({a[i] , a[j] , a[k] });
                    j++;
                    k--;
                    while( j <=k && a[j-1]==a[j]){
                        j++;
                    }
                    while( j <=k && a[k+1] == a[k]){
                        k--;
                    }
                }else if(sum > 0){
                    k--;
                }else{
                    j++;
                }
            }
            i++;
             while( i < n && a[i] == a[i-1]  ){
                    i++;
                }
        }
        return ans;
    }
};