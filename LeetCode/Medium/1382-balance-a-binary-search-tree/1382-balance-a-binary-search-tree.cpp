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
    vector<int> v;
public:
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        return generateBalancedBST(0, v.size() - 1);
    }

    void inOrder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inOrder(node->left);
        v.emplace_back(node->val);
        inOrder(node->right);
    }

    TreeNode* generateBalancedBST(int l, int r) {
        int m = (r - l) / 2 + l;
        TreeNode* leftNode = (l <= m - 1) ? generateBalancedBST(l, m - 1) : nullptr;
        TreeNode* rightNode = (m + 1 <= r) ? generateBalancedBST(m + 1, r) : nullptr;
        return new TreeNode(v[m], leftNode, rightNode);
    }
};