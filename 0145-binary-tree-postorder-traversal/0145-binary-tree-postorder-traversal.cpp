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
    void postorder(TreeNode* root, vector<int>& v) {
        if (root == NULL)
            return;

        postorder(root->left, v);   // Left
        postorder(root->right, v);  // Right
        v.push_back(root->val);     // Root
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;

        postorder(root, v);

        return v;
    }
};