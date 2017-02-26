//contest21_p2
//Continuous Subarray Sum
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(k < 0) k = -k;
        for(int i = 1; i < nums.size();i++)
            nums[i] += nums[i-1];
        for(int i = 1; i < nums.size();i++) {
            if((k == 0 && nums[i] == 0) || (k > 0 && nums[i] % k == 0)) return true;
            for(int j = 0; j <= i - 2; j++) {
                int tmp = nums[i] - nums[j];
                if((k == 0 && tmp == 0) || (k > 0 && tmp % k == 0)) return true;
            }
        }
        return false;
    }
};