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
    vector<int> rightSideView(TreeNode* root) {
       vector<int>ans;
       queue<TreeNode*>q;
       q.push(root);
       if(root==NULL) return ans;
       while(!q.empty()){
           int size=q.size();
           if(size==0) return ans;
           int data=0;
           while(size>0){
               TreeNode* temp=q.front();
               q.pop();
               data=temp->val;
               if(temp->left!=NULL)
               q.push(temp->left);
               if(temp->right!=NULL)
               q.push(temp->right);
               size--;
           }
           ans.push_back(data);
       } 
       return ans;
    }
};


/*vector<int> leftView(Node *root)
{
   // Your code here
 
    vector<int> ans;
  
    
    queue<Node*> q;
    q.push(root);
      if (root == NULL) return ans;

    while (!q.empty()) {
        int size = q.size();
        if(size==0) return ans;
        int dat = 0;
        
        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();
            
           
            if (i == 0) {
                dat = temp->data;
            }

            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }

        ans.push_back(dat);
    }

    return ans;
}
*/