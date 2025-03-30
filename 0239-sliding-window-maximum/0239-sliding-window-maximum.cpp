class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        // TLE 
        // int i = 0 , maxi = INT_MIN , n = a.size() , windowSize = k;
        // while(k-- && i < n ){
        //     maxi = max(maxi , a[i]);
        //     i++;
        // }
        // if(i==n){
        //     return {maxi};
        // }
        // vector<int> v;
        // v.push_back(maxi);
        // for(i = 1 ; i + windowSize -1 < n ; i++){
        //     maxi = INT_MIN;
        //     for(int j = i ; j < i + windowSize ; j++){
        //         maxi = max(maxi , a[j]);
        //     }
        //     v.push_back(maxi);
        // }
        // return v;
        int i = 0 , maxi = INT_MIN , n = a.size() , windowSize = k;
        priority_queue<pair<int,int>> pq;
        vector<int> v;
        for( i=0 ; i < n ; i++ ){
            pq.push({a[i] , i}); // value , index
            
            while(!pq.empty() && pq.top().second < i - windowSize + 1 ){
                // cout << "i : " << i << " " ;
                cout << pq.top().first << " ";
                pq.pop();
                cout << pq.top().first << " ";
            }
            if(i >= windowSize - 1 ){
                v.push_back(pq.top().first);
            }
        }
        return v;
    }
};