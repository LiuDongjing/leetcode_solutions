//53
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastj = nums.size() - 1;
        while(lastj > 0) {
            bool flag = true;
            for(int j = lastj-1; j >= 0; j--){
                if(lastj - j <= nums[j]) {
                    lastj = j;
                    flag = false;
                    break;
                }
            }
            if(flag) break;
        }
        return lastj == 0;
    }
};