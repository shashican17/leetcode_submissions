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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        help(root, res);
        return res;
    }

    int help(TreeNode* root, int& res){
        if(!root){
            return 0;
        }

        int leftSum = max(0, help(root->left, res));
        int rightSum = max(0, help(root->right, res));
        res = max(res, leftSum + rightSum + root->val);
        return root->val + max(leftSum , rightSum);
    }
};