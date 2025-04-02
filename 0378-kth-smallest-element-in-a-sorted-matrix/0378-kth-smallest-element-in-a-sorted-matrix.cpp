class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int i , j , n = a.size();
        priority_queue<int>pq; // Max heap
        for(i = 0 ; i < n ; i++){
            for(j = 0 ; j< n ; j++){
                pq.push(a[i][j]);
                if(pq.size() > k ){
                    // Pop the topmost as it is greater than the kth smallest
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};