/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        queue<TreeNode*> q;
        if(root){
            q.push(root);
        }
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node){
                str += to_string(node->val);
                q.push(node->left);
                q.push(node->right);
            }else{
                str += "NULL";
            }
            if(!q.empty()){
                str += ",";
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return NULL;
        }
        vector<string> vals = split(data, ',');
        if(vals.empty() || vals[0] == "NULL"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(!q.empty() && i < vals.size()){
            TreeNode* node = q.front();
            q.pop();
            if(vals[i] != "NULL"){
                node->left = new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }
            i++;
            if(i < vals.size() && vals[i] != "NULL"){
                node->right = new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
    vector<string> split(string& str, char delim){
        vector<string> res;
        stringstream ss(str);
        string item;
        while(getline(ss, item, delim)){
            res.push_back(item);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));