class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        int i , a, b ,n = nums.size() ;
        for(i = 0 ; i < n ; i++){
            a = abs(nums[i]) ; b = nums[ a - 1];
            cout << b;
            if( b < 0 ){
                
                v.push_back(a);
            }else{
                nums[a - 1] = - b;
            }
        }
        return v;
    }
};