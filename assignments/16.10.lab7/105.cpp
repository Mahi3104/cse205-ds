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
int pre=0;
TreeNode* build(vector<int>& preorder, vector<int>& inorder,int is,int ie){
    if(is>ie) return NULL;
    TreeNode* temp=new TreeNode(preorder[pre]);
    pre++;
    int in;
    for(int i=is;i<=ie;i++){
        if(inorder[i]==temp->val){
            in=i;
            break;
        }
    }
    temp->left=build(preorder,inorder,is,in-1);
    temp->right=build(preorder,inorder,in+1,ie);
    return temp;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode*ans=build(preorder,inorder,0,inorder.size()-1);
        return ans;
    }
};