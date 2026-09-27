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
    void levelOrderTraversal(TreeNode* root, vector<int>& res){
        queue<TreeNode*> q;
        if(!root){
            return;
        }
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int val = 0;
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                val = curr->val;
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            res.push_back(val);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        levelOrderTraversal(root, res);
        return res;
    }
};