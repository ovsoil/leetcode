/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    vector<int> data;
    int index;

    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        traverse(root->left);
        data.push_back(root->val);
        traverse(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
         traverse(root);
         index = -1;
    }
    
    /** @return the next smallest number */
    int next() {
        return data[++index];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index + 1 < data.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
