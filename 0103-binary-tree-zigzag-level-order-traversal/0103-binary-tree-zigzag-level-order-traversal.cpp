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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                q.pop();
                level.push_back(node->val);
                // if(flag){
                //     level.push_back(node->val);                    
                // }else{
                //     level.insert(level.begin(), node->val);
                // }
            }
            if(!flag){
                reverse(level.begin(), level.end());
            }
            res.push_back(level);
            flag = !flag;
        }
        return res;
    }

    void help(TreeNode* root, bool flag, vector<vector<int>> &res){
        if(!root){
            return;
        }
        vector<int> level;
        if(flag){
            
        }
    }
};