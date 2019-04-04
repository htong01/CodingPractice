DFS

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        dfs(root, sum);
        return sum;
    }
    int dfs(TreeNode* root, int &sum){
        if(!root) return 0;
        int l = max(0, dfs(root->left, sum));
        int r = max(0, dfs(root->right, sum));
        sum = max(sum, l+r+root->val);
        return root->val + max(l,r);            // 最后的return为什么不是return sum？
    }
};
