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
 // ע��sum����Ϊ��ֵ������ʱ��Զ����false�������������
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