//376
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
         if(nums.size() < 2) return nums.size();
         if(nums.size() == 2) return 1+(nums[0] != nums[1]);
         vector<int> tmp;
         tmp.push_back(nums[0]);
         for(int i = 1;i < nums.size();i++)
            if(nums[i] != nums[i-1]) tmp.push_back(nums[i]);
         if(tmp.size() < 3) return tmp.size();
         int cnt = 0;
         for(int i = 1; i < nums.size()-1;i++) {
             int dl = nums[i] - nums[i-1];
             int dr = nums[i+1] - nums[i];
             if(dl*dr < 0) cnt++;
         }
         if(cnt == 0) return 1+(tmp.front() != tmp.back());
         return cnt+2;
    }
};