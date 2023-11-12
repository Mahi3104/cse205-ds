class Solution {
public:
    void preorder(TreeNode* root, long long lower, long long upper, bool &ans) {
        if (root != nullptr) {
            if (root->val <= lower || root->val >= upper) {
                ans = false;
                return;
            }
            preorder(root->left, lower, root->val, ans);
            preorder(root->right, root->val, upper, ans);
        }
    }

    bool isValidBST(TreeNode* root) {
        bool ans = true;
        preorder(root, LLONG_MIN, LLONG_MAX, ans);
        return ans;
    }
};
