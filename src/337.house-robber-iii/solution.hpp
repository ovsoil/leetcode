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
    pair<int, int> robIn(TreeNode* root) {
        if (root == nullptr) return make_pair(0, 0);
        pair<int, int> left = robIn(root->left);
        pair<int, int> right = robIn(root->right);
        // 不偷root
        int fir = max(left.first, left.second) + max(right.first, right.second);
        // 偷root
        int sec = root->val + left.first + right.first;
        return make_pair(fir, sec);
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> ret = robIn(root);
        return max(ret.first, ret.second);
    }
};
