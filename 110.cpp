//Balanced Binary Tree
//凭直觉做的，思路还不是很清晰，有点绕
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
    bool height(TreeNode *node, int &h) {
        if(node == NULL)
        {
            h = -1;
            return true;
        }
        int l, r;
        bool lb = height(node->left, l);
        if (!lb) return false;
        bool rb = height(node->right, r);
        if (!rb) return false;
        h = max(l, r) + 1;
        if (abs(l - r) > 1)
            return false;
        else
            return true;
    }
    bool isBalanced(TreeNode* root) {
        int h;
        return height(root, h);
    }
};
