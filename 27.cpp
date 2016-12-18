//Remove Element
/*注意下面两个特殊情况
[3,3]
5
[1]
1
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        int i = 0, j = nums.size() - 1;
        while(i <= j) {
            for(;i < nums.size() && nums[i] != val;i++);
            for(;j >= 0 && nums[j] == val;cnt++,j--);
            if(i < j) {
                nums[i] = nums[j];
                i++;
                j--;
                cnt++;
            }
        }
        nums.resize(nums.size() - cnt);
        return nums.size();
    }
};
