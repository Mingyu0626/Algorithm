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
    int dfs(TreeNode* node, string cur) {
        cur += node->val + '0';
        if (node->left == nullptr && node->right == nullptr) {
            return calculate(cur);
        }
        
        int sum = 0;
        sum += (node->left != nullptr) ? dfs(node->left, cur) : 0;
        sum += (node->right != nullptr) ? dfs(node->right, cur) : 0;
        return sum;
    }

    int calculate(const string& binary) {
        int value = 0, binaryLength = binary.length();
        for (int i = 1; i <= binaryLength; ++i) {
            value += (binary[i - 1] == '1') ? pow(2, binaryLength - i) : 0;
        }
        return value;
    }

    int sumRootToLeaf(TreeNode* root) {
        string binary;
        return dfs(root, binary);
    }
};