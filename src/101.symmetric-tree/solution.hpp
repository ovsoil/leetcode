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
    bool symmetric(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && symmetric(p->left, q->right) && symmetric(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return symmetric(root->left, root->right);
    }
};
