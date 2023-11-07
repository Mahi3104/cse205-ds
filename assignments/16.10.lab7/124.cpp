/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
       int ms=INT_MIN;
       c(root,ms); 
       return ms;
    }
    int c(TreeNode* root,int &ms){
        if(root==NULL) return 0;
        int lm=max(0,c(root->left,ms));
        int rm=max(0,c(root->right,ms));
        int ns=root->val+lm+rm;
        ms=max(ms,ns);
        return root->val+max(lm,rm);

    }
};