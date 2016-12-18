//Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        queue<pair<TreeNode*,int>> que;
        vector<vector<int>> ret;
        if(root == NULL)
            return ret;
        que.push(make_pair(root,0));
        while(!que.empty()) {
            auto e = que.front();
            if(e.first->left != NULL)
                que.push(make_pair(e.first->left, e.second+1));
            if(e.first->right != NULL)
                que.push(make_pair(e.first->right, e.second+1));
            if(e.second >= ret.size())
                ret.push_back(vector<int>());
            ret[e.second].push_back((e.first)->val);
            que.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
