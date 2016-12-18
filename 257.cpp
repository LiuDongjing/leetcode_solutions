//Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(root == NULL) 
            return ret;
        stringstream cvt;
        cvt << root->val;
        string s = cvt.str();
        if(root->left == NULL && root->right == NULL) {
            ret.push_back(s);
            return ret;
        }
        auto ls = binaryTreePaths(root->left);
        auto rs = binaryTreePaths(root->right);
        for(auto &e : ls){
            e = s + "->" + e;
        }
        for(auto &e : rs){
            e = s + "->" + e;
        }
        ret.insert(ret.end(), ls.begin(), ls.end());
        ret.insert(ret.end(), rs.begin(), rs.end());
        return ret;
    }
};
