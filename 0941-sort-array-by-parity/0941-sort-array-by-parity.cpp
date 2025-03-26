class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // int n = nums.size() , i, j=0;
        // vector<int>  a;
        // for(i=0 ; i<n ; i++){
        //     if(nums[i]%2 == 0){
        //         a.push_back(nums[i]);
        //     }
        // }
        // for(i=0 ; i<n ; i++){
        //     if(nums[i]%2 == 1){
        //         a.push_back(nums[i]);
        //     }
        // }
        // return a;
        int n = nums.size();
        int i = 0, j = n-1 ,evenIndex = 0 , oddIndex = n-1;
        vector<int> a(n,0);
        while(i!=n){
            if(nums[i] % 2 == 0 ){ // even Condition
                a[evenIndex] = nums[i];
                evenIndex++;
            }
            if(nums[j] % 2 == 1 ){ // Odd condition
                a[oddIndex] = nums[j];
                oddIndex--;
            }
            i++;
            j--;
        }
        return a;
    }
};