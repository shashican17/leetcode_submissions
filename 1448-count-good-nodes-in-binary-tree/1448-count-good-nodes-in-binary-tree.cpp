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
    void help(TreeNode* root, int& count, int maxVal){
        if(!root){
            return;
        }

        if(root->val >= maxVal){
            count++;
            maxVal = root->val;
        }
        help(root->left, count, maxVal);
        help(root->right, count, maxVal);
    }
public:
    int goodNodes(TreeNode* root) {
        int maxVal = INT_MIN;
        int count = 0;
        help(root, count, maxVal);
        return count;
    }
};