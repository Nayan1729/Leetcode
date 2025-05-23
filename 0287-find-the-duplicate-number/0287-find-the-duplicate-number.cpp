class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // This is a linked list cycle detection problem
        int slow = 0 , fast = 0 , slow2  = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                break;
            }
        }
        while(true){
            slow = nums[slow];
            slow2 = nums[slow2];
            if(slow == slow2){
                return slow;
            }
        }
        return slow;
    }
};