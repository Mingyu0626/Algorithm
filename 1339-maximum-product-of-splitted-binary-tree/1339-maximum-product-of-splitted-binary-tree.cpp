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
    const int MOD = 1000000007;
    int maxProduct(TreeNode* root) {
        int sum = getSum(root);
        long long result = 0;
        dfs(root, sum, result);
        return result % MOD;
    }

    int getSum(TreeNode* cur) {
        if (cur == nullptr) {
            return 0;
        }
        return cur->val + getSum(cur->left) + getSum(cur->right);
    }

    long long dfs(TreeNode* cur, const int& sum, long long& maxProduct) {
        if (cur == nullptr) {
            return 0;
        }
        long long subTreeSum = cur->val + 
        dfs(cur->left, sum, maxProduct) + 
        dfs(cur->right, sum, maxProduct);

        maxProduct = max(maxProduct, (sum - subTreeSum) * subTreeSum);
        return subTreeSum;
    }
};