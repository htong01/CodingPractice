// inorder traverse
class Solution {
public:
    int res = INT_MAX;
    int prev = NULL;
    
    int minDiffInBST(TreeNode* root) {
        if(root==NULL) return res;

        minDiffInBST(root->left);
        if(prev!=NULL) res = min(res,root->val - prev);
        prev = root->val;
        minDiffInBST(root->right);
        return res;
    }
};
