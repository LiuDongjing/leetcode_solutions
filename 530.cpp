//contest21_p1
//Minimum Absolute Difference in BST
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
private:
	void deep(TreeNode* root, vector<int> &val) {
		if (root != NULL) {
			val.push_back(root->val);
			deep(root->left, val);
			deep(root->right, val);
		}
	}
public:
	int getMinimumDifference(TreeNode* root) {
		vector<int> val;
		deep(root, val);
		int minv = -1;
		for (int i = 0; i < val.size(); i++) {
			for (int j = i + 1; j < val.size(); j++) {
				int tmp = abs(val[i] - val[j]);
				if (minv < 0 || tmp < minv) minv = tmp;
			}
		}
		return minv;
	}
};