//LCA
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct PathNode {
   int mark;
   TreeNode *data;
   PathNode(TreeNode *t):mark(0){
       data = t;
   }
 };
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        static vector<PathNode> paths;
        if(root == NULL) {
            return NULL;
        }
        paths.push_back(PathNode(root));
        TreeNode *ret = NULL;
        if(root == p || root == q) {
            for(auto i = paths.rbegin(); i < paths.rend(); i++) {
                i->mark++;
                if(i->mark == 2) {
                    ret = i->data;
                    break;
                }
            }
        }
        TreeNode *tmp0 = lowestCommonAncestor(root->left, p, q);
        TreeNode *tmp1 = lowestCommonAncestor(root->right, p, q);
        if(tmp0 != NULL) {
            ret = tmp0;
        }
        if(tmp1 != NULL) {
            ret = tmp1;
        }
        paths.pop_back();
        return ret;
    }
};
