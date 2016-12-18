//Symmetric Tree
//结构上对称，数值上也要对称
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
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        return isSame(root->left, root->right);
    }
    bool isSame(TreeNode* t0, TreeNode* t1) {
        if(t0 == NULL && t1 == NULL) {
            return true;
        }else if(t0 == NULL || t1 == NULL) {
            return false;
        }
        if(t0->val != t1->val) {
            return false;
        }
        if(isSame(t0->left, t1->right) && isSame(t0->right, t1->left)) {
            return true;
        }
        else {
            return false;
        }
    }
};
