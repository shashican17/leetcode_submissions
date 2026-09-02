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
    void help(TreeNode* root, int maxi, int &count){
        if(!root){
            return;
        }

        if(root->val >= maxi){
            maxi = root->val;
            count++;
        }
        help(root->left, maxi, count);
        help(root->right, maxi, count);
    }
public:
    int goodNodes(TreeNode* root) {
        int maxi = INT_MIN;
        int count = 0;
        help(root, maxi, count);
        return count;
    }
};