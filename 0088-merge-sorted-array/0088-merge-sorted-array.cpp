class Solution {
public:
vector<int>res;

    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        
        // int i=0,j=0,k=n;
        // while( i<m && j<n )
        // {
        //     if(num1[i]<num2[j])
        //     {
        //         res.push_back(num1[i++]);
        //     }
        //      else
        //     {
        //         res.push_back(num2[j++]);
        //     }
        // }
        // while(i<m)
        // {
        //         res.push_back(num1[i++]);
                
        // }
        // while(j<n)
        // {
        //     res.push_back(num2[j++]);
        // }
        // for(int i=0;i<res.size();i++)
        // {
        //     num1[i]=res[i];
        // }

        // Most optimal approach

        int i = m - 1 , j = n - 1 , k = m + n - 1;
        while(i >= 0 && j >= 0){
            if(a[i] > b[j]){
                a[k] = a[i];
                i--; k--;
            }else{
                a[k] = b[j];
                j--;k--;
            }
        }
        while(i>=0){
            a[k] = a[i];
            i--; k--;
        }
        while(j >=0 ){
            a[k] = b[j];
            j--;k--;
        }
    }
};