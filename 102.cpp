//Binary Tree Level Order Traversal
//宽度优先搜索
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode *, int>> que;
        vector<vector<int>> ret;
        if (root == NULL) 
            return ret;
        int level = 0;
        ret.push_back(vector<int>());
        que.push(pair<TreeNode*, int>(root,0));
        while(!que.empty()) {
            auto p = que.front();
            if(p.second != level){
                level ++;
                ret.push_back(vector<int>());
            }
            ret[level].push_back(p.first->val);
            if(p.first->left != NULL) 
                que.push(pair<TreeNode*, int>(p.first->left, level+1));
            if(p.first->right != NULL) 
                que.push(pair<TreeNode*, int>(p.first->right, level+1));
            que.pop();
        }
        return ret;
    }
};
