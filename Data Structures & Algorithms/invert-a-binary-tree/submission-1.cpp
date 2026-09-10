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
            
            // 1. Physically swap the left and right pointers of the current node
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
            
            // 2. Push the children onto the stack so they get inverted later
            // (It doesn't matter which order you push them for this problem!)
            if(curr->left != NULL){
                s.push(curr->left);
            }
            if(curr->right != NULL){
                s.push(curr->right);
            }
        }
        
        // 3. Return the original root. The entire tree underneath it is now swapped.
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
