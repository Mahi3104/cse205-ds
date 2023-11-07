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
void Preorder(vector<int>&ansp,TreeNode*root){
    if(root!=NULL){
        ansp.push_back(root->val);
        Preorder(ansp,root->left);
        Preorder(ansp,root->right);
    }
    else
    ansp.push_back(0);
}
void Preorder1(vector<int>&ansq,TreeNode*root){
    if(root!=NULL){
        ansq.push_back(root->val);
        Preorder(ansq,root->left);
        Preorder(ansq,root->right);
    }
      else
    ansq.push_back(0);
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
    vector<int>ansp,ansq;
    Preorder(ansp,p);
     Preorder1(ansq,q);
       if(ansp!=ansq)
       return false;
       return true;
    }
};