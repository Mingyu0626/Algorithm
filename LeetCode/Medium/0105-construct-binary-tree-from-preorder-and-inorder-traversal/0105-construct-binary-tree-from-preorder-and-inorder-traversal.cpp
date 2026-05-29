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
private:
    unordered_map<int, int> um;
    vector<int> pre, in;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder, in = inorder;
        for (int i = 0; i < inorder.size(); ++i) {
            um[inorder[i]] = i;
        }
        return build(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode* build(int preStart, int preEnd, int inStart, int inEnd) {
        if (preEnd < preStart || inEnd < inStart) {
            return nullptr;
        }

        int rootVal = pre[preStart];
        int leftSubTreeSize = um[rootVal] - inStart;
        TreeNode* root = new TreeNode(rootVal);

        root->left = build(preStart + 1, preStart + leftSubTreeSize, inStart, um[rootVal] - 1);
        root->right = build(preStart + leftSubTreeSize + 1, preEnd, um[rootVal] + 1, inEnd);
        return root;
    }
};