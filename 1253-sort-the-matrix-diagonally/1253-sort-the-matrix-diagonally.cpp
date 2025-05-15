class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& a) {
         priority_queue<int, vector<int>,greater<int>> pq;
         int i , j , row , col;
         int m = a.size() , n = a[0].size();
         // Take the first row and first col and sort the diagonal elements 
         // First row
         for(j = 0 ; j <n;j++){
            row = 0 , col = j;
            while(row < m && col < n ){
                pq.push(a[row][col]);
                row++;col++;
            }
            row = 0 , col = j;
            while(  !pq.empty()  ){
                a[row][col] = pq.top();
                pq.pop();
                row++;col++;
            }
         }
         for(i = 1 ; i <m;i++){
            row = i , col = 0;
            while(row < m && col < n ){
                pq.push(a[row][col]);
                row++;col++;
            }
            row = i , col = 0;
            while( !pq.empty()  ){
                a[row][col] = pq.top();
                pq.pop();
                row++;col++;
            }
         }
         return a;
    }
};