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

using pib = pair<int, bool>; 

public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        pib l = dfs(root->left, 0), r = dfs(root->right, 0);
        return abs(l.first - r.first) <= 1 && l.second && r.second;
    }

    pair<int, bool> dfs(TreeNode* curNode, int curDepth) {
        if (curNode == nullptr) {
            return {curDepth, true};
        }
        pib l = dfs(curNode->left, curDepth + 1), r = dfs(curNode->right, curDepth + 1);
        return {max(l.first, r.first), abs(l.first - r.first) <= 1 && l.second && r.second};
    }
};