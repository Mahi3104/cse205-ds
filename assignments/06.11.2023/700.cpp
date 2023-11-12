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
TreeNode*temp;
void preorder(TreeNode* root,int val){
    if(root!=NULL){
        if(root->val==val){
           temp=root;
            
            return;
        }
        else if(val<root->val)
         preorder(root->left,val);
         else if(val>root->val)
            preorder(root->right,val);

        
    }
}
    TreeNode* searchBST(TreeNode* root, int val) {
        
       preorder(root,val);

        return temp;
    }
};