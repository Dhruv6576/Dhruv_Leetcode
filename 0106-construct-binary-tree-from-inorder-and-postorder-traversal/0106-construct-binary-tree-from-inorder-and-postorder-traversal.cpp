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
    unordered_map<int, int> inMap;   

    TreeNode* build(vector<int>& postorder, int postStart, int postEnd,
                    int inStart, int inEnd) {
        if (postStart > postEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int leftSize = inRoot - inStart;  
        root->left = build(postorder, postStart, postStart + leftSize - 1,
                           inStart, inRoot - 1);
        root->right = build(postorder, postStart + leftSize, postEnd - 1,
                            inRoot + 1, inEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < (int)inorder.size(); i++) inMap[inorder[i]] = i;
        return build(postorder, 0, (int)postorder.size() - 1,
                     0, (int)inorder.size() - 1);
    }
};