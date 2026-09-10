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

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* curr = s.top();
            s.pop();
            
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
            
            if(curr->left != NULL){
                s.push(curr->left);
            }
            if(curr->right != NULL){
                s.push(curr->right);
            }
        }
        
        return root; 
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
