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

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int leftSize = inRoot - inStart;   
        root->left = build(preorder, preStart + 1, preStart + leftSize,
                           inStart, inRoot - 1);
        root->right = build(preorder, preStart + leftSize + 1, preEnd,
                            inRoot + 1, inEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1,
                     0, inorder.size() - 1);
    }
};