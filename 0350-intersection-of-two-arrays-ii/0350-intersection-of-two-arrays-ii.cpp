// class Solution {
// public:
//     vector<int> intersect(vector<int>& a, vector<int>& b) {
//         vector<int> res;
//         int i , j , m = a.size() , n = b.size();
//         for(i=0; i < m ;i++ ){
//             for(j=0;j<n;j++){
//                 if(a[i]==b[j]){
//                     res.push_back(a[i]);
//                     b[j] = -1; //  SO that it doesnt repeat again
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        vector<int> result;

        for (int num : nums1) {
            freq[num]++;
        }

        for (int num : nums2) {
            if (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }

        return result;
    }
};
