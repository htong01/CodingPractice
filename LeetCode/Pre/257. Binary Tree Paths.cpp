DFS recursion

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL) return res;
        dfs(root, res, to_string(root->val));
        return res;
    }
    void dfs(TreeNode *root, vector<string>& res, string val){
        if(root->left==NULL && root->right==NULL){
            res.push_back(val);
            return;
        }
        if(root->left) dfs(root->left, res, val+"->"+ to_string(root->left->val));
        if(root->right) dfs(root->right, res, val+"->"+ to_string(root->right->val));
    }
};
