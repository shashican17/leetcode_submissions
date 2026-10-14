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
    bool help(TreeNode* root, int targetSum, int currSum){
        if(!root){
            return false;
        }
        currSum += root->val;
        if(!root->left && !root->right){
            return currSum == targetSum;
        }
        return help(root->left, targetSum, currSum) || help(root->right, targetSum, currSum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return help(root, targetSum, 0);
    }
};