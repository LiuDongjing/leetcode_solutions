//Remove Duplicates from Sorted Array
/*
第一个可行，但是超时了
第二个可行，要简单得多
*/
/*
class Solution {
public:
int removeDuplicates(vector<int>& nums) {
	if (nums.size() <= 1)
		return nums.size();
	int cnt = 0;
	int s = nums.size() - 1, e = nums.size() - 1;
	int x = nums.back();
	for (int i = nums.size() - 2; i >= 0; i--) {
		if (nums[i] != x && s - i > 1) {
			int k = s, n = e;
			cnt += (s - i - 1);
			e -= (s - i - 1);
			s -= (s - i);
			for (int j = i + 1; k <= n; j++, k++) {
				nums[j] = nums[k];
			}
			x = nums[i];
		}
		else if (nums[i] != x && s - i == 1) {
			x = nums[i];
			s--;
		}
	}
	if (s > 0) {
		int k = s, n = e;
		cnt += s;
		for (int j = 0; k <= n; j++, k++) {
			nums[j] = nums[k];
		}
	}
	return nums.size() - cnt;
}
};*/

class Solution {
public:
int removeDuplicates(vector<int>& nums) {
	if(nums.size() < 1)
	    return 0;
	int last = 0, pre = nums[0] - 1;
    for(int i = 0; i < nums.size();i++) {
        if(nums[i] != pre){
            nums[last++] = nums[i];
            pre = nums[i];
        }
    }
    return last;
}
};
