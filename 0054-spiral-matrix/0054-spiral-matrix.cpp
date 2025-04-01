class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        // int n = a.size();
        // int m = a[0].size();
        // vector<int> v;
        // int count = 0;
        
        // // Continue while there is a layer to process.
        // while(count * 2 < n && count * 2 < m) {
        //     // Traverse Right (Top Row)
        //     int row = count;
        //     for (int j = count; j < m - count; j++) {
        //         v.push_back(a[row][j]);
        //     }
            
        //     // Traverse Down (Right Column)
        //     int col = m - count - 1;
        //     for (int i = count + 1; i < n - count; i++) {
        //         v.push_back(a[i][col]);
        //     }
            
        //     // Traverse Left (Bottom Row) only if there's more than one row in the current layer
        //     if (n - count - 1 > count) {
        //         row = n - count - 1;
        //         for (int j = m - count - 2; j >= count; j--) {
        //             v.push_back(a[row][j]);
        //         }
        //     }
            
        //     // Traverse Up (Left Column) only if there's more than one column in the current layer
        //     if (m - count - 1 > count) {
        //         col = count;
        //         for (int i = n - count - 2; i > count; i--) {
        //             v.push_back(a[i][col]);
        //         }
        //     }     
        //     count++;
        // }
        // return v;

        //Clean code 
        int n = a.size();
        int m = a[0].size();
        vector<int> v;
        int count = 0;
        int left = 0 , right = m - 1 , top = 0 , bottom = n - 1 , i , j ;
        while(left <= right && top <= bottom ){
            // Left to right thus top is constant 
            for(j = left ; j <= right ; j++){
                v.push_back(a[top][j]);
            }
            top++;
            // Top to bottom Thus right is constant
            for(i = top  ; i <= bottom ; i++){
                v.push_back(a[i][right]);
            }
            right--;
            // Right to left thus bottom is constant
            if(top <= bottom){
                for(j = right ; j >= left ; j--){
                    cout << a[bottom][j];
                    v.push_back(a[bottom][j]);
                }  
                bottom--; 
            }
            // Bottom to top thus left is constant
            if(left <= right){
                for(i = bottom  ; i >= top ; i--){
                v.push_back(a[i][left]);
                }
                left++;
            }
            
        }
        return v;
    }
};
