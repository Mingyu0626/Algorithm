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
    int maxLevelSum(TreeNode* root) {
        vector<int> sumList;
        calculate(sumList, root, 1);
        return max_element(sumList.begin(), sumList.end()) - sumList.begin() + 1;
    }

    void calculate(vector<int>& sumList, TreeNode* cur, int curLevel) {
        if (sumList.size() < curLevel) {
            sumList.emplace_back(0);
        }
        sumList[curLevel - 1] += cur->val;
        if (cur->left != nullptr) {
            calculate(sumList, cur->left, curLevel + 1);
        }
        if (cur->right != nullptr) {
            calculate(sumList, cur->right, curLevel + 1);
        }
    }
};