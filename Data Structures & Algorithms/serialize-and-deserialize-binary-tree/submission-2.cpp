/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    void shelper(TreeNode* root, string& ans) {

        if(root == NULL) {
            ans += "NULL,";
            return;
        }

        ans += to_string(root->val);
        ans += ",";

        shelper(root->left, ans);
        shelper(root->right, ans);
    }

    string serialize(TreeNode* root) {

        string ans = "";

        shelper(root, ans);

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* dhelper(string& data, int& idx) {

        string temp = "";

        while(data[idx] != ',') {
            temp += data[idx];
            idx++;
        }

        idx++;

        if(temp == "NULL")
            return NULL;

        TreeNode* currRoot = new TreeNode(stoi(temp));

        currRoot->left = dhelper(data, idx);
        currRoot->right = dhelper(data, idx);

        return currRoot;
    }

    TreeNode* deserialize(string data) {

        int idx = 0;

        return dhelper(data, idx);
    }
};