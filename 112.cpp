//Path sum
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 注意sum可以为负值，空树时永远返回false；深度优先搜索
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        if(root->val == sum)
            if(root->left == NULL && root->right == NULL)
                return true;
        bool l = false;
        if(root->left != NULL)
            l = hasPathSum(root->left, sum - root->val);
        if(l) return true;
        if(root->right != NULL) 
         return hasPathSum(root->right, sum - root->val);
        return false;
    }
};