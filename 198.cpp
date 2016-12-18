//House Robber
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() < 3)
            return *max_element(nums.begin(), nums.end());
        for(int i = 2; i < nums.size();i++) {
            int dm = nums[i - 1];
            for(int j = i - 2;j >= 0;j--) {
                dm = max(dm, nums[j] + nums[i]);
            }
            nums[i] = dm;
        }
        return nums.back();
    }
};
